#include <iostream>
#include <vector>
#define MIN(a,b) ((a<b)?a:b)
using namespace std;

struct Node{ int x, y; };

int N, M, ans = 21e8, hidx = 0, cidx = 0;
int visited[13];

Node house[100];
Node chicken[13];

int get_distance(int sy, int sx, int ty, int tx)
{
	return abs(sy - ty) + abs(sx - tx);
}

void dfs(int level,int cnt)
{
	if (cnt == M)
	{
		int temp = 0;
		
		for (int i = 0; i < hidx; i++)
		{
			int home_to_chicken = 21e8;
			Node now = house[i];
			for (int j = 0; j < 13; j++)
			{
				if(visited[j])
					home_to_chicken = MIN(home_to_chicken, get_distance(now.y, now.x, chicken[j].y, chicken[j].x));
			}
			temp += home_to_chicken;
			if (temp > ans) return;
		}
		ans = MIN(temp, ans);
		return;
	}

	for (int i = level; i < cidx; i++) 
	{
		if (visited[i])continue;
		// 현재 단계 고른다
		visited[i] = 1;
		dfs(i,cnt+1);
		visited[i] = 0;
	}

}

void input() {

	int temp;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> temp;
			if (temp == 1) house[hidx++] = { i,j };
			if (temp == 2) chicken[cidx++] = { i,j };
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	input();
	dfs(0,0);
	cout << ans;
}
