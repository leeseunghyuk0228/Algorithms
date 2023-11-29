#include <iostream>
using namespace std;

long long dp[100];

int main() {
	long long init[] = { 1,1,1,2,2,3,4,5,7,9,12 };
	int idx,n;
	
	for (int i = 0; i < 11; i++)dp[i] = init[i];
	for (int i = 11; i < 100; i++) dp[i] = dp[i - 1] + dp[i-5];
	cin >> n;
	while (n--)
	{
		cin >> idx;
		cout << dp[idx - 1] << '\n';
	}
}
