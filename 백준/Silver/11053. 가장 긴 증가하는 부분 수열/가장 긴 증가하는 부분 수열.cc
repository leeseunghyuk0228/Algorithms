#include <iostream>
using namespace std;
int N;
int Arr[1010];
int dp[1010];
int MAX(int a, int b) { if (a > b)return a; return b; }
void solution() {
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--)
		{
			if (Arr[i] > Arr[j])
				dp[i] = MAX(dp[i], dp[j] + 1);
		}
		answer = MAX(dp[i], answer);
	}
	cout << answer;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)cin >> Arr[i];
	solution();
	return 0;
}