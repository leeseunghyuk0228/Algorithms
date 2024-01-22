#include <iostream>
#include <vector>
using namespace std;

int N,res;
vector<pair<int,int>> v[10001];
int visited[10001];
int next_start;

void input()
{
	cin >> N;
	for (int i = 0; i < N-1; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		v[from].push_back({ to,weight });
		v[to].push_back({ from,weight });
	}
}

void dfs(int start,int now_weight)
{
	visited[start] = 1;

	if (now_weight > res)
	{
		res = now_weight;
		next_start = start;
	}
	for (auto n : v[start])
	{
		if (visited[n.first])continue;
		dfs(n.first,now_weight + n.second);
	}

}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	dfs(1,0);
	for (int i = 1; i <= N; i++)visited[i] = 0;
	dfs(next_start, 0);

	cout << res;
}
