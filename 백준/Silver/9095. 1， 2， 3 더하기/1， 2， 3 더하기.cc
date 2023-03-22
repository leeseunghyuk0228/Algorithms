#include <iostream>
using namespace std;
int N, res;
void dfs(int level) {
	if (level > N)return;
	if (level == N) {
		res++;
		return;
	}
	dfs(level + 1);
	dfs(level + 2);
	dfs(level + 3);
}
int main() {
	int cur;
	cin >> cur;
	for (int i = 0; i < cur; i++) {
		cin >> N;
		res = 0;
		dfs(0);
		cout << res<<'\n';
	}
}