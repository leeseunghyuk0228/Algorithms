#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  string s;
  cin >> s;

  for(int i = 0; i <= s.length() / 2; i++) 
  {
    if(s[i] == s[s.length() - i - 1])continue;
      cout << 0;
      return 0;
  }
  cout << 1;
  return 0;
}