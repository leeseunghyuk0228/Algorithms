#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


int buildTime[1001];
int degree[1001];
int dp[1001];
int N, K;
vector<int> nextBuild[1001];

void input()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++)cin >> buildTime[i];
	for (int i = 0; i < K; i++)
	{
		int from, to;
		cin >> from >> to;
		nextBuild[from].push_back(to);
		degree[to]++;
	}
}

int MAX(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T,target;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		input();

		cin >> target;
		queue<int> q;

		for (int i = 1; i <= N; i++)
		{
			if (degree[i] == 0)
			{
				q.push(i);
				dp[i] = buildTime[i];
			}
		}

		while (!q.empty())
		{
			int n = q.front();
			q.pop();
			
			int cnt = nextBuild[n].size();
			
			for (int i = 0; i < cnt; i++)
			{
				int next = nextBuild[n][i];
				dp[next] = MAX(dp[next], dp[n] + buildTime[next]);
				degree[next]--;

				if (degree[next] == 0)q.push(next);
			}
		}

		cout << dp[target] << '\n';

		for (int i = 0; i < 1001; i++)nextBuild[i].clear();
		memset(buildTime, 0, sizeof(buildTime));
		memset(dp, 0, sizeof(dp));
		memset(degree, 0, sizeof(degree));
	}

	return 0;
}