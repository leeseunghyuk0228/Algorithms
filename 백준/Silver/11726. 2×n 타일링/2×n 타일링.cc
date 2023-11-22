#include <iostream>
using namespace std;

int dp[1001];
int n;

int main() {
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < 1001; i++) dp[i] = (dp[i - 1] + dp[i - 2])%10007;

    cin >> n;
    cout << dp[n];
}