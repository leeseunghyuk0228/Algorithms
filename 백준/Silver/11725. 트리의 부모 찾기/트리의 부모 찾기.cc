#include <iostream>
#include <vector>
using namespace std;

vector<int> vec[100001];
bool visit[100001] = {false};
int parent[100001] = {0};

void dfs(int x){

    visit[x] = true;

    for(int num : vec[x]){
        if(visit[num] == false){
            parent[num] = x;
            dfs(num);
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    for(int i = 0 ; i < n - 1 ; i++){
        int num1, num2;
        cin>>num1>>num2;

        vec[num1].push_back(num2);
        vec[num2].push_back(num1);

    }

    dfs(1);

    for(int i = 2 ; i <= n ; i++){
        cout<<parent[i]<<'\n';
    }

    return 0;

}