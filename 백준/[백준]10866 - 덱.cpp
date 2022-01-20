#include <iostream>
#include <deque>

using namespace std;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> DQ;
	int N;
	cin >> N;

	while (N--) {
		string s;
		cin >> s;
		if (s == "push_back") {
			int num;
			cin >> num;
			DQ.push_back(num);
		}
		else if (s == "push_front") {
			int num;
			cin >> num;
			DQ.push_front(num);
		}
		else if (s == "front") {
			if (DQ.size() == 0) {
				cout << -1 << "\n";
			}
			else
				cout<<DQ.front()<<"\n";
		}
		else if (s == "back") {
			if (DQ.empty()) {
				cout << -1 << "\n";
			}
			else
				cout<<DQ.back()<<"\n";
		}
		else if (s == "size") {
			cout << DQ.size() << "\n";
		}
		else if (s == "pop_front") {
			if (DQ.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << DQ.front()<<"\n";
				DQ.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (DQ.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << DQ.back() << "\n";
				DQ.pop_back();
			}
		}
		else if (s == "empty") {
			cout << DQ.empty() << "\n";
		}
		
	}
}