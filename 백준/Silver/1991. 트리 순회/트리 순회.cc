#include <iostream>
#include <vector>
using namespace std;

struct node{char left, right;};

int n;
node v[26];

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;
		v[a - 65].left = b;
		v[a - 65].right = c;
	}
}

void preOrder(int now)
{
	cout << char(now + 65);
	if (v[now].left != '.')preOrder(v[now].left-65);
	if (v[now].right != '.')preOrder(v[now].right-65);

}
void inOrder(int now)
{
	
	if (v[now].left != '.')inOrder(v[now].left - 65);
	cout << char(now + 65);
	if (v[now].right != '.')inOrder(v[now].right - 65);

}
void postOrder(int now)
{

	if (v[now].left != '.')postOrder(v[now].left - 65);
	if (v[now].right != '.')postOrder(v[now].right - 65);
	cout << char(now + 65);

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();

	preOrder(0);
	cout << '\n';
	inOrder(0);
	cout << '\n';
	postOrder(0);
}
