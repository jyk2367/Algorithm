#include <bits/stdc++.h>
using namespace std;

char tree[26][3];

void preorder(char mid) {
	if (mid != '.') {
		cout << mid;
		preorder(tree[mid-'A'][1]);
		preorder(tree[mid-'A'][2]);
	}
}

void inorder(char mid) {
	if (mid != '.') {
		inorder(tree[mid - 'A'][1]);
		cout << mid;
		inorder(tree[mid - 'A'][2]);
	}
}

void postorder(char mid) {
	if (mid != '.') {
		postorder(tree[mid - 'A'][1]);
		postorder(tree[mid - 'A'][2]);
		cout << mid;
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int num = N;
	while (num--) {
		char parent, left, right;
		cin >> parent >> left >> right;
		tree[parent - 'A'][1] = left;
		tree[parent - 'A'][2] = right;
		if(left!='.')
			tree[left - 'A'][0] = parent;
		if(right!='.')
			tree[right - 'A'][0] = parent;
	}

	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');

	return 0;
}