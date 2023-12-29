#include <iostream>
#include <vector>
#include <algorithm>
#define MAX(a,b)((a>b)?a:b)
using namespace std;

struct lines { int from, to; };
vector<lines> v;
int dp[100];
int n,end;
int lcs;

bool cmp(lines left, lines right)
{
    if (left.from < right.from) return true;
    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int from, to;
        cin >> from >> to;
        v.push_back({ from,to });
    }
    
    sort(v.begin(), v.end(),cmp);
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j <= i; j++)
        {
            if (v[j].to < v[i].to) dp[i] = MAX(dp[j]+1, dp[i]);
        }
        lcs = MAX(dp[i], lcs);
    }

    cout << n - lcs;
    return 0;
}