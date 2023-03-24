#include <iostream>
#include <algorithm>
using namespace std;
int dp[15];

int main() {
	int N;
	cin >> N;
	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		int days, cost;
		cin >> days >> cost;
		int endday = i + days - 1;
		dp[i] = max(dp[i], dp[i - 1]);
		if (endday > N)continue;
		dp[endday] = max(dp[endday], dp[i-1] + cost);
	}
	cout << dp[N];

}