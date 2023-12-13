#include <iostream>
using namespace std;
//dp[num]=A
// num을 나타낼 수 있는 경우의 수 A
// dp[num+1] = dp[num]을 나타내는 수에 1을 나타내는 수(dp[1])를 더해야 한다.
// dp[num+2] = dp[num] + dp[2](dp[1]+dp[2])

int main() {
    int N,K, dp[10001], value[101];
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> value[i];

    // 0 원 이용 -> 나 자신만 사용
    dp[0] = 1;

    // 동전 종류
    for(int i = 1;i<=N;i++)
    {
        int coin = value[i];// {1,2,5}
        for(int j = value[i];j<=K;j++) // coin원 보다 낮은건 만들 수 없다.
        {
            // dp[coin] = coin을 만드는 경우의 수 
            // dp[j] ~ d[k]를 만들기 위해서 dp[j - 내가 사용할 동전(coin)원] 을 누적합 해준다.
            // 그러면 j원에서 coin[i]~coin[N]을 사용했을 때, j-coin원의 경우의 수를 더할 수 있다.
            dp[j] += dp[j - coin];
        }
    }
   
    cout << dp[K];
    return 0;
}
