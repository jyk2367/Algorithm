#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int N;

int mid = 0x7fff'ffff;
priority_queue<int,vector<int>,less<int>> left_v;
priority_queue<int, vector<int>, greater<int>> right_v;
//pq + greater : 작은 놈부터 나옴

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int input;
	int n = 0;
	while (n++<N) {
		cin >> input;
		
		//최초 1회
		if (mid == 0x7fff'ffff) {
			mid = input;
		}
		else if (mid <= input) {
			right_v.push(input);
		}
		else if (input < mid) {
			left_v.push(input);
		}


		//홀수 : 균형이면 그대로, 균형이 아니라면 수 많은 쪽의 top을 꺼내 교체
		if (n % 2 == 1) {
			if (left_v.size() < right_v.size()) {
				left_v.push(mid);
				mid = right_v.top();
				right_v.pop();
			}

			if (left_v.size() > right_v.size()) {
				right_v.push(mid);
				mid = left_v.top();
				left_v.pop();
			}
		}
		//짝수 : 오른쪽이 많으면 그대로, 왼쪽이 많으면 교체
		else {
			if (left_v.size() > right_v.size()) {
				right_v.push(mid);
				mid = left_v.top();
				left_v.pop();
			}
		}
		
		
		cout << mid << "\n";
	}

	return 0;
}
