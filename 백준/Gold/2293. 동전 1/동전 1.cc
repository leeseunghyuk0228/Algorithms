#include <iostream>
using namespace std;


int main() {
    int N,K, dp[10001]={1,}, value[101]={0,};
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    
    for (int i = 1; i <= N; i++) cin >> value[i];
    
    for(int i = 1;i<=N;i++)
    {
        int coin = value[i];
        for(int j = value[i];j<=K;j++) 
            dp[j] += dp[j - coin];
    }
   
    cout << dp[K];
    return 0;
}