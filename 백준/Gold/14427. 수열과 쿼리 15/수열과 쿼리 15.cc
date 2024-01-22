#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<pair<int, int>> tree; // 값, 인덱스
vector<int> v;

void input()
{
	cin >> N;
	tree.resize(4 * N);
	v.resize(N);

	for (int i = 0; i < N; i++)cin >> v[i];
}

pair<int, int> init(int idx, int start, int end)
{
	if (start == end) return tree[idx] = { v[start],start };
	else return tree[idx] = min(init(2 * idx, start, (start + end) / 2), init(2 * idx+1, (start + end) / 2+1, end));
}

pair<int, int> update(int idx, int start, int end, int addr, int val)
{
	if (addr<start || addr>end) return tree[idx];
	if (start == end) return tree[idx] = { val, tree[idx].second };
	return tree[idx] = min(update(idx * 2, start, (start + end) / 2,addr, val), update(idx * 2 + 1, (start + end) / 2+1, end,addr,val));
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	init(1,0,N-1);
	cin >> M;
	int r,node,val;

	for (int i = 0; i < M; i++)
	{
		cin >> r;
		if (r == 2) cout << tree[1].second + 1 << '\n';
		else {
			cin >> node >> val;
			update(1, 0, N - 1, node - 1, val);
			v[node - 1] = val;
		}
	}
    return 0;
}