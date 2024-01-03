#include <iostream>
using namespace std;

int dp[51][51][51] = { 1, };

int func(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)return 1;
    if (a > 20 || b > 20 || c > 20)return func(20,20,20);
    if (dp[a][b][c])return dp[a][b][c];
    if (a < b && b < c) dp[a][b][c] = func(a, b, c - 1) + func(a, b - 1, c - 1) - func(a, b - 1, c);
    else dp[a][b][c] = func(a - 1, b, c) + func(a - 1, b - 1, c) + func(a - 1, b, c - 1) - func(a - 1, b - 1, c - 1);
    return dp[a][b][c];

}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while (1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << func(a, b, c) << '\n';
    }

    return 0;
} 