#include <bits/stdc++.h>
#define weight first 
#define price second 
using namespace std;

vector<pair<int, int>> jewelry;
multiset<int> bag;

bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.price == p2.price)
		return p1.weight > p2.weight;
	else
		return p1.price > p2.price;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N,K;
	long long answer = 0;

	cin >> N >> K;//보석개수, 가방개수
	for (int i = 0; i < N; i++) {
		//보석 무게, 가격 입력
		int weight, price;
		cin >> weight >> price;
		jewelry.push_back({ weight,price });
	}
	for (int i = 0; i < K; i++) {
		//가방에 담을 수 있는 최대 무게(가방에는 보석 한개씩만)
		int maxWeight;
		cin >> maxWeight;
		bag.insert(maxWeight);
	}

	//1.가격 내림차순
	//2.무게 내림차순
	sort(jewelry.begin(), jewelry.end(), compare);
	for (int i = 0; i < N; i++) {
		multiset<int>::iterator it=bag.lower_bound(jewelry[i].weight);
		if (it == bag.end())
			continue;
		answer += jewelry[i].price;
		bag.erase(it);
	}

	cout << answer << "\n";


	return 0;
}