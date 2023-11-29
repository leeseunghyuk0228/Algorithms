#include <iostream>
using namespace std;

int dp[31][31];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,N,M;
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[2][0] = 1;
	dp[2][1] = 2;
	dp[2][2] = 1;
	for (int i = 3; i <= 30; i++)
	{
		for (int j = 0;j<=i/2; j++)
		{
			if (j == 0)dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				dp[i][i - j] = dp[i][j];
		}
	}

	cin >> n;

	while (n--)
	{
		cin >> N >> M;
		cout << dp[M][N]<<'\n';
	}

}