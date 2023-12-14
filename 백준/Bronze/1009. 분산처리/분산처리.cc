#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int start = a;
        
        for (int i = 1; i < b; i++)
            start = start * a % 10;

        if (!(start % 10))cout << 10 << '\n';
        else cout << start % 10 << '\n';
    }
    return 0;
}