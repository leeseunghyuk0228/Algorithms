#include <iostream>
#define MAX(a,b) ((a>b)?a:b)
using namespace std;

int n, arr[1001], LIS_L[1001], LIS_R[1001],ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        LIS_L[i] = LIS_R[i] = 1;
    }

    for (int i =1; i <= n; i++) // 나를
        for (int j = 1; j < i; j++) // 내 전거 전부랑 비교한다.
            if (arr[i] > arr[j]) LIS_L[i] = MAX(LIS_L[i], LIS_L[j]+1);

    for (int i = n; i >=1; i--) // 나를
        for (int j = n; j >i; j--) // 오른쪽에서 부터 비교한다.
            if (arr[i] > arr[j]) LIS_R[i] = MAX(LIS_R[i], LIS_R[j]+1);


    for (int i = 1; i <= n; i++)
        ans = MAX(ans, LIS_L[i] + LIS_R[i]);

    cout << ans - 1;
    return 0;
}