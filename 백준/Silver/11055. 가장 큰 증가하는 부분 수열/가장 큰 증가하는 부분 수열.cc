#include <iostream>
#define MAX(a,b)((a>b)?a:b)
using namespace std;

int n,ans=-21e8;
int arr[1000],dp[1000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		dp[i] = arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j]) dp[i] = MAX(dp[j] + arr[i], dp[i]);
		ans = MAX(dp[i], ans);
	}
	cout << ans;
}