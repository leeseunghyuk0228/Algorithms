#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int flag;
	string s;

	while (1)
	{
		getline(cin, s);
		if (s == ".")break;
		stack<int> st;
		flag = 0;

		for (int i=0;i<s.length();i++)
		{
			char c = s[i];

			if (c == ' ')continue;
			if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')continue;

			switch (c)
			{
			case '(':
				st.push(1);
				break;
			case '[':
				st.push(2);
				break;
			case ')':
				if (!st.size()|| st.top() != 1) { flag = 1; break; }
				else st.pop();
				break;
			case ']':
				if (!st.size()|| st.top() != 2) { flag = 1; break; }
				else st.pop();
				break;
			}
		}
		
		if (st.size())flag =1;
		if (flag)cout << "no\n";
		else cout << "yes\n";
	}
}