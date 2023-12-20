#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int ans = 0;
	int n; 
	string tmp;
	cin >> n;
	cin >> tmp;
	for (auto c : tmp)ans += c-'0';
	cout << ans << '\n';
	return 0;
}
