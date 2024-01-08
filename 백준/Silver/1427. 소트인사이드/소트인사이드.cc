#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	vector<char> v;

	cin >> s;

	for (char c : s) v.push_back(c);

	sort(v.begin(), v.end());

	int cursize = v.size();
	for (int i = cursize - 1; i >= 0; i--)cout << v[i];


	return 0;
	
}