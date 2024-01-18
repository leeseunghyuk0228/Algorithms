#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int ydir[] = { -1,1,0,0,-1,1,-1,1 };
int xdir[] = { 0,0,-1,1,-1,-1,1,1};
int MAP[50][50];
int visited[50][50];
int w, h,res;

void bfs(int sy,int sx)
{
	res++;
	queue<pair<int, int>> q;
	q.push({ sy,sx });
	visited[sy][sx] = 1;

	while (!q.empty())
	{
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		for (int i = 0; i <8; i++)
		{
			int ny = nowy + ydir[i];
			int nx = nowx + xdir[i];
			if (ny < 0 || nx < 0 || ny >= h || nx >= w)continue;
			if (visited[ny][nx])continue;
			if (!MAP[ny][nx])continue;
			visited[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (1)
	{
		cin >> w >> h;
		if (!w && !h)break;

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> MAP[i][j];

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (!visited[i][j] && MAP[i][j]) bfs(i, j);

		cout << res << '\n';
		memset(visited, 0, sizeof(visited));
		res = 0;
	}

	return 0;

}