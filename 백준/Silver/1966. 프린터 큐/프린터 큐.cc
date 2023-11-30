#include <iostream>
#include <queue>
using namespace std;

typedef struct Node
{
    int priority, idx;
}docs;


priority_queue<int> pq;
queue<docs> q;

int T, n, cnt, target;
void input()
{
    cin >> cnt >> target;

    
    for (int i = 0; i < cnt; i++)
    {
        int temp; cin >> temp;
        pq.push(temp);
        q.push({ temp,i });
    }

}

void solution()
{
    int ans = 1;
    while (1)
    {
        while (pq.top() > q.front().priority)
        {
            q.push(q.front()); q.pop();
        }
        if (q.front().idx == target)
        {
            cout << ans << "\n";
            break;
        }
        else {
            ans++;
            pq.pop();
            q.pop();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        input();
        solution();
        pq = priority_queue<int>();
        q = queue<docs>();
    }
}