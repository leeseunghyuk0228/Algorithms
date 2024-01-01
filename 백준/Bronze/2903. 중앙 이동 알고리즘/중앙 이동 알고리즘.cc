#include <iostream>
using namespace std;

int points[16] = { 2, };

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) points[i] = points[i - 1] - 1 + points[i - 1];
    cout << points[n] * points[n];
    return 0;
}
