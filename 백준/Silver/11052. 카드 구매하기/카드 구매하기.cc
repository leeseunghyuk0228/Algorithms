#include <iostream>
#define MAX(a,b)((a>b)?a:b)
using namespace std;

int N, price[1001], dp[1001];

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)cin >> price[i];
	
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
			dp[i] = MAX(dp[i], dp[i - j]+price[j]);

	cout << dp[N];
	return 0;
}