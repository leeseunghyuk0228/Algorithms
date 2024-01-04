#include <iostream>
#include <string>
using namespace std;
 

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
    string alphabet[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    string s;
    
    cin >> s;    
    
    for(int i=0; i<8; i++){
        while(1){
            if(s.find(alphabet[i]) != -1){
                s.replace(s.find(alphabet[i]), alphabet[i].length(), "#");
            }else break;
        }
    }
    
    cout<<s.length();
    
    return 0;
}
