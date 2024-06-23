#include <iostream>

int N, K;
long long left = 1;
long long right = 1;
int arr[10001];

int main()
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		std::cin >> arr[i];
		right = right > arr[i] ? right : arr[i];
	}

	int cnt;
	int res = 0;

	while (left <= right)
	{
		cnt = 0;
		long long mid = (left + right) / 2;

		for (int i = 0; i < N; i++)
		{
			cnt += arr[i] / mid;
		}

		if (cnt >= K)
		{
			res = res > mid ? res : mid;
			left = mid + 1;
		}
		else
			right = mid - 1;

	}

	std::cout << res;

}
