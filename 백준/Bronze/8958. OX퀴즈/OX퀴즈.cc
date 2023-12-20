#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	string s;
	
	cin >> T;

	while (T--)
	{
		cin >> s;
		int res = 0;
		int con_o = 1;
		for (auto c : s)
			if (c == 'O')res = res + con_o++;
			else con_o = 1;
		cout << res << '\n';

	}

	return 0;
}
