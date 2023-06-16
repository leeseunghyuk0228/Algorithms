#include <iostream>

using namespace std;
struct Node {
	Node* next;
	Node* prev;
	int data;
};

Node* init(Node* tmp,int n) {
	tmp = new Node();
	tmp->prev = NULL;
	tmp->next = NULL;
	tmp->data = n;
	return tmp;
}

Node* create(Node* head, int data) {
	if (head == NULL) { // 첫 생성
		head = init(head,0);
		head->data = data;
		head->next = head; // 내 다음은 나고
		head->prev = head; // 내 이전도 나다
		return head;
	}

	// 마지막 노드는 헤드의 다음?
	Node* last_node = head->prev;
	Node* new_node = NULL;
	new_node = init(new_node,data);

	last_node->next = new_node;
	new_node->prev = last_node;
	new_node->next = head;
	head->prev = new_node;

	return head;

}

void insert(Node* head) {
	int x, y, s;
	cin >> x >> y;
	Node* target = head;
	for (int i = 0; i < x; i++)target = target->next;

	for (int i = 0; i < y; i++) {
		cin >> s;
		Node* new_node = NULL;
		new_node = init(new_node,s);

		target->next->prev = new_node;
		new_node->next = target->next;
		target->next = new_node;

		new_node->prev = target;
		target = new_node;
	}
}

void Delete(Node* head) {
	int x, y;
	cin >> x >> y;

	Node* target = head;
	for (int i = 0; i < x; i++) target = target->next;
	for (int i = 0; i < y; i++) {
		target->next = target->next->next;
		target->next->next->prev = target;
	}
}

void Print(Node* head,int i) {
	cout << "#" << i<<" ";
	Node* ptr = head->next;
	for(int i=0;i<10;i++){
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout <<"\n";

}

int main() {
	
	for (int t = 1; t<= 10; t++) {
		Node* list = NULL;
		int enLen, cmdLen;

		// 원본 리스트 만들기
		cin >> enLen;
		for (int j= 0;j < enLen; j++) {
			int num; cin >> num;
			list = create(list, num);
		}

		// 명령어 받고 수행
		cin >> cmdLen;

		for (int k = 0; k < cmdLen; k++) {
			char cmd;
			cin >> cmd;
			if (cmd == 'I')insert(list);
			else if (cmd == 'D')Delete(list);
			else if (cmd == 'A') {
				int y, n;
				cin >> y;
				for (int cur = 0; cur < y; cur++) {
					cin >> n;
					create(list,n);
				}
			}
			
		}
		Print(list, t);
	}
	return 0;

}

/*
10
1 2 3 4 5 6 7 8 9 10
5
I
1 2 22 22
D
3 1
A
1 7 
D
5 1
D
5 1
*/