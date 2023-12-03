#include <iostream>
#include <algorithm>
using namespace std;

int N,M,basket[101];

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)basket[i] = i;
	for (int i = 0; i < M; i++)
	{
		int low, high, mid;
		cin >> low >> high >> mid;
		rotate(basket+low, basket+mid, basket+high+1);
		
	}
	for (int i = 1; i <= N; i++)cout << basket[i] << " ";
	cout << '\n';
	

}