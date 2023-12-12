#include <iostream>
#define MAX(a,b)((a>b)?a:b)
using namespace std;

int N, arr[2][100001];
int dp[2][100001];

void input()
{
	cin >> N;
	for (int i = 0; i <= 1; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];

}

void solution()
{
	
	dp[0][0] = dp[0][1] = 0;

	dp[0][1] = arr[0][1];
	dp[1][1] = arr[1][1];


	for (int i = 2; i <= N; i++)
	{
		dp[0][i] = MAX(MAX(dp[0][i - 1], dp[1][i - 1] + arr[0][i]), dp[1][i - 2] + arr[0][i]);
		dp[1][i] = MAX(MAX(dp[1][i - 1], dp[0][i - 1] + arr[1][i]), dp[0][i - 2] + arr[1][i]);
	}

	cout << MAX(dp[0][N], dp[1][N])<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		input();
		solution();
	}
}