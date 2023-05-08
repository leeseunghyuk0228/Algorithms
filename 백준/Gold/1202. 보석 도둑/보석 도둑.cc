#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct j {
    int weight, price;
    bool operator < (struct j next) const {
        if (weight < next.weight) return true;
        if (weight > next.weight) return false;
        return false;
    }
};
vector <j> jews;

int bags[300000];
int N, M, idx = 0;
long long res = 0;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int w, p;
        cin >> w >> p;
        jews.push_back({ w,p });
    }

    for (int i = 0; i < M; i++)cin >> bags[i];

    sort(bags, bags+M);
    sort(jews.begin(), jews.end());

}

int main() {

    input();

    priority_queue<int> pq;

    for (int i = 0; i < M; i++) {
        for (int j = idx; j < N; j++) {
            if (jews[j].weight > bags[i])break;
            idx++; pq.push(jews[j].price);
        }
        if (pq.size())
        {
            res += pq.top(); pq.pop();
        }
    }

    cout << res;
    return 0;

}