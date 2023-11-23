#include <stdio.h>
#include <queue>

using namespace std;

int MAP[50][50];
int xdir[] = { 1,0,-1,0 };
int ydir[] = { 0,-1,0,1 };
int xdir2[] = { 1,0,-1,0 };
int ydir2[] = { 0,1,0,-1 };
int upper_idx, lower_idx;
int R, C, T;
queue<int>q;

void input() {
	scanf("%d %d %d", &R, &C, &T);
	int flag = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf("%d", &MAP[i][j]);
			if (MAP[i][j] == -1 && flag == 0)
			{
				upper_idx = i;
				flag++;
			}
			else if (MAP[i][j] == -1 && flag == 1)
				lower_idx = i;
		}
	}
}

void spread() {
	int temp[50][50] = { 0, };

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (MAP[i][j] == -1)continue;
			if (MAP[i][j] == 0)continue;
			int base = MAP[i][j] / 5;
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int ny = i + ydir[k];
				int nx = j + xdir[k];
				if (ny < 0 || nx < 0 || ny >= R || nx >= C)continue;
				if (MAP[ny][nx] == -1)continue;
				temp[ny][nx] += base;
				cnt++;
			}
			if(cnt!=0)
				MAP[i][j] -=( base * cnt);
		}
	}

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			MAP[i][j] += temp[i][j];

}

void upper_air() {
	int sy = upper_idx;
	int sx = 0;
	int flag = 0;
	q.push(0);
	while (1) {
		sy += ydir[flag];
		sx += xdir[flag];
		if (flag == 3 && (sy == upper_idx && sx == 0)) break;
		if (sy < 0 || sx < 0 || sy >= R || sx >= C)
		{
			sy -= ydir[flag];
			sx -= xdir[flag];
			flag++;
		}
		else
			q.push(MAP[sy][sx]);
	}

	sx = 0;
	flag = 0;

	while (!q.empty()) {
		

		sy += ydir[flag];
		sx += xdir[flag];

		if (sy < 0 || sx < 0 || sy >= R || sx >= C)
		{
			sy -= ydir[flag];
			sx -= xdir[flag];
			flag++;
		}
		else 
		{
			int num = q.front(); q.pop();
			if (!q.empty()) MAP[sy][sx] = num;
		}
		
	}
}

void lower_air() {
	int sy = lower_idx;
	int sx = 0;
	int flag = 0;
	q.push(0);
	while (1) {
		sy += ydir2[flag];
		sx += xdir2[flag];
		if (flag == 3 && (sy == lower_idx && sx == 0)) break;
		if (sy < 0 || sx < 0 || sy >= R || sx >= C)
		{
			sy -= ydir2[flag];
			sx -= xdir2[flag];
			flag++;
		}
		else
			q.push(MAP[sy][sx]);
	}

	sx = 0;
	flag = 0;

	while (!q.empty()) {


		sy += ydir2[flag];
		sx += xdir2[flag];

		if (sy < 0 || sx < 0 || sy >= R || sx >= C)
		{
			sy -= ydir2[flag];
			sx -= xdir2[flag];
			flag++;
		}
		else
		{
			int num = q.front(); q.pop();
			if (!q.empty()) MAP[sy][sx] = num;
		}

	}
}

void get_dust_amount() {
	int res = 0;
	for (int i = 0; i < R; i++)for (int j = 0; j < C; j++)res += MAP[i][j];
	printf("%d", res+2);
}

int main() {
	input();
	while (T--)
	{
		spread();
		upper_air();
		lower_air();
	}

	get_dust_amount();
}