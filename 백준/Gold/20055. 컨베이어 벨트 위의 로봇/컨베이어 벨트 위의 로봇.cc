#include <iostream>
using namespace std;
int BELT[2][200];
int N, K;
int cnt = 0;
int Rcnt = 1;
int nowcnt = 0;
int idx;
void input() {
	cin >> N >> K;
	for (int i = 0; i < N * 2; i++) 
		cin >> BELT[0][i];
	idx = (2*N) - 1;
}

void rotate() {
	int temp = BELT[0][idx];
	int RobotTemp= BELT[1][idx];

	for (int i = idx; i >= 1; i--) 
	{
		BELT[0][i] = BELT[0][i - 1];
		BELT[1][i] = BELT[1][i - 1];
	}

	BELT[0][0] = temp;
	BELT[1][0] = RobotTemp;

	if (BELT[1][N - 1]) {
		nowcnt--;
		BELT[1][N - 1] = 0;
	}
}

void move() {
	for (int i = Rcnt-nowcnt; i <= Rcnt; i++) {
		for (int j = 0; j < N; j++) {
			if (BELT[1][j] == i) {
					if (BELT[0][j + 1] > 0 && BELT[1][j+1]==0)
					{
						BELT[0][j + 1]--;
						BELT[1][j + 1] = BELT[1][j];
						if (j + 1 == N - 1)
						{
							BELT[1][N - 1] = 0;
							nowcnt--;
						}
						BELT[1][j] = 0;

					}
				break;
			}
		}
	}
}

void Uploading() {
	if (BELT[0][0] && !BELT[1][0]) {
		nowcnt++;
		BELT[1][0] = Rcnt++;
		BELT[0][0]--;
	}
}

bool check() {
	int empty = 0;
	for (int i = 0; i < 2*N; i++)
		if (!BELT[0][i])empty++;
	if (empty >= K)return true;
	return false;
}

int main() {
	input();
	while (1) {
		cnt++;
		rotate();
		move();
		Uploading();
		if (check())break;
	}
	cout << cnt;

}