#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define MIN(a,b)((a<b)?a:b)
using namespace std;

int dp[10001];
vector<int>coins;
set<int> coin_check;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, target;
	cin >> n >> target;

	while (n--)
	{
		int c; cin >> c;
		if (c == 0 || c > 10000)continue;
		if (coin_check.find(c) == coin_check.end())
		{
			coin_check.insert(c);
			coins.push_back(c);
		}
	}

	for (int i = 1; i <= target; i++)dp[i] = 10001;


	for (auto coin : coins)
		for (int i = coin; i <= target; i++)
			dp[i] = MIN(dp[i-coin]+1, dp[i]);


	if (dp[target] == 10001)cout << -1;
	else cout << dp[target];

	
	return 0;
}