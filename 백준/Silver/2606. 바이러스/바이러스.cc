#include <iostream>
using namespace std;

typedef struct st {
	int number;
	struct st* next;
}Node;

Node head[101];
Node pool[101 * 101];

int queue[101 * 101];
int visited[101];
int pcnt, ans;

void Connect(int from, int to) {
	Node* nd = &pool[pcnt++];
	nd->number = to;

	nd->next = head[from].next;
	head[from].next = nd;
}

void Check()
{
	int now;
	
	int write_idx,read_index;
	write_idx = read_index = 0;

	// 1부터 감염됨
	// queue는 확인할 숫자들을 넣는 배열
	queue[write_idx++] = 1;
	visited[1] = 1;

	// 읽을 인덱스가 더 커진다 = 더 볼게 없다
	while (write_idx > read_index)
	{
		// 이번에 볼 숫자
		now = queue[read_index++];
		 
		// 다음 주소값이 NULL이 아닐 때 까지
		for (Node* p = head[now].next; p; p = p->next)
		{
			// 이미 나왔던 숫자가 아니라면
			if (visited[p->number] == 0)
			{
				visited[p->number] = 1;
				ans++;
				queue[write_idx++] = p->number;
			}
		}
	}
}

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		Connect(from, to);
		Connect(to, from);
	}
	Check();
	
	cout << ans;
	
}