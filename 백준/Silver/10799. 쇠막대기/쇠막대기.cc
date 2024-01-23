#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<pair<int,int>> st;
vector<pair<int,pair<int,int>>> stick; // 막대개수, 시작점, 끝점

vector<int> raser;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	int now = 0;
	int res = 0;
	cin >> s;

	for (char c : s)
	{
		if (c == '(')st.push({ 1,now });  // ( 괄호일때는 그냥 넣음
		else if (c == ')' && st.top().first == 1) // ) 괄호일 때, (라면 레이저 추가, 쇠막대 추가
		{
			if (now - st.top().second > 1) stick.push_back({ 0,{st.top().second, now} }); //시작과 끝이 1이상이면 막대 추가
			else raser.push_back(now);// 시작과 끝이 1이면 레이저 추가
			st.pop();
		}
		else st.push({ 2,now });// ) 괄호일 때, ) 라면 그냥 그대로 추가
		now++;
	}

	int cursize = stick.size();

	for (auto n : raser)
		for(int i=0;i<cursize;i++)
			if (n > stick[i].second.first && n < stick[i].second.second)
				stick[i].first++;


	for (auto cnt : stick)
		res += cnt.first + 1;

	cout << res;

	return 0;
}
