#include <iostream>
using namespace std;

int MAP[1001][1001];
int dp[1001][1001];
int ydir[] = { 1,0,1 };
int xdir[] = { 0,1,1 };

int MAX(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, M;
	int ny, nx;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> MAP[i][j];

	dp[1][1] = MAP[1][1];

	for (int i = 2; i <= N; i++) dp[i][1] = dp[i - 1][1] + MAP[i][1];
	for (int i = 2; i <= M; i++) dp[1][i] = dp[1][i-1] + MAP[1][i];

	for (int i = 2; i <= N; i++)
		for (int j = 2; j <= M; j++)
			dp[i][j] = MAX(MAX(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + MAP[i][j];

	cout << dp[N][M];
	return 0;
	
}