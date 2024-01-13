#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int num[1001] = { 0, };
	int n, k, start = 0,cnt=0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)num[i] = 1;
	cout << "<";
	for (int i = 0; i < n; i++)
	{
		while (cnt != k)
		{
			start++;
			if (start > n)start -= n;
			if (num[start])cnt++;
		}
		cnt = 0;
		cout << start;
		if (i != n - 1)cout << ", ";
		num[start] = 0;
	}
	cout << ">";
}