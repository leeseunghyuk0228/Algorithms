#include <iostream>
using namespace std;

int arr[10000];
int pos_left, pos_right;
// 1 2

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		string cmd;
		cin >> cmd;
		if (cmd == "push")
		{
			cin >> num;
			arr[pos_right++] = num;
		}
		else if (cmd == "pop"||cmd=="front")
		{
			if (pos_right - pos_left == 0)cout << -1 << '\n';
			else if(cmd=="pop") cout << arr[pos_left++] << '\n';
			else cout << arr[pos_left] << '\n';
		}
		else if (cmd == "size")
		{
			cout << pos_right - pos_left << '\n';
		}
		else if (cmd == "empty")
		{
			if (pos_right-pos_left==0)cout << 1 << '\n';
			else cout << "0\n";

		}else if (cmd == "back")
		{
			if (pos_right == 0||pos_right==pos_left)cout << -1 << '\n';
			else  cout << arr[pos_right-1] << '\n';
		}
	}

}
