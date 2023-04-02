#include <iostream>
#include <algorithm>
using namespace std;
int N, M,MAP[500][500],res=-21e8;



void solutionC2(int sy, int sx,int level,int sum) {
	if (level == 1) {
		int ydir[][2] = { {-1,0},{-1,0},{0,1},{0,1},{-1,0} };
		int xdir[][2] = { {-1,1},{1,-1},{-1,-1},{1,1},{1,1} };
		for (int i = 0; i < 5; i++) {
			int temp = 0, flag = 1;
			for (int j = 0; j < 2; j++) {
				int ny = sy + ydir[i][j];
				int nx = sx + xdir[i][j];
				if (ny < 0 || nx < 0 || ny >= N || nx >= M)flag = 0;
				temp += MAP[ny][nx];
			}
			if (flag) res = max(res, sum + temp);
		}
		return;
	}
	if (sy+1 >= N)return;
	solutionC2(sy+1,sx, level + 1, sum += MAP[sy+1][sx]);
}

void solutionC3(int sy, int sx, int level, int sum) {
	if (level == 2) {
		int ydir[] = { -2,-1,0,1,0,-1,-2 };
		int xdir[] = { -1,-1,-1,0,1,1,1 };
		for (int i = 0; i < 7; i++) {
			int ny = sy + ydir[i];
			int nx = sx + xdir[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			res = max(res, sum + MAP[ny][nx]);
		}
		return;
	}
	if (sy + 1 >= N)return;
	solutionC3(sy + 1, sx, level + 1, sum += MAP[sy + 1][sx]);
}

void solutionR3(int sy, int sx, int level, int sum) {
	if (level == 2) {
		int ydir[] = { -1,-1,-1,0,1,1,1 };
		int xdir[] = { -2,-1,0,1,0,-1,-2 };
		for (int i = 0; i < 7; i++) {
			int ny = sy + ydir[i];
			int nx = sx + xdir[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			res = max(res, sum + MAP[ny][nx]);
		}
		return;
	}
	if (sx + 1 >= M)return;
	solutionR3(sy, sx+1, level + 1, sum += MAP[sy][sx+1]);
}



int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			solutionC2(i, j,0,MAP[i][j]);
			solutionC3(i, j, 0,MAP[i][j]);
			solutionR3(i, j, 0,MAP[i][j]);
		}
	}
	cout << res;

}