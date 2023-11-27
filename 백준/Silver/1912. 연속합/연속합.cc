#include <iostream>
#define MAX(a,b) ((a>b)?a:b)
using namespace std;

int ans,N,arr[100001],dp[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> arr[i];

	ans = dp[1] = arr[1];

	for (int i = 2; i <= N; i++)
	{
		dp[i] = MAX(dp[i - 1] + arr[i], arr[i]);
		ans = MAX(dp[i], ans);
	}
	cout << ans;

}