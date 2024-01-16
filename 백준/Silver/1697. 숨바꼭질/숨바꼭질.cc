#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, K,res;
queue<int>q;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	res = K - N;

	if (N >= K) {
		cout << N-K;
		return 0;
	}

	queue<int> q; q.push(N);
	int dist[100001];
	memset(dist, -1, sizeof(dist));
	dist[N] = 0;

	while (!q.empty())
	{
		int now = q.front(); q.pop();
		int d[] = { now-1,now+1,now*2 };

		for (int n : d)
		{
			if (n < 0 || n>100000)continue;
			if (dist[n] >= 0)continue;
			dist[n] = dist[now] + 1;
			if (n == K) {
				cout << dist[n];
				return 0;
			}
			q.push(n);
		}
	}


	cout << res;

}