#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M,res;
int visited[1001] = { 0, };
vector<int> v[1001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;

	int from, to;
	for (int i = 0; i < M; i++)
	{
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	for (int i = 1; i <= N; i++)
	{
		if (visited[i])continue;
		res++;
		queue<int>q;
		q.push(i);

		while (!q.empty())
		{
			int now = q.front(); q.pop();
			for (int next : v[now])
			{
				if (visited[next])continue;
				visited[next] = 1;
				q.push(next);
			}
		}
	}

	cout << res;

	return 0;

}