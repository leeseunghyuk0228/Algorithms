#include <iostream>
#include <queue>
using namespace std;

string MAP[12];
struct coord { int y, x; };
int ydir[] = { -1,1,0,0 };
int xdir[] = { 0,0,-1,1 };
int isbombed,res=0;
char target;

void drop() {
	for (int j = 0; j < 6; j++)
	{
		string temp = "";
		for (int i = 11; i >= 0; i--)
		{
			if (MAP[i][j] != '.')temp += MAP[i][j];
			MAP[i][j] = '.';
		}
		int len = temp.length();
		for (int i = 0; i < len; i++)
			MAP[11 - i][j] = temp[i];
	}
}

void bfs(int sy, int sx) {
	queue<coord> q;
	int visited[12][6] = { 0, };
	visited[sy][sx] = 1;
	q.push({ sy,sx });
	// 현재 좌표에서 터트릴 수 있는 모든 것 담는다
	while (1) {
		int cursize = q.size();
		for (int i = 0; i < cursize; i++) {
			coord now = q.front(); q.pop();
			for (int j = 0; j < 4; j++) {
				int ny = now.y + ydir[j];
				int nx = now.x + xdir[j];
				if (ny < 0 || nx < 0 || ny >= 12 || nx >= 6)continue;
				if (visited[ny][nx] == 1)continue;
				if (MAP[ny][nx] != target) continue;
				visited[ny][nx] = 1;
				q.push({ ny,nx });
			}
			q.push({ now });
		}
		int cur2 = q.size();
		if (cursize == cur2)break;
	}
	// 4개 이상이면 터트리고 중력 작용
	if (q.size() >= 4)
	{
		isbombed = 1;
		while (!q.empty()) {
			coord now = q.front(); q.pop();
			MAP[now.y][now.x] = '.';
		}
	}

}

int main() {
	for (int i = 0; i < 12; i++) cin >> MAP[i];
	int cnt = 0;
	while (1) {
		isbombed = 0;
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (MAP[i][j] != '.') {
					target = MAP[i][j];
					bfs(i, j);
				}
			}
		}
		if (isbombed) {
			drop();
			cnt++;
		}
		if (!isbombed)break;
	}
	cout << cnt;
}