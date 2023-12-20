#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<char, int> um;
vector<char> v;
int max_num = -21e8;
char ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	for (auto c : s)
	{
		c = toupper(c);
		if (um.find(c) != um.end())
			um[c]++;
		else
		{
			um[c] = 1;
			v.push_back(c);
		}
		if (um[c] > max_num) max_num = um[c];
	}

	int cnt = 0;
	
	for (auto c : v)
	{
		if (um[c] < max_num) continue;
		cnt++;
		ans = c;
	}

	if (cnt >=2) cout << '?';
	else {
		cout << ans;
	}

	return 0;
}
