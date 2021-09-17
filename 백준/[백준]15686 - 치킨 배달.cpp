#include <iostream>
#include <stdlib.h>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;
int **city;
int** dist;
bool **visited;
vector <pair<int,int>> home;
vector <pair<int, int>> chicken;


void func() {
	vector<pair<int, int>> homeV;
	vector<pair<int, int>> chickenV;
	vector <int> combination;
	int result = 1000000;

	for (int i = 0; i < M; i++) {
		combination.push_back(1);
	}
	for (int i = M; i < chicken.size(); i++) {
		combination.push_back(0);
	}
	sort(combination.begin(), combination.end());
	do {
		int sum = 0;
		homeV.clear();
		homeV.assign(home.begin(), home.end());
		while (!homeV.empty()) {
			pair<int, int> p = homeV.back();
			homeV.pop_back();

			for (int i = 0; i < combination.size(); i++) {
				if (combination[i] == 1) {
					chickenV.push_back(make_pair(chicken[i].first,chicken[i].second));
				}
			}

			while (!chickenV.empty()) {
				pair<int, int> c = chickenV.back();
				chickenV.pop_back();

				dist[p.first][p.second] = min(abs(p.first - c.first) + abs(p.second - c.second), dist[p.first][p.second]);
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (dist[i][j] != 10000000)
					sum += dist[i][j];
				dist[i][j] = 10000000;
			}
		}
		if (result > sum)
			result = sum;
	} while (next_permutation(combination.begin(), combination.end()));


	cout << result;
	
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	
	city = new int* [N];
	dist = new int* [N];
	visited = new bool* [N];
	for (int i = 0; i < N; i++) {
		city[i] = new int[N];
		dist[i] = new int[N];
		visited[i] = new bool[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = 10000000;
			visited[i][j] = false;
			cin >> city[i][j];
			if (city[i][j] == 1)
				home.push_back(make_pair(i, j));
			if (city[i][j] == 2)
				chicken.push_back(make_pair(i, j));
		}
	}
	func();
	
}