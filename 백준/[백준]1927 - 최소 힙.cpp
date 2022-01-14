#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, x;
	priority_queue<int,vector<int>,greater<int>> pq;

	cin >> N;
	while (N--) {
		cin >> x;
		if (x == 0) {
			if (pq.empty())
				cout <<0 << "\n";
			else {
				cout <<pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}

}
/*
#include <bits/stdc++.h>
using namespace std;

int heap[100005];//minheap
int sz = 0; // heap에 들어있는 원소의 수

void push(int x) {
	heap[++sz] = x;
	int idx = sz;
	while (idx != 1) {
		int par = idx / 2;
		if (heap[par] <= heap[idx])
			break;
		swap(heap[par], heap[idx]);
		idx = par;
	}
}

int top(){
	if (sz > 0)
		return heap[1];
	else
		return 0;
}

void pop() {
	if (sz > 0) {
		heap[1] = heap[sz--];
		int idx = 1;
		while (idx * 2 <= sz) {
			int lc = idx * 2, rc = idx * 2 + 1;
			int minchild = lc;
			if (rc <= sz && heap[rc] < heap[lc])
				minchild = rc;
			if (heap[idx] <= heap[minchild])
				break;
			swap(heap[idx], heap[minchild]);
			idx = minchild;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	while (N--) {
		int num;
		cin >> num;
		if (num == 0) {
			cout <<top() << "\n";
			pop();
		}
		else
			push(num);
	}

}
*/