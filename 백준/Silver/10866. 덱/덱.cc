#include <iostream>
#include <deque>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	deque<int> DQ;
	
	while (n--) {
		string cmd;
		cin >> cmd;
		
		if (cmd == "push_front") {
			int x;
			cin >> x;
			DQ.push_front(x);
		} else if (cmd == "push_back") {
			int x;
			cin >> x;
			DQ.push_back(x);
		} else if (cmd == "pop_front") {
			if (DQ.empty()) {
				cout << "-1" << '\n';
			} else {
				cout << DQ.front() << '\n';
				DQ.pop_front();
			}
		} else if (cmd == "pop_back") {
			if (DQ.empty()) {
				cout << "-1" << '\n';
			} else {
				cout << DQ.back() << '\n';
				DQ.pop_back();
			}
		} else if (cmd == "size") {
			cout << DQ.size() << '\n';
		} else if (cmd == "empty") {
			if (DQ.empty()) {
				cout << '1' << '\n';
			} else {
				cout << '0' << '\n';
			}
		} else if (cmd == "front") {
			if (DQ.empty()) {
				cout << "-1" << '\n';
			} else {
				cout << DQ.front() << '\n';
			}
		} else { // cmd == "back"
			if (DQ.empty()) {
				cout << "-1" << '\n';
			} else {
				cout << DQ.back() << '\n';
			}
		}
	}
	
	return 0;
}