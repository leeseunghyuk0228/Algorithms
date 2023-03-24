#include <iostream>
#include <vector>

using namespace std;
struct coord { int y, x; };
int arr[11], sign[4], N, MAX = -21e8, MIN = 21e8;
vector<int> path;

void dfs(int level) {
	if (level == N-1) {
		int sum = arr[0];
		for (int i = 0; i < N - 1;i++)
		{
			if (path[i] == 0) sum += arr[i + 1];
			else if (path[i] == 1) sum -= arr[i + 1];
			else if (path[i] == 2)sum *= arr[i + 1];
			else sum /= arr[i + 1];
		}	
		if (MAX < sum)MAX = sum;
		if (MIN > sum)MIN = sum;

		return;
	}

	for (int i = 0; i < 4; i++) {
		if (!sign[i])continue;
		sign[i]--;
		path.push_back(i);
		dfs(level + 1);
		path.pop_back();
		sign[i]++;
	}


}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> arr[i];
	for (int i = 0; i < 4; i++)cin >> sign[i];
	dfs(0);
	cout << MAX << '\n' << MIN;
}