#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int n, dat[8001];
int mode_cnt;
double SUM = 0;
vector<int> v;

void get_mean() {
    int ans = round(SUM / n);
    cout << ans <<'\n';
}

void get_median() {
    cout << v[n / 2] - 4000<<'\n';
}

void get_mode() {
    int flag = 0;
    int ans=0;
    for (int i = 0; i < 8001; i++) {
        if (dat[i] == mode_cnt) {
            ans = i;
            flag++;
        }
        if (flag == 2)break;
    }
    cout << ans-4000 << '\n';
}

void get_minmax() {
    
    cout << v[n-1] - v[0] << '\n';
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        SUM += a;
        a+=4000;
        dat[a]++;

        if (dat[a] > mode_cnt) mode_cnt = dat[a];
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    get_mean();
    get_median();
    get_mode();
    get_minmax();
}