#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node{int to, w;};

vector<node> v[20001];
int dist[20001];
int N, M;

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start});
	
	dist[start] = 0;

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		int cursize = v[now].size();
		for (int cur=0; cur<cursize;cur++)
		{
			node next = v[now][cur];
			int next_cost = next.w;
			int next_node = next.to;

			if (dist[next_node] > cost + next_cost)
			{
				dist[next_node] = cost + next_cost;
				pq.push({ -dist[next_node],next_node });
			}
		}

	}

}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int start, from, to, w;
	cin >> N >> M >> start;
	for (int i = 1; i <= N; i++)dist[i] = 21e8;
	for (int i = 0; i < M; i++)
	{
		cin >> from >> to >> w;
		v[from].push_back({to,w});
	}

	dijkstra(start);

	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == 21e8) cout << "INF\n";
		else cout << dist[i] << '\n';
	}

	return 0;

}