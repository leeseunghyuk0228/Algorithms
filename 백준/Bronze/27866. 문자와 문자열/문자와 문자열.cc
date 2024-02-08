#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    int idx;
    
    cin>>s>>idx;
    cout<<s[idx-1];
    
    return 0;
}