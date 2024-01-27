#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x, y;
    int count;

    cin >> n;
    vector<pair<int, int> > v;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back(pair<int, int>(x, y));
    }

    for (int j = 0; j < n; j++) {
        count = 1;
        for (int k = 0; k < n; k++) {
            if (v[j].first < v[k].first && v[j].second < v[k].second) {
                count++;
            }
        }
        cout << count << endl;
    }
}
