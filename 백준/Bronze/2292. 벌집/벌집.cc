#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int num;
    int t, limit, res;

    t = limit = res = 1;

    cin >> num;

    while (num > limit)
    {
        limit += 6 * t++;
        res++;
    }

    cout << res;
    return 0;
}
