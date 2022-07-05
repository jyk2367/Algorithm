#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

string N;
int M,K;
int answer;

void bfs() {

	queue<pair<string, int>> q;
	q.push({N,0});
	int T = 0;
	while (!q.empty()) {
		int QSIZE = q.size();
		set<string> s;
		for (int p = 0; p < QSIZE; p++) {
			string number = q.front().first;
			int k = q.front().second;
			q.pop();

			if (k == K) {
				answer = max(answer, stoi(number));
				continue;
			}

			for (int i = 0; i < M - 1; i++) {
				for (int j = i + 1; j < M; j++) {
					swap(number[i], number[j]);
					if (number[0] == '0') {
						swap(number[i], number[j]);
						continue;
					}
					else
						s.insert(number);
					swap(number[i], number[j]);
				}
			}
		}

		for (set<string>::iterator it = s.begin(); it != s.end(); it++) {
			q.push({ *it,T + 1 });
		}
		T++;
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	M = N.length();
	
	bfs();

	if(answer==0)
		cout << -1 << "\n";
	else
		cout << answer << "\n";

	return 0;
}