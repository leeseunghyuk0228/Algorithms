#include <iostream>
#include <vector>
using namespace std;

int N,res, d;
vector<int> v[51];

void dfs(int node)
{

	// 현재가 삭제된 노드
	if (node == d) return;

	// 현재가 리프노드
	if (!v[node].size()) { res++; return; }


	// 자식 노드 있음
	for (int next : v[node])
	{
		// 다음 노드가 삭제된 노드다
		if (next == d)
		{
			// 그리고 자식은 이 노드 뿐이다 => 내가 리프노드
			if (v[node].size() == 1) res++;
			continue;
		}
		// 다음 노드가 일반 노드다
		dfs(next);
	}

}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;

	int n,start;

	for (int i = 0; i < N; i++)
	{
		cin >> n;
		if (n == -1) start = i;
		else v[n].push_back(i);
	}

	cin >> d;
	dfs(start);
	cout << res;

	return 0;

}