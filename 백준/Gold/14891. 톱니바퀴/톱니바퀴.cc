#include <iostream>
#include <vector>
using namespace std;


// 정수 시계, 음수 반시계
// 0번부터 주어짐
string arr[4];

void rotate(int idx, int dir) {
	if (dir==1) {
		char temp = arr[idx][7];
		for (int i = 6; i >=0; i--)
			arr[idx][i+1] = arr[idx][i];
		arr[idx][0] = temp;
	}

	else {
		char temp = arr[idx][0];
		for (int i = 0; i < 7; i++) {
			arr[idx][i] = arr[idx][i+1];
		}
		arr[idx][7] = temp;
	}
	
}

void check(int idx, int dir) {
	vector <int> v;

	for (int i = idx; i < 3; i++)
	{
		if (arr[i][2] != arr[i + 1][6]) v.push_back(i + 1);
		else break;
	}
	for (int i = idx; i > 0; i--){
		if (arr[i][6] != arr[i - 1][2]) v.push_back(i - 1);
		else break;
	}

	v.push_back(idx);
	int cursize = v.size();

	for (int i = 0; i < cursize; i++) {
		if (abs(v[i] - idx)%2 == 1)
			rotate(v[i], -dir);
		else
			rotate(v[i], dir);
	}
}

int main() {
	for (int i = 0; i < 4; i++) cin >> arr[i];

	int n;cin >> n;

	for (int i = 0; i < n; i++) {
		int idx, dir;
		cin >> idx>>dir;
		check(idx-1, dir);
	}
	
	int score[4] = { 1,2,4,8 };
	int sum = 0;

	for (int i = 0; i < 4; i++)
		if(arr[i][0]=='1')sum += score[i];

	cout << sum;
}