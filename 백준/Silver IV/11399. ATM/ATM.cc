#include <iostream>
#include <algorithm>
using namespace std;

int arr[1005];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    int ans = 0;
    
    cin>>n;
        
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    for(int i=0;i<n;i++) ans += arr[i]*(n-i);

    cout<<ans;

    return 0;
}