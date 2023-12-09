#include <iostream>
using namespace std;

int  N, M, cnt = 0, ans = 21e8, coll[] = { 1,0,3,2 };
int ydir[] = { -1,1,0,0 };
int xdir[] = { 0,0,-1,1 };

struct coord {
    int y, x, Enter;
};
coord RED, BLUE;
string MAP[10];

// 입력 함수
void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> MAP[i];
        for (int j = 0; j < M; j++) {
            if (MAP[i][j] == 'R') {
                RED.y = i;
                RED.x = j;
                RED.Enter = 0;
            }
            if (MAP[i][j] == 'B') {
                BLUE.y = i;
                BLUE.x = j;
                BLUE.Enter = 0;
            }
        }
    }
}

// dfs
void dfs(int level, int dir) {
    // 기저조건


    if (cnt > ans || level > 10 || cnt>10) return;

    for (int i = 0; i < 4; i++) {
        coord tempRED = RED;
        coord tempBLUE = BLUE;
        string temp[10];

        for (int j = 0; j < N; j++) temp[j] = MAP[j];

        while (1)
            // 빨간공과 파란공이 다 멈출 때 까지 i 방향으로 돌려본다
        {
            int nry = RED.y + ydir[i];
            int nrx = RED.x + xdir[i];
            // 구멍에 빠졌다
            if (MAP[nry][nrx] == 'O') {
                MAP[RED.y][RED.x] = '.';
                RED.Enter = 1;
            }
            // 갈 수 있다
            else if (MAP[nry][nrx] == '.' && RED.Enter==0) {
                MAP[RED.y][RED.x] = '.';
                MAP[nry][nrx] = 'R';
                RED.y = nry;
                RED.x = nrx;
            }

            int nby = BLUE.y + ydir[i];
            int nbx = BLUE.x + xdir[i];

            if (MAP[nby][nbx] == 'O') {
                for (int i = 0; i < N; i++) MAP[i] = temp[i];
                RED = tempRED;
                BLUE = tempBLUE;
                break;
            }

            else if (MAP[nby][nbx] == '.') {
                MAP[BLUE.y][BLUE.x] = '.';
                MAP[nby][nbx] = 'B';
                BLUE.y = nby;
                BLUE.x = nbx;
            }

            // 둘 다 멈췄다면 그만 돌아라
            if ((MAP[nry][nrx] == '#' && MAP[nby][nbx] == '#') ||
                (MAP[nry][nrx] == '#' && MAP[nby][nbx] == 'R') ||
                (MAP[nry][nrx] == 'B' && MAP[nby][nbx] == '#'))
                break;

            if (RED.Enter == 1 && MAP[nby][nbx] == '#') {
                for (int i = 0; i < N; i++) MAP[i] = temp[i];
                RED = tempRED;
                BLUE = tempBLUE;
                if (ans > cnt)
                    ans = cnt + 1;
                break;
            }
        };

        if (tempRED.y == RED.y && tempRED.x == RED.x && 
            tempBLUE.y == BLUE.y && tempBLUE.x == BLUE.x)continue;


        cnt++;
        dfs(level + 1, i);
        cnt--;

        for (int i = 0; i < N; i++) MAP[i] = temp[i];
        RED = tempRED;
        BLUE = tempBLUE;
    }

    return;
}

int main() {
    input();
    string backup[10];
    for (int i = 0; i < N; i++) backup[i] = MAP[i];
    dfs(0, 0);
    if (ans >10)ans = -1;
    cout << ans;
}