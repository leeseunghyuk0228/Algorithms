#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,cnt=99;
    cin>>n;
    if(n<100)cnt=n;
    for(int i=100;i<=n;i++){
        int L=i/100;
        int M=i/10%10;
        int R=i%10;
        if(L+R==M*2)cnt++;
    }
    cout<<cnt;
}