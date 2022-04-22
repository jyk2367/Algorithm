#include <bits/stdc++.h>

using namespace std;


int N;
int x, y, d, g;
int mtrx[102][102];

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

void gen() {
	vector<pair<int, int>> curv;
	curv.push_back({x,y});
	curv.push_back({x+dx[d],y+dy[d]});
	int cnt=0;
	
	while (cnt < g) {
		int CSIZE = curv.size();
		vector<pair<int, int>> v;
		for (int i = 0; i < CSIZE; i++) {
			int nx = x - (curv[i].second - y);
			int ny = y + (curv[i].first - x);

			v.push_back({ nx,ny });
		}

		int ndx = curv.back().first- v.back().first;
		int ndy =curv.back().second- v.back().second;
		v.pop_back();
		int VSIZE = v.size();

		for (int i = VSIZE - 1; i >= 0; i--) {
			int nx = v[i].first + ndx;
			int ny = v[i].second + ndy;
			curv.push_back({ nx, ny });
		}

		cnt++;
	}

	int VSIZE = curv.size();
	for (int i = 0; i < VSIZE; i++) {
		mtrx[curv[i].first][curv[i].second]++;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
		gen();
	}

	int answer = 0;
	for (int i = 0; i <100; i++) {
		for (int j = 0; j <100; j++) {
			if (mtrx[i][j] > 0 && mtrx[i + 1][j] > 0 && mtrx[i][j + 1] > 0 && mtrx[i + 1][j + 1] > 0)
				answer++;
		}
	}
	cout << answer << "\n";

}