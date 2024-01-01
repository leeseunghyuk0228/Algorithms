#include <iostream>
#include <stack>
using namespace std;

int B;
long long num;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    stack<char> result; // 나머지를 저장할 스택

    cin >> num >> B;

    while (num)
    {
        int remainder = num % B;
        char digit = (remainder >= 10) ? (char)(remainder - 10 + 'A') : (char)(remainder + '0');

        result.push(digit);
        num /= B;
    }

    while (!result.empty())
    {
        cout << result.top();
        result.pop();
    }

    return 0;
}
