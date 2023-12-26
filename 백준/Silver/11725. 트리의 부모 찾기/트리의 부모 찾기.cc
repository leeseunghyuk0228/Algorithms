#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[100001];
int visited[100001];
int ans[100001];
int n;

void input()
{
	cin >> n;
	for (int i = 0; i < n-1; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}
}

void bfs()
{
	queue<int>q;
	q.push(1);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (auto child : v[now])
		{
			if (visited[child])continue;
			ans[child] = now;
			visited[child] = 1;
			q.push(child);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	bfs();
	for (int i = 2; i <= n; i++)
		cout << ans[i] << '\n';
		
}
