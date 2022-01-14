#include <bits/stdc++.h>
using namespace std;

struct cmp {
	bool operator()(const int &a,const int &b) {
		if (abs(a) == abs(b))//절댓값이 같은 경우
			return a>0&&b<0;//두 수가 다르고 앞이 양수, 뒤가 음수일때만 true 반환, 둘이 같은 부호를 가진다면 false(a가 b의 앞에 와야할 때 true,아니면 false)
		else//절댓값이 다른 경우
			return abs(a)>abs(b);//앞 수의 절댓값이 뒤 수의 절댓값보다 크면 true 반환
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	priority_queue<int,vector<int>,cmp> pq;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int op;
		cin >> op;
		if (op == 0) {
			if (pq.empty())
				cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
			pq.push(op);
	}

	return 0;
}