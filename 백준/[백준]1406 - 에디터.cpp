#include <iostream>
#include <string>

using namespace std;

struct Node {
	Node * prev, * next;
	char c;
};

Node* cursor = NULL;
Node* front = NULL;

void remove(Node *cursor) {
	Node* lnode = cursor->prev;
	if (lnode->prev != NULL) {
		lnode->prev->next = cursor;
		cursor->prev = lnode->prev;

		cursor = cursor->prev;
		delete(lnode);
	}
	else {
		cursor->prev = NULL;
		front = cursor;
		delete(lnode);
	}
}

void insertleft(Node *editor,char c) {
	if (editor->prev != NULL) {
		Node* lnode = editor->prev;
		Node* one = new Node{ NULL,NULL,NULL };
		lnode->next = one;
		one->prev = lnode;
		one->next = editor;
		one->c = c;
		editor->prev = one;
	}
	else {
		Node* one = new Node{ NULL,NULL,NULL };
		editor->prev = one;
		one->next = editor;
		one->c=c;
		front = one;
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int M;
	getline(cin,s);
	cin >> M;

	Node* editor = new Node{ NULL,NULL,NULL };
	int s_length = s.length();
	for (int i = 0; i < s_length; i++) {
		insertleft(editor,s[i]);
	}
	
	cursor = editor;

	for (int i = 0; i < M; i++) {
		char order, input;
		
		cin >> order;
		if (order == 'P')
			cin >> input;
		switch (order) {
		case 'L':
			if (cursor->prev != NULL) {
				cursor = cursor->prev;
			}
			break;
		case 'D':
			if (cursor->next != NULL) {
				cursor = cursor->next;
			}
			break;
		case 'B':
			if (cursor->prev != NULL)
				remove(cursor);
			break;
		case 'P':
			insertleft(cursor,input);
			break;
		default:
			break;
		}
	}

	for (Node* start = front; start->c != NULL; start = start->next) {
		cout << start->c;
	}

}