#include <iostream>
using namespace std;

int N,M,basket[101];

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int low, high, num;
		cin >> low >> high >> num;
		for (int now = low; now <= high; now++)
			basket[now] = num;
	}
	for (int i = 1; i <= N; i++)cout << basket[i] << " ";

}
