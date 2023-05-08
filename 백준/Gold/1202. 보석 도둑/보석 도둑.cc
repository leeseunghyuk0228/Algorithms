#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

pair<int, int> jews[300000];
int bags[300000];
int N, M, idx = 0;
long long res = 0;

void input() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)scanf("%d %d", &jews[i].first, &jews[i].second);
    for (int i = 0; i < M; i++)scanf("%d", &bags[i]);
    sort(jews, jews + N);
    sort(bags, bags+M);
}

int main() {

    input();

    priority_queue<int> pq;
    for (int i = 0; i < M; i++) {
        for (int j = idx; j < N; j++) {
            if (jews[j].first > bags[i])break;
            idx++; pq.push(jews[j].second);
        }
        if (pq.size())
        {
            res += pq.top(); pq.pop();
        }
    }

    printf("%lld", res);
    return 0;

}