#include <iostream>
#include <queue>
using namespace std;

// 초기 아기상어 2, 1초에 한칸 상하좌우
// 자신보다 큰 물고기 지나갈 수 없음
// 크기가 같은 물고기 먹을수 X 지나갈 수는 있음
// 없으면? -> 엄마 부르기
// 1마리 -> 먹으러 가기
// 1마리 보다 많으면 -> 가장 가까운 물고기
// 거리 : 지나야 하는 칸의 개수 최소값
// 가장 위, 가장 왼쪽 물고기 부터 먹는다.

// 크기가 같은 수 물고기 먹으면 크기 1증가
typedef struct Coood {
    int y, x;
}coord;

int N, MAP[20][20], sy, sx, ans, ssize, cnt,fishes,catched;
int ydir[] = { -1,1,0,0 };
int xdir[] = { 0,0,-1,1 };


void input() {
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 9)
            {
                sy = i; sx = j;
            }
            else if (MAP[i][j] != 0) fishes++;
        }

    }
}

bool move()
{
    int visited[20][20] = { 0, };
    int ty = 20, tx = 20, dist = 21e8;
    queue<coord> q;
    q.push({ sy,sx });
    visited[sy][sx] = 1;

    while (!q.empty())
    {
        coord now = q.front(); q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue; 
            if (MAP[ny][nx] > ssize)continue; 
            if (visited[ny][nx] != 0)continue; 
            visited[ny][nx] = visited[now.y][now.x] + 1;
            q.push({ ny,nx });

            if (MAP[ny][nx] == 0 || MAP[ny][nx] == ssize)continue;
            if (visited[ny][nx] > dist)continue;


            if (ny < ty || (ny == ty && nx < tx))
            {
                dist = visited[ny][nx];
                ty = ny; 
                tx = nx;
            }

        }
    }

    if (dist != 21e8)
    {
        cnt++;
        MAP[sy][sx] = 0;
        if (cnt == ssize) { ssize++; cnt = 0; }
        MAP[ty][tx] = 9;
        sy = ty;
        sx = tx;
        ans = ans + dist - 1;
        catched++;
        return 1;
    }
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ssize = 2;
    input();

    while (1)
    {
        if (fishes == catched || fishes==0)break;
        if (!move())break;
    }

    cout << ans;
    return 0;
}