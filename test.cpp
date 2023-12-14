#include <iostream>
using namespace std;
int N,dp[101],value[101];
int main(){
    cin>>N;
    for(int i=1;i<=N;i++) cin>>value[i];
    dp[1]=1; // 1 (1)
    dp[2]=2;// 11 2(2)
    for(int i=3;i<=N;i++)
    {
        if(i%2==0)dp[i]= dp[i/2]*2+1;
        else dp[i] = dp[i-1]+1;
    }
    cout<<dp[N];
    return 0;
}