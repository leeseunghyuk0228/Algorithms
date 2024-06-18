#include <iostream>
#include <vector>

std::vector<long long> v;
long long arr[1000001];

long long init(int node, int st, int en)
{
	if (st == en)return v[node] = arr[st];
	return v[node] = init(2 * node, st, (st + en) / 2) + init(2 * node + 1, (st + en) / 2 + 1, en);
}

void update(int node, int st, int en, int index,long long val)
{
	if (st > index || index > en) return;
	v[node] += val;
	if (st == en)return;

	update(node * 2, st, (st + en) / 2, index, val);
	update(node * 2+1, (st + en) / 2+1,en, index, val);
}

long long query(int node, int st, int en, int qst, int qen)
{
	// qst st en qen
	if (qen < st || qst > en) return 0;
	if (qst<=st && en<=qen) return v[node];

	long long left = query(node * 2, st, (st + en) / 2, qst, qen);
	long long right = query(node * 2+1, (st + en) / 2 + 1, en, qst, qen);

	return left + right;
}

int main() {
	int N, M, K;
	std::cin >> N >> M >> K;
	v.assign(N * 4, 0);

	long long a, b, c;

	for (int i = 0; i < N; i++)
		std::cin >> arr[i];
	init(1, 0, N - 1);

	for (int i = 0; i < M + K; i++)
	{
		std::cin >> a >> b >> c;
		if (a == 1)
		{
			long long val = c - arr[b - 1];
			arr[b - 1] = c;
			update(1, 0, N - 1, b - 1, val);

		}
		else if(a==2)
			std::cout << query(1, 0, N-1 , b - 1, c - 1) << '\n';
	}

}