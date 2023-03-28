#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;
struct tree { int y, x, age; 
	bool operator < (tree next) {
		if (age < next.age) return true;
		if (age > next.age) return false;
		return false;
	};
};
deque <tree> trees;
int A[11][11], MAP[11][11], N, M, K;

void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
		{
			cin >> A[i][j];
			MAP[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		int y, x, age;
		cin >> y >> x >> age;
		trees.push_back({y,x,age});
	}
}

void seasons() {
	int ydir[] = { -1,-1,-1,0,0,1,1,1 };
	int xdir[] = { -1,0,1,-1,1,-1,0,1 };
	int temp[11][11] = { 0, };
	
	int cursize = trees.size();

	queue<tree>addq;

	for (int cur = 0; cur < cursize; cur++) {
		tree now = trees.front(); trees.pop_front();

		if (MAP[now.y][now.x] < now.age)
		{
			temp[now.y][now.x] += now.age / 2; continue;
		}

		else {
			MAP[now.y][now.x] -= now.age;
			now.age++;
			trees.push_back( now );
			if (now.age % 5 == 0)
				addq.push({ now });

		}
	}

	while (!addq.empty()) {
		tree now = addq.front(); addq.pop();
		for (int dir = 0; dir < 8; dir++) {
			int ny = now.y + ydir[dir];
			int nx = now.x + xdir[dir];
			if (ny<1 || nx<1 || ny>N || nx>N)continue;
			trees.push_front({ ny,nx,1 });
		}
	}

	// 겨울
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			MAP[i][j] += A[i][j] + temp[i][j];

}

int main() {

	input();
	sort(trees.begin(), trees.end());
	for (int i = 0; i < K; i++) seasons();
	cout << trees.size();
}

/*
10 1 1000
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
1 1 1
*/