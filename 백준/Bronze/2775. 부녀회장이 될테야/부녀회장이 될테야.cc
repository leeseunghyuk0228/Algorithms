#include <iostream>
using namespace std;

int MAP[15][15];

int main() {
	for (int i = 1; i <= 14; i++)MAP[0][i] = i;
	for (int i = 1; i <= 14; i++)MAP[i][1] = 1;
    
	for (int i = 1; i <= 14; i++)
		for (int j = 2; j <= 14; j++) 
            MAP[i][j] = MAP[i][j - 1] + MAP[i-1][j];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int d, h;
		cin >> d >> h;
		cout << MAP[d][h] << '\n';
	}
    return 0;
}
