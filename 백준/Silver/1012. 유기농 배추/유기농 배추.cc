#include <iostream>
#include <queue>
using namespace std;

int T,n,m,k;
int map[50][50], visited[50][50], ans = 0;

void input()
{
	cin >> n >> m>>k;
	for (int i = 0; i < k; i++)
	{
		int y, x;
		cin >> y >> x;
		map[y][x] = 1;
	}
}

void bfs(int sy, int sx)
{
	ans++;
	queue<pair<int, int>> q;
	q.push({ sy,sx });
	visited[sy][sx] = 1;

	int ydir[] = { -1,1,0,0 };
	int xdir[] = { 0,0,-1,1 };

	while (!q.empty())
	{
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = nowy + ydir[i];
			int nx = nowx + xdir[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (visited[ny][nx])continue;
			if (!map[ny][nx])continue;
			visited[ny][nx] = 1;
			q.push({ ny,nx });
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		input();

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (map[i][j] && !visited[i][j])bfs(i, j);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				map[i][j]=visited[i][j] = 0;

		cout << ans << '\n';
		ans = 0;
	}
	

}
