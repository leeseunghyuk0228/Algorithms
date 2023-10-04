#include <iostream>
#include <queue>
using namespace std;
// 섬찾기로 섬찾는다 -> BFS로 만들어놓기
// 섬별 구역 개수/합 구하기 -> B
// 섬 구역 갱신하기
int N, L, R;
int MAP[50][50];
int visited[50][50];
int yeonhap[50][50];
int ydir[] = { -1,1,0,0 };
int xdir[] = { 0,0,-1,1 };
int temp = 1;

void input() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> MAP[i][j];
}

int get_yeonhap(int sy, int sx) {
	queue < pair<int, int>> q;
	q.push({ sy,sx });
	visited[sy][sx] = 1;
	int flag = 0;

	while (!q.empty()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
	
		for (int i = 0; i < 4; i++) {
			int ny = nowy + ydir[i];
			int nx = nowx+xdir[i];
			// 범위
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
			// 방문여부
			if (visited[ny][nx])continue;
			// L<=gap<=R 여부
			int gap = MAP[ny][nx] - MAP[nowy][nowx];
			if (gap < 0)gap *= -1;
			if (gap >= L && gap <= R) {
				visited[ny][nx] = 1;
				yeonhap[ny][nx] = temp;
				yeonhap[nowy][nowx] = temp;
				q.push({ ny,nx });
				flag = 1;
			}
		}
	}

	return flag;
}

void update(int sy, int sx) {
	queue<pair<int, int>>q;
	queue<pair<int, int>>coords;
	q.push({ sy,sx });
	coords.push({ sy,sx });
	int base = yeonhap[sy][sx];
	int SUM = MAP[sy][sx];
	yeonhap[sy][sx] = 0;

	while (!q.empty()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int ny = nowy + ydir[i];
				int nx = nowx + xdir[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
				if (yeonhap[ny][nx] != base)continue;
				yeonhap[ny][nx] = 0;
				SUM += MAP[ny][nx];
				coords.push({ ny,nx });
				q.push({ ny,nx });
			}
		}
	}
	SUM /= coords.size();
	while (!coords.empty()) {
		MAP[coords.front().first][coords.front().second] = SUM;
		coords.pop();
	}
}

int main() {
	input();
	int res = 0;
	while (1)
	{
		int is_yeonhap = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == 0)
				{
					if (get_yeonhap(i, j)) {
						is_yeonhap = 1;
						temp++;
					}
				}
			}
		}
		if (!is_yeonhap)break;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = 0;
				if (yeonhap[i][j])update(i, j);
			}
		}
		res++;
	}
	cout << res;

}