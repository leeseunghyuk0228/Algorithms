#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;
set<string> st;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int N,M;
    string temp;
    cin>>N>>M;
    
    for(int i=0;i<N;i++)
    {
        cin>>temp;
        st.insert(temp);
    }
    for(int i=0;i<M;i++)
    {
        cin>>temp;
        if(st.find(temp)!=st.end()) v.push_back(temp);
    }
    
    sort(v.begin(),v.end());
    cout<<v.size()<<'\n';
    for(auto a:v) cout<<a<<'\n';
    
    return 0;
}