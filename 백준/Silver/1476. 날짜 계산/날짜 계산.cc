#include <iostream>
using namespace std;

int main() {
	int E, S, M;
	cin >> E >> S >> M;
	int start = 1;
	while (1) {
		if ((start - E) % 15 == 0 && (start - S) % 28 == 0 && (start - M) % 19 == 0) break;
		start++;
	}
	cout << start;
}