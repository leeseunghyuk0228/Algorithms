#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M, MAP[1000][1000], visited[1000][1000][2]; // 2차원 배열을 3차원으로 변경

void bfs()
{
    queue<pair<int, pair<int, int>>> q;
    q.push({ 0, {0, 0} });
    visited[0][0][0] = 1; // 3차원 배열로 변경

    int ydir[] = { -1, 1, 0, 0 };
    int xdir[] = { 0, 0, -1, 1 };

    while (!q.empty())
    {
        int nowy = q.front().second.first;
        int nowx = q.front().second.second;
        int crushed = q.front().first;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = nowy + ydir[i];
            int nx = nowx + xdir[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                continue;

            if (MAP[ny][nx] && !crushed)
            {
                q.push({ 1,{ny,nx} });
                visited[ny][nx][1] = visited[nowy][nowx][0] + 1;
            }

            else if (!MAP[ny][nx] && !visited[ny][nx][crushed])
            {
                q.push({ crushed,{ny,nx} });
                visited[ny][nx][crushed] = visited[nowy][nowx][crushed] + 1;
            }

            if (ny == N - 1 && nx == M - 1)
            {
                cout << visited[ny][nx][crushed];
                return; 
            }
        }
    }

    cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> N >> M;

    

    for (int i = 0; i < N; i++)
    {
        cin >> s;
        for (int j = 0; j < M; j++)
            MAP[i][j] = s[j] - '0';
    }

    if (N == 1 && M == 1 && MAP[0][0]==0)
    {
        cout << 1; return 0;
    }

    bfs();

    return 0;
}
