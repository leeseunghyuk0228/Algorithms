#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, num;
vector<int> v[100];
int visited[100][100];

void bfs(int start)
{
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int to : v[now])
        {
            if (!visited[start][to])
            {
                visited[start][to] = 1;
                q.push(to);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> num;
            if (num) v[i].push_back(j);
        }
    }

    for (int i = 0; i < N; i++)
        bfs(i);

    // 전체 visited 배열을 한 번에 출력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << visited[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
