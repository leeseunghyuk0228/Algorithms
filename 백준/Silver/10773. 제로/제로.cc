#include <iostream>
using namespace std;

int arr[100000];
int pos = 0;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int res=0,n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int number; cin >> number;
		if (number == 0)pos--;
		else arr[pos++] = number;
	}

	for (int i = 0; i < pos; i++)
		res += arr[i];
	cout << res;

}
