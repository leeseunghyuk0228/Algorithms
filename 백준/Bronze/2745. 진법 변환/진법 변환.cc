#include <iostream>
using namespace std;

string num;
int B;
long long res = 0;

int POW(int a, int b)
{
	int temp = 1;
	while (b--)
		temp *= a;
	return temp;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> num >> B;

	for (int i = num.length() - 1; i >= 0; i--)
	{
		int l = num.length() - i - 1;
		if (num[i] >= 'A' && num[i] <= 'Z') res += (POW(B, l) * (num[i] - 55));
		else res += POW(B,l) * (num[i]-'0');
		
	}
	cout << res;
	
	return 0;
}