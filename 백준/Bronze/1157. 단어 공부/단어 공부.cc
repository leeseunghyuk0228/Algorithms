#include <iostream>
#include <sstream>
using namespace std;

string s;
int A[26];
int max_num;
int max_pos;
int max_cnt;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) A[s[i] >= 97 ? (s[i] - 97) : (s[i] - 65)]++;
    for (int i = 0; i < 26; i++) {
        if (A[i] > max_num) {
            max_num = A[i];
            max_pos = i;
            max_cnt = 1;
        }
        else if (A[i] ==max_num)
        {
            max_cnt++;
        }

    }

    if (max_cnt == 1) {
        cout << char(65 + max_pos);
    }
    else cout << "?";

    return 0;
}