#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int dp[100001] = { 0,1,2,3, };


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 4; i <= n; i++)
	{
		dp[i] = i;
		int root = int(sqrt(i));

		if (sqrt(i) - root == 0)
		{
			dp[i] = 1;
			continue;
		}
		
		for (int j = 1; j <= root; j++)
			dp[i] = min(dp[i],dp[j * j] + dp[i - (j * j)]);
	}
	cout << dp[n]<<'\n';

	return 0;
}
