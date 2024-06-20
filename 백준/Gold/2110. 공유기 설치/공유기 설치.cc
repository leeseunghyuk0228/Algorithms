#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
int arr[200000];

int main()
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> N >> M;

	
	for (int i = 0; i < N; i++)std::cin >> arr[i];

	std::sort(arr, arr + N);

	int left = 1; // 최소 거리
	int right = arr[N - 1] - arr[0]; // 최대 거리

	int mid, cnt;
	int res = 0;
	int temp;

	while (left <= right)
	{
		cnt = 1;
		mid = (left + right) / 2;
		temp = arr[0];

		for (int i = 1; i < N; i++)
		{
			if (arr[i] - temp >= mid)
			{
				cnt++;
				temp = arr[i];
			}
		}

		if (cnt >= M)
		{
			res = std::max(res, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	std::cout << res;
	return 0;
}
