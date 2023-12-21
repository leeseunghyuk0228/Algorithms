#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> um;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num; cin >> num;
		if (um.find(num) != um.end())um[num]++;
		else um[num] = 1;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int num; cin >> num;
		if (um.find(num) != um.end())cout << um[num] << " ";
		else cout << 0 << " ";

	}
	return 0;
}
