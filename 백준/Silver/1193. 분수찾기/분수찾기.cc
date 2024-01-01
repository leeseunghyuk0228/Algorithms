#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int num, t, limit, dir;
    
    t = limit = dir = 1;
    cin >> num;

    while (num > limit)
    {
        limit += ++t;
        dir *= -1;
    }

    if(dir==-1)
        cout << t - (limit - num) << "/" << limit - num+1;
    else
        cout << limit - num + 1 << "/"<< t - (limit - num) ;


    return 0;
}