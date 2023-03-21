#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct cctv {
	int y, x, num;
};
bool cmp(cctv left,cctv right){
	if (left.num < right.num) return false;
	if (left.num > right.num) return true; 
	return false;
	
}
vector<cctv>cctvs;

int MAP[8][8];
int N, M;
int res,cctvCnt=0;

int ydir[] = { -1,0,1,0 };
int xdir[] = { 0,1,0,-1 };

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j]>0 && MAP[i][j]<6) {
				cctvs.push_back({ i,j,MAP[i][j] });
				cctvCnt++;
			}
		}
	}
	sort(cctvs.begin(), cctvs.end(), cmp);
	res = N * M;
}

void getline(cctv now, int idx) {
	int cnt = 1;
	while (1) {
		int ny = now.y + ydir[idx] * cnt;
		int nx = now.x + xdir[idx] * cnt;
		if (ny < 0 || nx < 0 || ny >= N || nx >= M)break;
		if (MAP[ny][nx]==6)break;
		MAP[ny][nx] = 9;
		cnt++;
	}
}

void dfs(int level) {
	if (level == cctvCnt) {
		int empty = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!MAP[i][j])empty++;
			}
		}
		if (empty < res) res = empty;
		return;
	}
	int temp[8][8];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) 
			temp[i][j] = MAP[i][j];

	cctv now = cctvs[level];

	if (now.num == 1) {
		for (int i = 0; i < 4; i++) {
			getline(now, i);
			dfs(level + 1);
			for (int k = 0; k < N; k++)
				for (int j = 0; j < M; j++)
					MAP[k][j] = temp[k][j];
		}

	}
	else if (now.num == 2) {
		for (int i = 0; i < 2; i++) {
			getline(now,i);
			getline(now, i + 2);
			dfs(level + 1);
			for (int k = 0; k < N; k++)
				for (int j = 0; j < M; j++)
					MAP[k][j] = temp[k][j];
		}
	}
	else if (now.num == 3) {
		for (int i = 0; i < 4; i++) {
			getline(now, i%4);
			getline(now, (i + 1)%4);
			dfs(level + 1);
			for (int k = 0; k < N; k++)
				for (int j = 0; j < M; j++)
					MAP[k][j] = temp[k][j];
		}
	}
	else if (now.num == 4) {
		for (int i = 0; i < 2; i++) {
			for (int j = i + 1; j < 3; j++) {
				for (int k = j + 1; k < 4; k++) {
					getline(now, i);
					getline(now, j);
					getline(now, k);
					dfs(level + 1);
					for (int n = 0; n < N; n++)
						for (int m = 0; m < M; m++)
							MAP[n][m] = temp[n][m];
				}
			}
		}
	
	}
	else if (now.num == 5) {
		for (int i = 0; i < 4; i++) getline(now, i);
		dfs(level + 1);
		for (int k = 0; k < N; k++)
			for (int j = 0; j < M; j++)
				MAP[k][j] = temp[k][j];
	}

}

int main() {
	input();
	dfs(0);
	cout << res;
}