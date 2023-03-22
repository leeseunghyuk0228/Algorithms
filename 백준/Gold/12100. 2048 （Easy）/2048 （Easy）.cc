#include <iostream>
#include <cstring>
using namespace std;
int MAP[20][20];
int N,res=-21e8;
int ydir[] = { -1,1,0,0 };
int xdir[] = { 0,0,-1,1 };
int visited[20][20];
void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> MAP[i][j];
}

void backup(int arr[20][20]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			MAP[i][j] = arr[i][j];
		}
	}
}

void Move(int sy, int sx, int dir) {
	int ny = sy;
	int nx = sx;
	while (1) {
		int nny = ny + ydir[dir];
		int nnx = nx + xdir[dir];
		// 범위 초과
		if (nny < 0 || nnx < 0 || nny >= N || nnx >= N)break;
		// 이미 합쳐진 적 있는 곳
		if (visited[nny][nnx] == 1)break;
		// 같다(합쳐진적 없는것 보장)
		if (MAP[nny][nnx] == MAP[ny][nx]) {
			MAP[nny][nnx] += MAP[ny][nx];
			MAP[ny][nx] = 0;
			visited[nny][nnx] = 1;
			break;
		}
		// 다르다
		else {
			// 0이다
			if (MAP[nny][nnx] == 0) {
				MAP[nny][nnx] = MAP[ny][nx];
				MAP[ny][nx] = 0;
			}
			// 0이 아니다
			else
				break;
		}

		ny = nny;
		nx = nnx;
	}
}

void rotate(int dir) {
	memset(visited, 0, sizeof(visited));
	int istart, iend;
	int jstart, jend;
	if (dir == 0 || dir == 2) {
		if (dir == 0) {
			istart = 1, iend = N;
			jstart = 0, jend = N;
		}
		else {
			istart = 0, iend = N;
			jstart = 1, jend = N;
		}
		for (int i = istart; i < iend; i++) {
			for (int j = jstart; j < jend; j++) {
				if (MAP[i][j] != 0) {
					Move(i, j, dir);
				}
			}
		}
	}
	else {
		if (dir == 3)
		{// 우로 이동할 때 (i=0~N ++ ,j=N-2~0 --)
			for (int i = 0; i < N; i++) {
				for (int j = N - 2; j >= 0; j--) {
					if (MAP[i][j] != 0) {
						Move(i, j,dir);
					}
				}
			}
		}

		if (dir == 1) {
			// 아래 이동할 때 (i= N-2~0 --, j=0~N ++)
			for (int i = N - 2; i >= 0; i--) {
				for (int j = 0; j < N; j++) {
					if(MAP[i][j] != 0) {
						Move(i, j, dir);
					}
				}
			}
		}
	}
}

void dfs(int level) {
	if (level == 5)
	{
		for (int i = 0; i < N; i ++) 
			for (int j = 0; j < N; j++) 
				if (MAP[i][j] > res)
					res = MAP[i][j];
		return;
	}

	int temp[20][20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = MAP[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		rotate(i);
		dfs(level + 1);
		backup(temp);
	}

}

int main() {
	input();
	dfs(0);
	cout << res;
}