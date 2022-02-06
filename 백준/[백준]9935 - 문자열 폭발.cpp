#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string text, explode;
	vector<char> v;

	cin >> text>>explode;

	int TLEN = text.length();
	int ELEN = explode.length();
	
	for (int i = 0; i < TLEN; i++) {
		v.push_back(text[i]);

		if (text[i]==explode[ELEN-1]) {
			bool flag = true;
			for (int j = 0; j < ELEN; j++) {
				if (v[v.size() - ELEN + j] != explode[j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				for (int j = 0; j < ELEN; j++) {
					v.pop_back();
				}
			}
		}
	}

	if (v.size()==0)
		cout << "FRULA";
	else {
		for (char c : v) {
			cout << c;
		}
	}


	return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// string text,explode;

// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);

// 	cin >> text;
// 	cin >> explode;

// 	while (true) {
// 		int idx=text.find(explode);
// 		if (idx == string::npos)
// 			break;
// 		text.erase(idx, explode.size());
// 	}
// 	if (text == "")
// 		cout << "FRULA";
// 	else
// 		cout<<text;
	


// 	return 0;
// }