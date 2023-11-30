#include <iostream>

using namespace std;

long long dp[1001];
int n;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    dp[1]=1;
    dp[2]=3;

    for(int i=3;i<=1000;i++)
        dp[i] = (dp[i-1]+dp[i-2]*2)%10007;

    cin>>n;
    cout<<dp[n];

}