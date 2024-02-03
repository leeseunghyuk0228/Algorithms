#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	string number = "";
	bool check = false;
	int res = 0;

	cin >> s;

	for (char c:s) {
		if (c == '-' || c == '+') 
		{
			if (check == true) res -= stoi(number);
			else res += stoi(number);
			number = "";
		}

		else number += c;
		if (c == '-')  check = true;
	}

	if (check == true) res -= stoi(number);
	else res += stoi(number);

	cout << res;

	return 0;
}
