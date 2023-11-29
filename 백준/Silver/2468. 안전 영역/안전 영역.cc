#include <iostream>
#include <queue>
#define MAX(a,b) ((a>b)?a:b)

typedef struct Coord {
	int y, x;
}coord;

int N, MAP[100][100], visited[100][100];
int high=-21e8,cnt,res=0;
using namespace std;

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
			high = MAX(MAP[i][j], high);
		}
	}
		
}

void flood(int level)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (MAP[i][j] <= level)
				visited[i][j] = 1;
}

void bfs(int sy, int sx)
{
	queue<coord> q;
	q.push({ sy,sx });
	visited[sy][sx] = 1;

	while (!q.empty())
	{
		coord now = q.front(); q.pop();
		int ydir[] = { -1,1,0,0 };
		int xdir[] = { 0,0,-1,1 };

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (visited[ny][nx])continue;
			visited[ny][nx] = 1;
			q.push({ ny,nx });
		}
 	}
}

void find_max_area()
{
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			if (visited[r][c])continue;
			cnt++;
			bfs(r, c);
		}
	}
}

void init() {
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)visited[i][j] = 0;
	cnt = 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	for (int i = 0; i <= high; i++)
	{
		flood(i);
		find_max_area();
		res = MAX(res, cnt);
		init();
	}
	cout << res;

}