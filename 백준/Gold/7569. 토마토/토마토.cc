#include <iostream>
#include <queue>
using namespace std;

int N, M, H;
int tomatoes[100][100][100];

int ydir[] = { -1,1,0,0,0,0 };
int xdir[] = { 0,0,-1,1,0,0 };
int hdir[] = { 0,0,0,0,-1,1 };
int unriped = 0;
int days = 0;

queue<pair<pair<int,int>,int>> q;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> M >>N >> H;

	for (int h = 0; h < H; h++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> tomatoes[i][j][h];
				if (tomatoes[i][j][h] == 1)q.push({ { i,j},h });
				else if (tomatoes[i][j][h] == 0)unriped++;
			}
		}
	}

	if (unriped == 0) { cout << 0; return 0; }
	if (unriped != 0 && q.size() == 0) { cout << -1; return 0; }

	while (!q.empty())
	{
		days++;
		int cursize = q.size();

		for (int cur = 0; cur < cursize; cur++)
		{
			int nowy = q.front().first.first;
			int nowx = q.front().first.second;
			int nowh = q.front().second;
			q.pop();
			for (int i = 0; i < 6; i++)
			{
				int ny = nowy + ydir[i];
				int nx = nowx + xdir[i];
				int nh = nowh + hdir[i];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M || nh < 0 || nh >= H)continue;
				if (tomatoes[ny][nx][nh] != 0)continue;
				tomatoes[ny][nx][nh] = 1;
				unriped--;
				q.push({ {ny,nx},nh });
				
			}
		};

		if (unriped == 0)break;
	}

	if (unriped == 0) cout << days;
	else cout << -1;

	return 0;

}