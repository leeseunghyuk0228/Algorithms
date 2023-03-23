#include <iostream>
#include <vector>
using namespace std;
struct coord { int y, x; };
vector<coord>v;

int MAP[101][101], N, cnt = 0;
int y, x, d, g;
int basey, basex;
int ydir[] = { 0,-1,0,1 };
int xdir[] = { 1,0,-1,0 };

int checky[] = { 0,1,1};
int checkx[] = { 1,0,1 };


void solution() {
	int cursize = v.size();
	cursize--;
	basey = v[cursize].y;
	basex = v[cursize].x;
	
	for (int i = cursize-1; i >=0; i--) {
		coord now = v[i];
		int ny, nx;
		ny = basey - (basex - now.x);
		nx = basex + (basey - now.y);
		MAP[ny][nx] = 1;
		v.push_back({ ny,nx });
	}
	
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y >> d >> g;
		v.clear();
		MAP[y][x] = 1;
		MAP[y + ydir[d]][x + xdir[d]] = 1;
		v.push_back({ y, x });
		v.push_back({ y+ydir[d],x+xdir[d]});
		if(g) for (int i = 0; i < g; i++) solution();
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (MAP[i][j] == 1) {
				int flag = 0;
				for (int k = 0; k < 3; k++)
				{
					if (MAP[i + checky[k]][j + checkx[k]] != 1) {
						flag = 1; break;
					}
				}
					
				if (flag == 0)cnt++;
			}
		}
	}
	cout << cnt;
}
