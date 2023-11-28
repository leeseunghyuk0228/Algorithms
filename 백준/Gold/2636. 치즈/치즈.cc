#include <iostream>
#include <queue>
#define MAX 100
using namespace std;

typedef struct Coood {
    int y, x;
}coord;

int R,C,MAP[MAX][MAX],ans,cnt;

void input() {
    cin >> R>>C;
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) cin >> MAP[i][j];
}

bool find_edge() {
    ans--;
    queue<coord> q;
    queue<coord> edges;
    q.push({ 0,0 });

    int ydir[] = { -1,1,0,0 };
    int xdir[] = { 0,0,-1,1 };

    while (!q.empty())
    {
        coord now = q.front(); q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];

            if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
            if (MAP[ny][nx] == ans)continue;
            if (MAP[ny][nx] == 1) edges.push({ ny,nx });
            else q.push({ ny,nx });
            MAP[ny][nx] = ans;
        }
    }

    if (edges.empty()) return 0;
    cnt = edges.size();
    return 1;

}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();

    while (1)
    {
        if (!find_edge()) break;
    }

    cout << (ans*-1)-1 << '\n' << cnt << '\n';
}