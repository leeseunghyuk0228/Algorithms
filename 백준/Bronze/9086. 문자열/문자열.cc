#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    string s;
    
    cin>>n;
    
    for(int i=0;i<n;i++)
    {    
        cin>>s;
        cout<<s[0]<<s[s.length()-1]<<'\n';
    }
    return 0;    
}
