#include <iostream>
#define swap(a, b) {int tmp=a; a=b; b=tmp;}
using namespace std;

int N,M,basket[101];

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++)basket[i] = i;

	for (int i = 0; i < M; i++)
	{
		int c1, c2, cur;
		cin >> c1 >> c2;
		cur = (c2 - c1+1)/2;
		for (int j = 0; j < cur; j++)
			swap(basket[c1 + j], basket[c2 - j]);
		
	}
	for (int i = 1; i <= N; i++)cout << basket[i] << " ";

}
