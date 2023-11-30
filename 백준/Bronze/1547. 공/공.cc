#include <iostream>
#define swap(a, b) {int tmp=a; a=b; b=tmp;}
using namespace std;

int N,cups[4];
int DAT[4];

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> N ;
	for (int i = 1; i <= 3; i++)cups[i] = DAT[i] = i;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		if (x == 0 || y == 0)
		{
			cups[1] = -1;
			break;
		}
		swap(cups[DAT[x]], cups[DAT[y]]);
		swap(DAT[x], DAT[y]);
	}
	cout << cups[1];

}
