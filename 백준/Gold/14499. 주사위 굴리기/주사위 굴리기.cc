#include <iostream>
#include <vector>
using namespace std;
int N, M, MAP[20][20], x, y, K;
int dice[6], lower = 0;
int xdir[] = { 0,0,0,-1,1 };
int ydir[] = { 0,1,-1,0,0 };
int rolling[5][2][4] = {
    {{0,0,0,0,},
    {0,0,0,0}},
    // 1번(동쪽, 우)
    {{3,0,2,5},
    {0,2,5,3}},
    // 2번(서쪽, 좌)
    {{0,2,3,5},
    {3,0,5,2}},
    // 3번(북쪽, 상)
    {{0,4,5,1},
    {1,0,4,5}},
    // 4번(남쪽, 하)
    {{0,4,5,1},
    {4,5,1,0}} };

void solution(int dir) {
    int nx = x + xdir[dir];
    int ny = y + ydir[dir];
    // 범위 초과의 경우 아무것도 하지 않음
    if (nx < 0 || ny < 0 || nx >= N || ny >= M) return;
    // dir 방향으로 일단 굴린 상태로 주사위 상태 변경 0번이 윗면, 5번 바닥
    vector<int>v;
    for (int i = 0; i < 4; i++)
        v.push_back(dice[rolling[dir][0][i]]);
    for (int i = 0; i < 4; i++)
        dice[rolling[dir][1][i]] = v[i];
    // 바닥이 0 -> 주사위 수 바닥을 0으로
    if (MAP[nx][ny] == 0) {
        MAP[nx][ny] = dice[5];
    }
    // 바닥이 0이 아님 -> 바닥 수를 주사위 바닥으로, 바닥은 0
    else {
        dice[5] = MAP[nx][ny];
        MAP[nx][ny] = 0;
    }

    cout << dice[0] << '\n';
    x = nx;
    y = ny;
}

int main() {
    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> MAP[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        int n;
        cin >> n;
        solution(n);
    }
}