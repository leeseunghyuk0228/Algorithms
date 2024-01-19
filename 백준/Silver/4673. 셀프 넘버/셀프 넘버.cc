#include <iostream>
using namespace std;

int arr[10001];

void func(int i)
{
	int next = i;
	while (i!=0)
	{
		next += i % 10;
		i /= 10;
	}
	if (next > 10000)return;

	arr[next] = 1;
	func(next);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 1; i <= 10000; i++)
		if (!arr[i]) func(i);

	for (int i = 1; i <= 10000; i++)
		if (!arr[i])cout << i << '\n';

}