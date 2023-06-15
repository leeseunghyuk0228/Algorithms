#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int a, b;
        cin >> a >> b;
        int N = (1 << a)-1;
        if ((b&N) == N)cout << "#" << tc << " " << "ON\n";
        else cout << "#" << tc << " " << "OFF\n";
    }
    return 0;
}