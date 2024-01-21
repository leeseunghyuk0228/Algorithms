#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, M;
	string s;
	map<int, string> um;
	map<string,int> um2;

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> s;
		um[i] = s;
		um2[s] = i;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> s;
		if((s[0]>='a'&&s[0]<='z') || (s[0] >= 'A' && s[0] <= 'Z')) cout<< um2[s] << '\n';
		else cout << um[stoi(s)]<<'\n';
		
	}

	return 0;

}