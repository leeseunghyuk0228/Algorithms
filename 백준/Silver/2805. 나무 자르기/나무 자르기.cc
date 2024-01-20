#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long tree,low=0, high =-1,mid,ans;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> tree;
		v.push_back(tree);
		if (tree > high)high = tree;
	}


	while (low<=high)
	{
		mid = (high + low) / 2;
		long long sum = 0;

		for (int i = 0; i < N; i++)
			if (mid < v[i]) sum += v[i] - mid;

		if (sum >= M)
		{
			ans = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}

	cout << ans;
	return 0;

}