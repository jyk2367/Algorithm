#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T,k;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> k;

		multiset<int> ms;

		while (k--) {
			string op, num;
			cin >> op >> num;

			if (op == "I") {
				ms.insert(stoi(num));
			}
			else if (op == "D"&& !ms.empty()) {
				if (num == "1") {
					ms.erase(prev(ms.end()));
				}
				else if(num=="-1") {
					ms.erase(ms.begin());
				}

			}
		}
		if (ms.empty()) {
			cout << "EMPTY" << "\n";
		}
		else {
			cout << *prev(ms.end()) << " " << *ms.begin() << "\n";
		}
	}

	return 0;
}