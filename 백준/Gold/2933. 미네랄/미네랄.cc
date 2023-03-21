#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
struct coord { int y, x; };

int visited[100][100];
int R, C;
int ydir[] = {-1,1,0,0};
int xdir[] = {0,0,-1,1};
char MAP[100][100];

void drop(vector<coord>v) {
	int base = 21e8;
	int cursize = v.size();

	for (int cur = 0; cur < cursize; cur++) {
		coord now = v[cur];
		MAP[now.y][now.x] = '.';
	}
	for (int cur = 0; cur < cursize; cur++) {
		coord now = v[cur];
		for (int i = now.y + 1; i < R; i++) {
			if (MAP[i][now.x] == 'x') {
				base = min(base, i - now.y - 1);
				break;
			}
			else if (i == R - 1 && MAP[i][now.x] == '.') 
				base = min(base, i - now.y);
		}
	}
	for (int i = 0; i <cursize; i++)
		MAP[v[i].y + base][v[i].x] = 'x';

}

void checkCluster(int sy, int sx) {
	for (int dir = 0; dir < 4; dir++) {
		int nny = sy + ydir[dir];
		int nnx = sx + xdir[dir];

		if (nny < 0 || nnx < 0 || nny >= R || nnx >= C)continue;
		if (MAP[nny][nnx] == '.')continue;
		vector<coord> q; q.push_back({ nny,nnx });
		memset(visited, 0, sizeof(visited));
		visited[nny][nnx] = 1;
		int flag = 0;
		int start = 0;
		while (1) {
			int cursize = q.size();
			for (int cur = start; cur < cursize; cur++) {
				coord now = q[cur];
				for (int i = 0; i < 4; i++) {
					int ny = now.y + ydir[i];
					int nx = now.x + xdir[i];
					if (ny < 0 || nx < 0 || ny >= R || nx >= C)continue;
					if (MAP[ny][nx] == '.')continue;
					if (visited[ny][nx] == 1)continue;
					if (ny == R - 1) {
						flag = 1;
						break;
					}
					visited[ny][nx] = 1;
					q.push_back({ ny,nx });
				}
				if (flag == 1)break;
			}

			int cursize2 = q.size();
			if (flag == 1 || cursize == cursize2) break;
			start = cursize;
			}
		
		if (flag == 0) {
			drop(q);
			break;
		}
	}

}

void stick(int row, int idx) {
	if (idx % 2 == 0)
	{
		for (int i = 0; i < C; i++) {
			if (MAP[R-row][i] == 'x') {
				MAP[R-row][i] = '.';
				checkCluster(R - row, i);
				break;
			}
		}
	}
	else
	{
		for (int i = C-1; i >=0; i--) {
			if (MAP[R-row][i] == 'x') {
				MAP[R-row][i] = '.';
				checkCluster(R - row, i);
				break;
			}
		}
	}
}

int main() {
	int n;
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> MAP[i][j];
		}
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		stick(number, i);
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << MAP[i][j];
		}cout << '\n';
	}


}