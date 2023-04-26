#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
using namespace std;

int MAP[51][51], CMAP[51][51],TEMP[51][51];
int cross[] = { 2,4,6,8 };
int ydir[] = { 0, 0,-1,-1,-1,0,1,1, 1 };
int xdir[] = { 0,-1,-1, 0, 1,1,1,0,-1 };
int N, M;

void init() {
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &MAP[i][j]);

	CMAP[N - 1][1] = 1;
	CMAP[N - 1][2] = 1;
	CMAP[N ][1] = 1;
	CMAP[N ][2] = 1;
}

void PRINT() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", MAP[i][j]);
		}printf("\n");
	}
}

void CPRINT() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", CMAP[i][j]);
		}printf("\n");
	}
}

void moveCloud(int dir,int s) {
	s %= N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!CMAP[i][j])continue;
			int ny = i + ydir[dir] * s;
			int nx = j + xdir[dir] * s;

			if (ny > N)ny -= N;
			else if (ny < 1)ny += N;

			if (nx > N) nx -= N;
			else if (nx < 1) nx += N;

			TEMP[ny][nx] = 1;
		}
	}

	memcpy(CMAP, TEMP, sizeof(TEMP));
}

void Rain() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (CMAP[i][j])MAP[i][j]++;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!CMAP[i][j])continue;

			for (int k = 0; k < 4; k++) {
				int ny = i + ydir[cross[k]];
				int nx = j + xdir[cross[k]];

				if (ny<1 || nx<1 || ny>N || nx>N)continue;
				if (MAP[ny][nx])	MAP[i][j]++;

			}
		}
	}

}

void NewCloud() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (CMAP[i][j])continue;
			if (MAP[i][j] >= 2) {
				TEMP[i][j] = 1;
				MAP[i][j] -= 2;
			}
		}
	}

	memcpy(CMAP, TEMP, sizeof(TEMP));
}

void func() {
	int dir, s;
	scanf("%d %d", &dir, &s);
	memset(TEMP, 0, sizeof(TEMP));
	moveCloud(dir, s);
	Rain();
	memset(TEMP, 0, sizeof(TEMP));
	NewCloud();
}

int main() {
	init();
	for (int i = 0; i < M; i++) func();
	int res = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			res += MAP[i][j];
	printf("%d",res);

}
