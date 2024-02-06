#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge
{
	int to;
	int cost;
	bool operator < (edge next) const
	{
		if (cost < next.cost) return false;
		if (cost > next.cost) return true;
		return false;
	}
};

int N, M;
vector<edge> v[10001];
int visited[10001];

void prim(int start)
{
	priority_queue<edge> pq;
	pq.push({ start,0 });

	
	int sum = 0;
	int cnt = 0;

	while (!pq.empty())
	{
		edge now = pq.top(); pq.pop();

		if (visited[now.to])continue;
		visited[now.to] = 1;

		sum += now.cost;
		cnt++;

		for (int i = 0; i < v[now.to].size(); i++)
		{
			edge next = v[now.to][i];
			if (visited[next.to])continue;
			pq.push(next);
		}
	}

	cout << sum;

}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int from, to, w;
		cin >> from >> to >> w;

		v[from].push_back({ to,w });
		v[to].push_back({ from,w });
	}

	prim(1);

	return 0;
}