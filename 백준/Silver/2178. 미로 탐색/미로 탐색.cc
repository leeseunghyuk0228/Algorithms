#include <iostream>
#include <queue>
using namespace std;

int N, M;
int MAP[100][100][2];

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			MAP[i][j][0] = s[j]-'0';
		}
	}

};

void bfs()
{
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	MAP[0][0][1] = 1;

	int ydir[] = { -1,0,1,0 };
	int xdir[] = { 0,-1,0,1 };

	while (!q.empty())
	{
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = nowy + ydir[i];
			int nx = nowx + xdir[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			if (!MAP[ny][nx][0])continue;
			if (MAP[ny][nx][1])continue;
			q.push({ ny,nx });
			MAP[ny][nx][1] = MAP[nowy][nowx][1] + 1;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	bfs();
	cout << MAP[N - 1][M - 1][1];
}
