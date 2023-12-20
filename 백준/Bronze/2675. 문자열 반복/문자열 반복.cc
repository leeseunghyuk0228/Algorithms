#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int cur;
		string s;
		string tmp = "";
		cin >> cur >> s;

		for (char c : s)
			for(int i=0;i<cur;i++)
					tmp += c;

		cout << tmp << '\n';
	}

	return 0;
}
