#include <iostream>
using namespace std;

int dice[25],temp_dice[25];
int rotate_index[6][8] = { {3,4,17,19,10,9,16,14},
						  {4,2,21,23,10,12,6,8},
						  {1,3,5,7,9,11,24,22},
						  {13,14,22,21,17,18,5,6},
						  {20,18,2,1,13,15,11,12},
						  {7,8,19,20,23,24,15,16} };

void input() {
	for (int i = 1; i < 25; i++)
		cin >> dice[i];
}

void rotate(int idx) {
	int temp1 = temp_dice[rotate_index[idx][6]];
	int temp2 = temp_dice[rotate_index[idx][7]];

	for (int i = 6; i >= 2;i-=2) {
		temp_dice[rotate_index[idx][i]] = temp_dice[rotate_index[idx][i - 2]];
		temp_dice[rotate_index[idx][i + 1]] = temp_dice[rotate_index[idx][i - 1]];
	}
	temp_dice[rotate_index[idx][0]] = temp1;
	temp_dice[rotate_index[idx][1]] = temp2;
}

int check() {
	int flag = 0;
	for (int i = 1; i <25; i+=4) {
		int base = temp_dice[i];
		for (int j = i + 1; j < i + 4; j++) {
			if (base != temp_dice[j])return 0;
		}
	}
	return 1;
}

int func() {
	for (int i = 0; i < 6; i++) {
		for (int j = 1; j < 25; j++)temp_dice[j] = dice[j];
		rotate(i);
		if (check()==1)return 1;
		rotate(i);
		rotate(i);
		if (check()==1)return 1;
	}
	return 0;
}	

int main() {
	input();
	int res = func();
	cout << res;

}