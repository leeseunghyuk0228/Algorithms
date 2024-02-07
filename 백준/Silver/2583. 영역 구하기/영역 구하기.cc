#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int ydir[]={-1,1,0,0};
int xdir[]={0,0,-1,1};
int m, n, k, a, b, c, d;
int ans = 0;
int visited[101][101];
vector<int> area;
 
void bfs(int sy, int sx){
    ans++;
    queue<pair<int, int>> q;
    q.push({sy,sx});
    visited[sy][sx] = 1;
    int cnt = 1;
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
 
        for (int i = 0; i < 4;i++)
        {
            int ny = y + ydir[i];
            int nx = x + xdir[i];
            if(ny<0||nx<0||ny>=m||nx>=n)continue;
            if(visited[ny][nx])continue;
            q.push({ny,nx});
            visited[ny][nx]=1;
            cnt++;
        } 
    }
    area.push_back(cnt);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> m >> n >> k;
    for (int i = 0; i < k;i++){
        cin >> a >> b >> c >> d;
        for (int r = b; r < d;r++){ 
            for (int l = a; l < c;l++)
                visited[r][l] = 1; 
            }
        }
    
    
    for (int i = 0; i < m; i++) for (int j = 0; j < n;j++) if(!visited[i][j]) bfs(i, j);
    
    cout << ans << '\n';
    
    sort(area.begin(), area.end());
    for(auto ar:area) cout<<ar<<" ";
    
    return 0;
}
