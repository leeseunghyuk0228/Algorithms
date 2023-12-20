#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;

	for (int i = 0; i <= 25; i++)
	{
		int idx = s.find(char(i + 'a'));
		cout << idx << " ";
	}

	return 0;
}
