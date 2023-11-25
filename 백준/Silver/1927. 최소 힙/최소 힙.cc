#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

using namespace std;
priority_queue<long long, vector<long long> , greater<long long>> q;

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		long long num;
		scanf("%d", &num);
		if (num == 0)
		{
			if (q.empty()) printf("0\n");
			else 
			{
				printf("%d\n", q.top()); q.pop();
			}
		}
		else
		{
			q.push(num);
		}
	}
}