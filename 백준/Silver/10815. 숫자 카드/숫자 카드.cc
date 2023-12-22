#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;

int binary_search(int num)
{
	int left = 0;
	int right = n - 1;
	

	while (left <= right)
	{
		int mid = (left + right) / 2;
		int now = v[mid];

		if (num == now)return 1;
		if (now < num) left = mid + 1;
		else if (now > num) right = mid - 1;
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num; cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int num; cin >> num;
		cout << binary_search(num)<<' ';

	}
	return 0;
}
