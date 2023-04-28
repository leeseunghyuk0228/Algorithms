#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

vector<int> path;
int N, games[50][10], visited[10], res = -21e8, base[3];

int gobase(int ta) {
	int temp = 0;
	if (ta == 1) {
		temp += base[2];
		base[2] = base[1];
		base[1] = base[0];
		base[0] = 1;
	}
	else if (ta == 2) {
		temp += base[2];
		temp += base[1];
		base[2] = base[0];
		base[1] = 1;
		base[0] = 0;
	}
	else if (ta == 3) {
		for (int i = 0; i < 3; i++) {
			temp += base[i];
			base[i] = 0;
		}
		base[2] = 1;
	}
	else {
		temp++;
		for (int i = 0; i < 3; i++) {
			temp += base[i];
			base[i] = 0;
		}
	}
	return temp;
}

int Play() {
	int idx = 0, score = 0;
	

	for (int inn = 0; inn < N; inn++) {
		memset(base, 0, sizeof(base));

		int outcnt = 0;
		int now;

		while (1) {
			now = path[idx] ;
			if (now == 4)now = 1;
			else if (now == 1)now = 4;
			if (games[inn][now] == 0)outcnt++;
			else score += gobase(games[inn][now]);

			idx++;
			if (idx > 8) {
				idx = 0;
			}
			if (outcnt == 3) {
				break;
			}
		}
		
	}

	return score;
}

void func(int level) {
	if (level == 10) {
		int Score = Play();
		if (Score > res) {
			int cursize = path.size();
			res = Score;
		}

		return;
	}

	if (level == 4) {
		visited[4] = 1;
		path.push_back(4);
		func(level + 1);
		path.pop_back();
	}

	else {
		for (int i = 1; i <= 9; i++) {
			if (visited[i])continue;
			path.push_back(i);
			visited[i] = 1;

			func(level + 1);

			visited[i] = 0;
			path.pop_back();
		}
	}

}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < 10; j++) {
			scanf("%d", &games[i][j]);
		}
	}

	func(1);

	printf("%d", res);

}