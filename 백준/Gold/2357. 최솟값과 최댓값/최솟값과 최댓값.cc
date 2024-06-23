#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
long long arr[100001];

std::vector<long long> MAXtree;
std::vector<long long> MINtree;

void init(int node, int st,int en)
{
	if (st == en)
	{
		MINtree[node] = MAXtree[node] = arr[st];
		return;
	}

	init(node * 2, st, (st + en) / 2);
	init(node * 2+1,(st + en) / 2+1,en);

	MAXtree[node] = std::max(MAXtree[node * 2], MAXtree[node * 2 + 1]);
	MINtree[node] = std::min(MINtree[node * 2], MINtree[node * 2 + 1]);

}

std::pair<int, int> GetMinMax(int node, int st, int en, int qst, int qen)
{
	if (qst > en || qen < st)
		return std::make_pair(INT32_MAX, 0);
	else if (qst <= st && en <= qen)
		return std::make_pair(MINtree[node], MAXtree[node]);
	else
	{
		std::pair<int, int> left, right;
		left = GetMinMax(node * 2, st, (st + en) / 2, qst, qen);
		right = GetMinMax(node * 2 + 1, (st + en) / 2 + 1, en, qst, qen);
		return std::make_pair(std::min(left.first, right.first), std::max(left.second, right.second));
	}

}

int main()
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> N>>M;
	MAXtree.assign(N*4, 0);
	MINtree.assign(N*4, 0);

	for (int i = 1; i <= N; i++)
		std::cin >> arr[i];

	init(1,1,N);

	int st, en;

	for (int i = 0; i < M; i++)
	{
		std::cin >> st >> en;
		std::pair<int, int> res = GetMinMax(1, 1, N, st, en);
		std::cout << res.first << " " << res.second << '\n';
	}

}