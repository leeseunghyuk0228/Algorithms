#include <iostream>
using namespace std;

int n;
// dp[마지막자리수][수의길이]
long long dp[10][1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int len = 1; len <= n; len++)dp[0][len] = 1;
	for (int last_num = 0; last_num<=9; last_num++) dp[last_num][1] = 1;

	for (int len = 2; len <= n; len++)
		for (int last_num = 1; last_num <= 9; last_num++)
			for (int mini = 0; mini <= last_num; mini++)
				dp[last_num][len] = (dp[last_num][len] + dp[mini][len - 1]) % 10007;

	long long ans = 0;
	
	for (int i = 0; i <= 9; i++) ans = (ans + dp[i][n])%10007;
	cout << ans;
}