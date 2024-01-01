#include <iostream>
using namespace std;

int coins[] = { 25,10,5,1 };

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    
    while (n--)
    {
        int money; cin >> money;

        for (int i = 0; i < 4; i++)
        {
            cout << money / coins[i] << " ";
            money -= money / coins[i] * coins[i];
        }
        cout << '\n';
    }

    return 0;
}
