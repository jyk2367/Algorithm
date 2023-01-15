#include <bits/stdc++.h>

using namespace std;

int N, M, K;


vector<int> parent(4'000'001);
vector<int> card(4'000'001);


int find_root(int x) {
	if (x == parent[x])
		return x;
	return find_root(parent[x]);
}

void union_root(int x, int y) {
	x = find_root(x);
	y = find_root(y);

	if (x != y) {
		parent[x] = y; // x의 부모가 y
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> card[i];
	}

	sort(card.begin(), card.begin() + M);

	// Parent로 순서대로 연결시킴
	for (int i = 0; i < M; i++) {
		parent[i] = i;
	}
	
	//Solution - 분리집합 필요
	
	for (int i = 0; i < K;i++) {

		int num;
		cin >> num;
		
		int left = 0, right = M - 1;
		while (left < right) {
			int mid = (left + right) / 2;

			if (card[mid] > num) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}


		//1. 찾은 값을 출력하고
		//2. 찾은 값이 다음 값을 선택하도록 Union Find로 설정(연결리스트처럼 활용)
		cout << card[find_root(right)] << "\n";
		if (right <= M - 1)
			union_root(find_root(right), find_root(right) + 1);
	}

	return 0;
}