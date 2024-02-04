#include <iostream>
using namespace std;

int visited[26];
int N, M,res=1;
string MAP[20];

int ydir[] = { -1,1,0,0 };
int xdir[] = { 0,0,-1,1 };

void dfs(int sy,int sx,int now)
{
	
	if(now>res)res=now;
	if (now > 26)return;

	for (int i = 0; i < 4; i++)
	{
		int ny = sy + ydir[i];
		int nx = sx + xdir[i];
		
		if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;

		int next_char = MAP[ny][nx] - 'A';
		
		if (visited[next_char])continue;
		visited[next_char] = 1;
		dfs(ny, nx, now + 1);
		visited[next_char] = 0;
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> MAP[i];

	visited[MAP[0][0] - 'A'] = 1;
	dfs(0,0,1);
	cout << res;

	return 0;
}