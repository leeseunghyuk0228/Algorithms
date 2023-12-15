#include <iostream>
#define MAX(a,b)((a>b)?a:b)
using namespace std;

int n,m,num[1025][1025],dp[1025][1025];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);cout.tie(0);
    cin >> n>>m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> num[i][j];

    dp[1][1] = num[1][1];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)continue;
            if (i == 1) dp[i][j] = dp[i][j-1] + num[i][j];
            else if (j == 1)dp[i][j] = dp[i-1][j] + num[i][j];
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + num[i][j];
        }

    for (int i = 0; i < m; i++)
    {
        int sx, sy, lx, ly;
        cin >> sx >> sy >> lx >> ly;
        cout << dp[lx][ly] - dp[lx][sy-1] - dp[sx-1][ly] + dp[sx-1][sy-1]<<'\n';
    }


    return 0;
}