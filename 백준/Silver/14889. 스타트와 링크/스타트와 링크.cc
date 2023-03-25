#include <iostream>
using namespace std;
int checked[20], N, MAP[20][20], res = 21e8;
void calc() {
    int score1 = 0, score2 = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++) cnt += checked[i];
    if (cnt != N / 2)return;

    for(int i=0;i<N;i++){
        for (int j = 0; j < N; j++) {
            if (i == j)continue;
            if (!checked[i] && !checked[j])
                score1 += MAP[i][j] + MAP[j][i];
            if (checked[i] && checked[j])
                score2 += MAP[i][j] + MAP[j][i];
        }
    }
    int temp = abs(score1 - score2)/2;
    if (temp < res)res = temp;
}


void dfs(int level, int cnt) {
    
    if (cnt == N / 2) {
        calc();
        return;
    }
    if (level&&!checked[0])return;
    if (level == N)return;

    checked[level] = 1;
    dfs(level + 1, cnt + 1);
    checked[level] = 0;

    dfs(level + 1, cnt);
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> MAP[i][j];
    dfs(0, 0);
    cout << res;
}