#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int ydir[] = { 2, 2,-1,-1, 1,1,-2,-2 };
int xdir[] = { -1,1,-2, 2,-2,2,-1, 1};
int visited[300][300];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T,I;
	int sy, sx;
	int ty, tx;
	
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> I>> sy >> sx >> ty >> tx;

		if (sy == ty && sx == tx) { cout << 0<<'\n'; continue; }

		queue<pair<int, int>> q;

		visited[sy][sx] = 1;
		q.push({ sy,sx });
		int cnt = 0;
		int flag = 0;

		while (!q.empty())
		{
			int cursize = q.size();
			cnt++;
			for (int cur = 0; cur < cursize; cur++)
			{
				int nowy = q.front().first;
				int nowx = q.front().second;
				q.pop();
				for (int i = 0; i < 8; i++)
				{
					int ny = nowy + ydir[i];
					int nx = nowx + xdir[i];
					if (ny < 0 || nx < 0 || ny >= I || nx >= I)continue;
					if (visited[ny][nx])continue;
					if (ny == ty && nx == tx)
					{
						flag = 1;
						break;
					}
					
					visited[ny][nx] = 1;
					q.push({ ny,nx });
					
				}
			}
			if (flag)break;
			
		}

		for (int i = 0; i < I; i++)
			for (int j = 0; j < I; j++) visited[i][j] = 0;
		cout << cnt<<'\n';
	}

	return 0;

}