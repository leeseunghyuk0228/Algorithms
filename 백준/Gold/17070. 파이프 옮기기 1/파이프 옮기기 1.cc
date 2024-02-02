#include <iostream>
#include <queue>
using namespace std;

struct coord
{
	int type,sy, sx, ey, ex;
};
int MAP[17][17],N;
int ydir[] = { 0,1,1 };
int xdir[] = { 1,0,1 };

int bfs()
{
	int res = 0;
	queue<coord> q;
	q.push({ 0,0,0,0,1 });

	while (!q.empty())
	{
		coord now = q.front(); q.pop();

		if (now.ey == N - 1 && now.ex == N - 1) { res++; continue; }

		for (int i = 0; i < 3; i++)
		{
			if (now.type + i == 1)continue;

			int ny = now.ey + ydir[i];
			int nx = now.ex + xdir[i];
			
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
			if (MAP[ny][nx])continue;
			if (i == 2 && (MAP[ny - 1][nx]|| MAP[ny][nx - 1])) continue;
			
			q.push({ i,now.ey,now.ex,ny,nx });
		}
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> MAP[i][j];

	cout << bfs();
	return 0;
}