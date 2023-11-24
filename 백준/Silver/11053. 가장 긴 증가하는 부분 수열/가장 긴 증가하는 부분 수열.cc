#include <iostream>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int N,arr[1001],dp[1001],ans=0;

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
}
int main() {
	input();
	dp[1] = 1;

	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--) 
		{
			if (arr[i] > arr[j]) 
				dp[i] = MAX(dp[j] + 1, dp[i]);
		}
		ans = MAX(dp[i],ans);
	}

	cout << ans;
	return 0;
}
