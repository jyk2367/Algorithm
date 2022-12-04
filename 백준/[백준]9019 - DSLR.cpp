#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

char op[4] = { 'D','S','L','R' };
bool visited[10002];


inline int opD(const int number){
	return (number * 2) % 10000;
}

inline int opS(const int &number) {
	if (number == 0)
		return 9999;
	else
		return number-1;
}

//1234-> 2341
inline int opL(const int &number){
	return  (number % 1000) * 10 + (number / 1000);
}

//1234-> 4123
inline int opR(const int &number) {
	return  (number / 10) + (number % 10) * 1000;;
}

int opSelect(const char& C, const int& number) {
	switch (C) {
	case 'D':
		return opD(number);
	case 'S':
		return opS(number);
	case 'L':
		return opL(number);
	case 'R':
		return opR(number);
	}
	return -1;
}

string bfs(int st,int ed) {
	queue<pair<string,int>> q;
	q.push({"",st});
	visited[st] = true;
	int count = 0;
	
	while (!q.empty()) {
		const int QSIZE = q.size();
		for (int i = 0; i < QSIZE; i++) {
			string nowSt = q.front().first;
			int nowNum = q.front().second;
			q.pop();

			if (nowNum == ed) {
				return nowSt;
			}

			for (int d = 0; d < 4; d++) {
				int nextNum=opSelect(op[d], nowNum);
				if (visited[nextNum])
					continue;
				visited[nextNum] = true;
				q.push({ nowSt+op[d],nextNum });
			}
		}
		count++;
	}

	return "";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T,A,B;

	cin >> T;
	while (T--) {
		//초기화
		memset(visited, false, sizeof visited);

		//입력
		cin >> A >> B;

		//구현
		cout<<bfs(A,B)<<"\n";

	}


	return 0;

}