#include <iostream>
#include <stack>
#include <vector>
#define MAX(a,b) ((a>b)?a:b)
using namespace std;

int num=1;
stack<int> st;
vector<char> v;

void POP()
{
    st.pop();
    v.push_back('-');
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);cout.tie(0);
    int n; cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int temp; cin >> temp;
        if (num <= temp)
        {
            while (num <= temp)
            {
                st.push(num++);
                v.push_back('+');
            }
            POP();
        }
        else if (st.size() && st.top() == temp) POP();
        else if (st.size() && st.top() > temp)
        {
            cout << "NO\n";
            return 0;
        }
    }
    for (auto c : v)
        cout << c << '\n';
    return 0;
}