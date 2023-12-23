#include <iostream>
using namespace std;
struct coord { int y, x; };
int ydir[] = { -1,0,1,0 };
int xdir[] = { 0,1,0,-1 };
int MAP[50][50], res = 0;
int N, M, dir, sy, sx;

void input() {
	cin >> N >> M >> sy >> sx >> dir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}
}
// 상 우 하 좌
void bfs(int sy, int sx) {
	while (1) {
		if (MAP[sy][sx] == 0) {
			MAP[sy][sx] = 2; res++;
		}
		int flag = 0;

		for (int i = 0; i < 4; i++) {
			int ny = sy + ydir[i];
			int nx = sx + xdir[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			if (MAP[ny][nx] == 0)flag = 1;
		}

		if (flag == 1) {
			dir--;
			if (dir < 0)dir = 3;
			int ny = sy + ydir[dir];
			int nx = sx + xdir[dir];
			if (ny >= 0 && nx >= 0 && ny < N && nx < M)
			{
				if (MAP[ny][nx] == 0) {
					sy = ny, sx = nx;
				}
			}

		}
		else {
			int ny = sy - ydir[dir];
			int nx = sx - xdir[dir];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)break;
			if (MAP[ny][nx] == 1) break;
			sy = ny, sx = nx;
		}
	}
}

int main() {
	input();
	bfs(sy, sx);
	cout << res;
}