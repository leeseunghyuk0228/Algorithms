#include <iostream>
#define MAX 91

using namespace std;
long long dp[MAX];
int N;

int main()
{
	// N번째 줄의 1 끝나는 개수 = N-1 줄 0으로 끝나는 이진수
	// N번재 줄의 0 끝나는 개수 = N-1 줄 0으로 끝나는 이진수 + 1로 끝나는 개수
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	cin >> N;
	for (int i = 3; i <= N; i++) dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[N];

}

