#include <iostream>
using namespace std;

int ydir[] = { -1,1,0,0 };
int xdir[] = { 0,0,-1,1 };

int N, M;
int map[500][500];
int dp[500][500];

int dfs(int y, int x)
{
    if (y == N-1 && x == M - 1) return 1;
    
    if (dp[y][x] == -1) {
        dp[y][x] = 0;
        for (int i = 0; i < 4; i++) {
            int ny = y + ydir[i];
            int nx = x + xdir[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
            if (map[y][x] > map[ny][nx]) 
                dp[y][x] += dfs(ny, nx);
        }
    }

    return dp[y][x];
}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            dp[i][j] = -1;
        }

  
    cout << dfs(0, 0);

    return 0;
}