#include<bits/stdc++.h>

using namespace std;

int N;
//인구수
int population[12];

//선거구 index - 연결된 선거구 index
bool graph[12][12];
bool selected[12];

int answer = 0x7fff'ffff;

bool checkConnection(vector<int>& v) {
	bool visited[12];
	memset(&visited, 0, sizeof(visited));
	queue<int> q;
	q.push(v[0]);
	visited[v[0]] = true;
	int cnt = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cnt++;

		for (int i = 1; i <= N; i++) {
			if (graph[now][i] == false)
				continue;
			if (visited[i])
				continue;
			if (find(v.begin(), v.end(), i) == v.end())
				continue;
			visited[i] = true;
			q.push(i);
		}
	}

	if (cnt != v.size())
		return false;
	return true;
}

bool divide() {
	vector <int> v1, v2;
	for (int i = 1; i <= N; i++) {
		if (selected[i])
			v1.push_back(i);
		else
			v2.push_back(i);
	}
	if (v1.size() == 0 || v2.size() == 0)
		return false;

	if (!checkConnection(v1))
		return false;

	if (!checkConnection(v2))
		return false;

	return true;
}

void Calculate() {
	int sum1=0, sum2=0;
	for (int i = 1; i <= N; i++) {
		if (selected[i] == true)
			sum1 += population[i];
		else
			sum2 += population[i];
	}

	answer = min(answer, abs(sum1 - sum2));
}

void func(int k,int start) {
	if (k>=1) {
		if (divide()) {
			Calculate();
		}
	}

	for (int i = start; i < N; i++) {
		if (!selected[i]) {
			selected[i] = true;
			func(k + 1, i);
			selected[i] = false;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 1; i <=N; i++) {
		int popu;
		cin >> popu;
		population[i]=popu;
	}

	for (int i =1; i <=N; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int y;
			cin >> y;
			graph[i][y] = true;//연결되어 있다
			graph[y][i] = true;
		}
	}

	func(0,0);


	if (answer == 0x7fff'ffff) {
		cout << -1 << "\n";
	}
	else {
		cout << answer << "\n";
	}

	return 0;
}