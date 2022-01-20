#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(void) {
	queue<int> q;
	int N;
	cin >> N;
	
	while (N--) {
		string order;
		cin >> order;
		
		if (order == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (order == "pop") {
			if (q.size() == 0)
				cout << -1 << "\n";
			else {
				cout << q.front()<<"\n";
				q.pop();
			}
		}
		else if (order == "size") {
			cout << q.size() << "\n";
		}
		else if (order == "empty") {
			int num = q.size() == 0 ? 1 : 0;
			cout << num << "\n";
		}
		else if (order == "front") {
			if (q.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
			}
		}
		else if (order == "back") {
			if (q.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << q.back() << "\n";
			}
		}
	}
}