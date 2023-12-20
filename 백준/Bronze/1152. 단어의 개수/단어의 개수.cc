#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split(const string& s, char seperator)
{
	vector<string> tokens;
	istringstream tokenStream(s);
	string token;

	while (getline(tokenStream, token, seperator))
		if(token!="")
			tokens.push_back(token);

	return tokens;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int res = 0;
	string s;
	getline(cin, s);
	vector<string> words = split(s, ' ');

	cout << words.size();
	return 0;
}
