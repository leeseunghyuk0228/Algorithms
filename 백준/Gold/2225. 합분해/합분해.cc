#include <iostream>
using namespace std;

int dp[201][201];

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= k; i++) dp[1][i] = i;

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= k; j++)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;

    cout << dp[n][k];
    return 0;
} 