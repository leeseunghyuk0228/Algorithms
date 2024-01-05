#include <iostream>
#include <queue>
using namespace std;

int MAP[1000][1000];
int N, M,unriped_tomato;
queue<pair<int, int>> riped_tomato;

bool bfs()
{
    int flag = 0;

    int ydir[] = { -1,1,0,0 };
    int xdir[] = { 0,0,-1,1 };
    int cursize = riped_tomato.size();
    if (!cursize)return false;

    for (int i = 0; i < cursize; i++)
    {
        int nowy = riped_tomato.front().first;
        int nowx = riped_tomato.front().second;
        riped_tomato.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = nowy + ydir[i];
            int nx = nowx + xdir[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
            if (MAP[ny][nx] == -1 || MAP[ny][nx] == 1)continue;
            MAP[ny][nx] = flag = 1;
            unriped_tomato--;
            riped_tomato.push({ ny,nx });
        }
    }
    if (flag)return true;
    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int ans = 0;

    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 1)riped_tomato.push({ i,j });
            if (MAP[i][j] == 0)unriped_tomato++;
        }
    }

    while (bfs())
        ans++;

    if (unriped_tomato == 0)cout << ans;
    else cout << -1;


    return 0;
} 