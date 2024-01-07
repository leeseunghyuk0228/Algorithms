#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	while (1)
	{
		getline(cin, s);
		if (s != "") cout << s<<'\n';
		else break;
	}
	return 0;
	
}