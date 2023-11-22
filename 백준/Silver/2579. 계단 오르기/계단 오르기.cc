#include <iostream>
using namespace std;

int n,dp[301],points[301];


int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)cin >> points[i];

	dp[1] = points[1];
	dp[2] = points[1] + points[2];
	dp[3] = max(points[1]+points[3],points[2]+points[3]);

	for (int i = 4; i <= n; i++) 
		dp[i] = max(dp[i - 2] + points[i], dp[i - 3] + points[i - 1] + points[i]);
	cout << dp[n];
}