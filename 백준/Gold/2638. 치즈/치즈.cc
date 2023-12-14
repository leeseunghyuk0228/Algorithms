#include <iostream>
#include <queue>
using namespace std;

int N,M,MAP[101][101];

void input()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> MAP[i][j];
}

void bfs()
{
    int visited[101][101] = { 0, };
    int ydir[] = { -1,1,0,0 };
    int xdir[] = { 0,0,-1,1 };
    queue < pair<int, int>> q;
    q.push({ 0,0 });
    visited[0][0] = 1;


    while (!q.empty())
    {
        int nowy = q.front().first;
        int nowx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = nowy + ydir[i];
            int nx = nowx + xdir[i];
            if (ny<0 || nx<0 || ny>N || nx>M)continue;
            if (MAP[ny][nx]) visited[ny][nx]++;
            if (!MAP[ny][nx])
            {
                if (visited[ny][nx])continue;
                visited[ny][nx] = 1;
                q.push({ ny,nx });

            }
        }
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (visited[i][j] >= 2)MAP[i][j] = 0;
    
}

bool check_cheese()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (MAP[i][j])return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    int t = 0;
    while(1)
    {
        t++;
        bfs();
        if(!check_cheese()) break;
        
    }
    cout << t;
    return 0;
}