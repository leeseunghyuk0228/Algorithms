#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;


void input(vector<int> &v)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	cin >> M;
}

void search(vector<int>& v, long long value)
{
	int low = 0, high = N - 1, mid = N / 2;

	while (low <= high)
	{
		if (v[mid] == value)
		{
			cout << 1 << '\n';
			return;
		}
		if (value < v[mid]) high = mid - 1;
		else if (value > v[mid]) low = mid + 1;
		mid = (low + high) / 2;
	}

	cout << 0 << '\n';
	return;

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	vector<int> v;

	input(v);
	sort(v.begin(), v.end());

	for (int i = 0; i < M; i++)
	{
		long long temp;
		cin >> temp;
		search(v,temp);
	}
}
