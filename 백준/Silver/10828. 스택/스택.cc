#include <iostream>
#include <stack>

using namespace std;

int N;
stack<int> st;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		if (s == "push")
		{
			int n; cin >> n;
			st.push(n);
		}
		else if (s == "pop")
		{
			if (st.empty())cout << -1 << "\n";
			else {
				cout << st.top()<<'\n';
				st.pop();
			}
		}
		else if (s == "size")
		{
			cout << st.size()<<"\n";
		}
		else if (s == "empty")
		{
			if (st.empty())cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s == "top")
		{
			if (st.empty())cout << -1 << "\n";
			else cout << st.top() << '\n';
			
		}
	}

}