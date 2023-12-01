#include <iostream>
using namespace std;
int N, switches[101], students;
int toggle[2] = { 1,0 };

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> switches[i];
	cin >> students;
}

void male(int idx)
{
	// idx 의 배수
	for (int i = idx; i <= N; i+=idx)
		if (i % idx == 0) switches[i] = toggle[switches[i]];
}

void female(int idx)
{
	int low = idx, high = idx;

	while (1)
	{
		// 둘이 지금 같아
		// 그러니까 범위를 늘려서 한 번 더 보겠다.
		if (switches[low] == switches[high])
			low--; high++;

		// 범위를 초과했다 
		// 둘이 다르다!
		// 현재 범위를 볼 수 없고. 이전 범위가 최대치다
		if (low == 0 || high > N || switches[low]!=switches[high])
		{
			low++; high--;
			break;
		}
	}

	for (int i = low; i <= high; i++) switches[i] = toggle[switches[i]];

}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();

	for (int i = 0; i < students; i++)
	{
		int gender, idx;
		cin >> gender >> idx;
		if (gender == 1) male(idx);
		else if (gender == 2) female(idx);
	}

	for (int i = 1; i <= N; i++)
	{
		cout << switches[i] << " ";
		if (i % 20 == 0)cout << '\n';
	}
}