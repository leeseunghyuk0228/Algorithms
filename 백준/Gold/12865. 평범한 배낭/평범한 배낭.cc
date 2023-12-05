#include <iostream>
#define MAX(a,b)((a>b)?a:b)
using namespace std;

struct Product
{
	int weights, value;
}products[101];

int N, max_weight, now_weight,dp[101][100001];

void input()
{
	cin >> N >> max_weight;
	for (int i = 1; i <= N; i++)
		cin >> products[i].weights >> products[i].value;
}

int main()
{

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();

	for (int w = 1; w <= max_weight; w++)
	{
		for (int p = 1; p <= N; p++)
		{
			if (products[p].weights > w)dp[p][w] = dp[p - 1][w];
			else
			{
				int cmp1 = dp[p - 1][w - products[p].weights] + products[p].value;
				int cmp2 = dp[p - 1][w];
				dp[p][w] = MAX(cmp1,cmp2);
			}

		}
	}

	cout << dp[N][max_weight];

}

