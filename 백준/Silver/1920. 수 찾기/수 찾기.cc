#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
long long arr[100000],arr2[100000];

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> M;
}

void search(long long value)
{
	int low = 0, high = N - 1, mid = N / 2;

	while (low <= high)
	{
		if (value < arr[mid])
		{
			high = mid - 1;
			mid = (low + high) / 2;
		}
		else if (value > arr[mid]) 
		{
			low = mid + 1;
			mid = (low + high) / 2;
		}
		else if (value == arr[mid])
		{
			cout << 1 << '\n';
			return;
		}
	}

	cout << 0 << '\n';
	return;

}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
	input();
	sort(arr, arr + N);
	
	for (int i = 0; i < M; i++)
	{
		long long temp;
		cin >> temp;
		search(temp);
	}
}
