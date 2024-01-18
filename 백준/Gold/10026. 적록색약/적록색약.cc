#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N,res;
int visited[100][100];

int ydir[] = { -1,1,0,0 };
int xdir[] = { 0,0,-1,1 };
string s[100];

void bfs(int sy,int sx,int type)
{

	
	
	queue<pair<int, int>> q;
	q.push({ sy,sx });

	visited[sy][sx] = 1;
	res++;

	while (!q.empty())
	{
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = nowy + ydir[i];
			int nx = nowx + xdir[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= s[i].length()) continue;
			if (visited[ny][nx])continue;

			if (type == 1 && s[ny][nx] != s[nowy][nowx]) continue;
			
			if (type == 2)
			{
				if (s[nowy][nowx] == 'R' && s[ny][nx] == 'B')continue;
				if (s[nowy][nowx] == 'G' && s[ny][nx] == 'B')continue;
				if (s[nowy][nowx] == 'B' && s[ny][nx] != 'B') continue;
			}

			q.push({ ny,nx });
			visited[ny][nx] = 1;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> s[i];

	for (int i = 0; i < N; i++) for (int j = 0; j < s[i].length(); j++) if (!visited[i][j])bfs(i,j,1);
	cout << res << '\n';	res = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) visited[i][j] = 0;
	
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (!visited[i][j])bfs(i,j,2);
	cout << res << '\n';
	
	return 0;

}