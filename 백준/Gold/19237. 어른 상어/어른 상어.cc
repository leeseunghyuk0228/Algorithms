#include <iostream>
using namespace std;
struct smell { int sharknum, count; };
struct shark { int y, x, isAlive, dir, pdir[5][5]; };
smell SMELL[20][20];
shark sharks[401];

int N, M, k, MAP[20][20],t=0,alive;
int ydir[] = { 0, -1,1,0,0 };
int xdir[] = { 0, 0,0,-1,1 };

void input() {
	cin >> N >> M >> k;
	alive = M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j]) {
				sharks[MAP[i][j]] = { i,j,1,0,{} };
			}
		}
	}
	for (int i = 1; i <= M; i++)
		cin >> sharks[i].dir;

	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= 4; j++)
			for (int k = 1; k <= 4; k++)
				cin>>sharks[i].pdir[j][k];
}

int Empty(int i) {
	shark now = sharks[i];
	for (int j = 1; j <= 4; j++) {
		int nowdir = now.pdir[now.dir][j];
		int ny = now.y + ydir[nowdir];
		int nx = now.x + xdir[nowdir];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

		if (!SMELL[ny][nx].sharknum)
		{
			sharks[i].y = ny;
			sharks[i].x = nx;
			sharks[i].dir = nowdir;
			return 1;
		}
	}
	return 0;
}

void MySmell(int i) {
	shark now = sharks[i];
	for (int j = 1; j <= 4; j++) {
		int nowdir = now.pdir[now.dir][j];
		int ny = now.y + ydir[nowdir];
		int nx = now.x + xdir[nowdir];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (SMELL[ny][nx].sharknum == i) {
			sharks[i].y = ny;
			sharks[i].x = nx;
			sharks[i].dir = nowdir;
			break;
		}
	}
}


void solution() {
	// 맨처음 자신 위치 냄새 -> while(1){ 냄새 -> 이동 -> 냄새 감소 }
	
	while (t<=1000) {
		// 자기 자리 냄새 남김
		for (int i = 1; i <= M; i++) {
			if (sharks[i].isAlive) {
				SMELL[sharks[i].y][sharks[i].x].count = k;
				SMELL[sharks[i].y][sharks[i].x].sharknum = i;

			}
		}

		// 이동 위치 갱신
		for (int i = 1; i <= M; i++) {
			if (!sharks[i].isAlive)continue;
			int find = Empty(i);
			if (!find) MySmell(i);
		}
		
		// 죽을 상어 선택
		for (int i = 1; i <M; i++) {
			if (!sharks[i].isAlive)continue;
			int ty = sharks[i].y;
			int tx = sharks[i].x;
			for (int j = i + 1; j <= M; j++) {
				if (!sharks[j].isAlive)continue;
				if (sharks[j].y == ty && sharks[j].x == tx) {
					sharks[j].isAlive = 0;
					alive--;
				}
			}
		}

		// 냄새 감소
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (SMELL[i][j].count) {
					SMELL[i][j].count--;
					if (!SMELL[i][j].count)
						SMELL[i][j].sharknum = 0;
				}
			}
		}
		t++;
		if (alive == 1)break;
	}

}

int main() {
	input();
	solution();
	if (t > 1000)t = -1;
	cout << t;

}
