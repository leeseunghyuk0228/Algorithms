#include <iostream>
using namespace std;
int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i <=n; i*=10) cnt += (n - i + 1);
	cout << cnt;
}