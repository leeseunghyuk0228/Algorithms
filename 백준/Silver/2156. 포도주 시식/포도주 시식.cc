#include <iostream>
#define MAX(a,b) ((a>b)?a:b)
using namespace std;

int N, wines[10001],dp[10001],ans=-21e8;

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)cin >> wines[i];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	dp[1] = wines[1];
	dp[2] = dp[1]+wines[2];
	dp[3] = MAX(wines[1] + wines[2], wines[2] + wines[3]);
	dp[3] = MAX(dp[3], wines[1]+wines[3]);

	for (int i = 4; i <= N; i++)
	{
		dp[i] = MAX(dp[i-2]+wines[i], dp[i-3] + wines[i-1]+ wines[i]);
		dp[i] = MAX(dp[i], dp[i - 1]);
	}

	cout << dp[N];
}