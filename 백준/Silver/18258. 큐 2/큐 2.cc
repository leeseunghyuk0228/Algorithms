#include <iostream>
#include <queue>

using namespace std;

int main() {

	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> q;
	string command;
	int t, cnt;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> command;
		
		if (command == "push") {
			cin >> cnt;
			q.push(cnt);
		}
		else if (command== "pop") {
			if (q.empty()) {
				cout << "-1" << '\n';
			} else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (command == "front") {
			if (q.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << q.front() << '\n';
			}
		}
		else if (command == "back") {
			if (q.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << q.back() << '\n';
			}
		}
		else if (command == "size")
			cout << q.size() << '\n';
		else if (command == "empty")
			cout << q.empty() << '\n';
		else if (command == "top") {
			if (q.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << q.front() << '\n';
			}
		}
	}
	return 0;
}