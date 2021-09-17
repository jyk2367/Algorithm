#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int L, C;
vector <char> v;
bool visited[16];
char arr[16];

void func(int k,int st) {
	if (k == L) {
		int cnt1=0, cnt2=0;
		for (int i = 0; i < L; i++) {
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
				cnt1++;
			else
				cnt2++;
		}
		if (cnt1 >= 1 && cnt2 >= 2) {
			for (int i = 0; i < L; i++) {
				cout << arr[i];
			}
			cout << "\n";
		}
		return;
	}
	for (int i = st; i < C; i++) {
		if (!visited[i]) {
			arr[k] = v[i];
			visited[i] = true;
			func(k + 1,i);
			visited[i] = false;
		}
	}


}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		char c;
		cin >> c;
		v.push_back(c);
	}
	sort(v.begin(), v.end());
	func(0,0);

}