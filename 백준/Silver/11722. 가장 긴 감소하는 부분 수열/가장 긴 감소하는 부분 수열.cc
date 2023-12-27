#include <iostream>
#define MAX(a,b)((a>b)?a:b)
using namespace std;

int dp[1001];
int arr[1001];
int ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)cin >> arr[i];

	for (int i = 2; i <= n; i++)
    {
		for (int j = 1; j <= i; j++)
        {
            if (arr[i] < arr[j]) dp[i] = MAX(dp[i], dp[j] + 1);
            ans = MAX(dp[i],ans);
        }
    }			

	cout << ans + 1;

	return 0;
}
