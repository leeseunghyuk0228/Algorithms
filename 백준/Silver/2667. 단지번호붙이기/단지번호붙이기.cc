#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int MAP[25][25], visited[25][25], apart = 0,n;

vector<int>res;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			MAP[i][j] = s[j] - '0';
	}
	
}

void bfs(int y, int x)
{
	vector<int> temp;
	temp.push_back(1);

	queue<pair<int, int>> q;
	q.push({ y,x });
	
	int ydir[] = { -1,1,0,0 };
	int xdir[] = { 0,0,-1,1 };

	visited[y][x] = 1;

	while (!q.empty())
	{
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = nowy + ydir[i];
			int nx = nowx + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
			if (!MAP[ny][nx])continue;
			if (visited[ny][nx])continue;
			
			visited[ny][nx] = 1;
			q.push({ ny,nx });
			temp.push_back(1);
		}
	}


	if (temp.size()) {
		res.push_back(temp.size());
		apart++;
	}
	

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (MAP[i][j] && !visited[i][j])bfs(i, j);

	cout << apart << '\n';

	sort(res.begin(), res.end());

	for (int r : res) cout << r << '\n';

}