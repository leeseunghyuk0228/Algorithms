#include <iostream>
#define MAX(a,b)((a>b)?a:b)
using namespace std;


int weights[101], values[101];
int N, max_weight, dp[101][100001];

void input()
{
	cin >> N >> max_weight;
	for (int i = 1; i <= N; i++)
		cin >> weights[i] >> values[i];
}

int main()
{

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= max_weight; j++)
		{
			if (weights[i] > j)dp[i][j] = dp[i - 1][j];
			else dp[i][j] = MAX(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]);
		}
	}

	cout << dp[N][max_weight];

}

