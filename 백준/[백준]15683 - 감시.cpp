#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
int N, M;
int** matrix;
vector <pair<int, int>> v;

int min_cnt=0x7fffffff;
int v_SIZE;

queue<pair<int, int>> dir_up(pair<int, int> p) {
	queue<pair<int, int>> q;

	for (int i = p.first; i >= 0; i--) {
		if (matrix[i][p.second] == 0) {
			matrix[i][p.second] = 7;
			q.push(make_pair(i, p.second));
		}
		else if (matrix[i][p.second] == 6)
			break;
	}

	return q;
}
queue<pair<int, int>> dir_left(pair<int, int> p) {
	queue<pair<int, int>> q;

	for (int i = p.second; i >= 0; i--) {
		if (matrix[p.first][i] == 0) {
			matrix[p.first][i] = 7;
			q.push(make_pair(p.first, i));
		}
		else if (matrix[p.first][i] == 6)
			break;
	}

	return q;
}
queue<pair<int, int>> dir_right(pair<int, int> p) {
	queue<pair<int, int>> q;

	for (int i = p.second; i < M; i++) {
		if (matrix[p.first][i] == 0) {
			matrix[p.first][i] = 7;
			q.push(make_pair(p.first, i));
		}
		else if (matrix[p.first][i] == 6)
			break;
	}

	return q;
}
queue<pair<int, int>> dir_down(pair<int, int> p) {
	queue<pair<int, int>> q;

	for (int i = p.first; i < N; i++) {
		if (matrix[i][p.second] == 0) {
			matrix[i][p.second] = 7;
			q.push(make_pair(i, p.second));
		}
		else if (matrix[i][p.second] == 6)
			break;
	}

	return q;
}

void func(int k) {
	if (k==v_SIZE) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (matrix[i][j] == 0) {
					cnt++;
				}
			}
		}
		if (cnt < min_cnt)
			min_cnt = cnt;
		return;
	}

	pair<int, int> p = v.back();
	v.pop_back();

	switch (matrix[p.first][p.second]) {
	case 1:
		for (int dir = 0; dir < 4;dir++) {
			queue<pair<int, int>> q;
			switch (dir) {
			case 0:
				q = dir_up(p);
				func(k + 1);
				while (!q.empty()) {
					pair<int, int> pa = q.front();
					q.pop();
					matrix[pa.first][pa.second] = 0;
				}
				break;
			case 1:
				q = dir_left(p);
				func(k + 1);
				while (!q.empty()) {
					pair<int, int> pa = q.front();
					q.pop();
					matrix[pa.first][pa.second] = 0;
				}
				break;
			case 2:
				q = dir_right(p);
				func(k + 1);
				while (!q.empty()) {
					pair<int, int> pa = q.front();
					q.pop();
					matrix[pa.first][pa.second] = 0;
				}
				break;
			case 3:
				q = dir_down(p);
				func(k + 1);
				while (!q.empty()) {
					pair<int, int> pa = q.front();
					q.pop();
					matrix[pa.first][pa.second] = 0;
				}
				break;
			default:
				func(k + 1);
				break;
			}
		}
		break;
	case 2:
		for (int dir = 0; dir < 2; dir++) {
			queue<pair<int, int>> q1, q2;
			switch (dir) {
			case 0:
				q1 = dir_up(p);
				q2 = dir_down(p);
				func(k + 1);
				while (!q1.empty()) {
					pair<int, int> pa = q1.front();
					q1.pop();
					matrix[pa.first][pa.second] = 0;
				}
				while (!q2.empty()) {
					pair<int, int> pa = q2.front();
					q2.pop();
					matrix[pa.first][pa.second] = 0;
				}
				break;
			case 1:
				q1 = dir_left(p);
				q2 = dir_right(p);
				func(k + 1);
				while (!q1.empty()) {
					pair<int, int> pa = q1.front();
					q1.pop();
					matrix[pa.first][pa.second] = 0;
				}
				while (!q2.empty()) {
					pair<int, int> pa = q2.front();
					q2.pop();
					matrix[pa.first][pa.second] = 0;
				}
				break;
			default:
				func(k + 1);
			}
		}
		break;
	case 3:
		for (int dir = 0; dir < 4; dir++) {
			queue<pair<int, int>> q1,q2;
			switch (dir) {
			case 0:
				q1 = dir_up(p);
				q2 = dir_right(p);
				func(k + 1);
				while (!q1.empty()) {
					pair<int, int> pa = q1.front();
					q1.pop();
					matrix[pa.first][pa.second] = 0;
				}
				while (!q2.empty()) {
					pair<int, int> pa = q2.front();
					q2.pop();
					matrix[pa.first][pa.second] = 0;
				}
				break;
			case 1:
				q1 = dir_right(p);
				q2 = dir_down(p);
				func(k + 1);
				while (!q1.empty()) {
					pair<int, int> pa = q1.front();
					q1.pop();
					matrix[pa.first][pa.second] = 0;
				}
				while (!q2.empty()) {
					pair<int, int> pa = q2.front();
					q2.pop();
					matrix[pa.first][pa.second] = 0;
				}
				break;
			case 2:
				q1 = dir_down(p);
				q2 = dir_left(p);
				func(k + 1);
				while (!q1.empty()) {
					pair<int, int> pa = q1.front();
					q1.pop();
					matrix[pa.first][pa.second] = 0;
				}
				while (!q2.empty()) {
					pair<int, int> pa = q2.front();
					q2.pop();
					matrix[pa.first][pa.second] = 0;
				}
				break;
			case 3:
				q1 = dir_left(p);
				q2 = dir_up(p);
				func(k + 1);
				while (!q1.empty()) {
					pair<int, int> pa = q1.front();
					q1.pop();
					matrix[pa.first][pa.second] = 0;
				}
				while (!q2.empty()) {
					pair<int, int> pa = q2.front();
					q2.pop();
					matrix[pa.first][pa.second] = 0;
				}
				break;
			default:
				func(k + 1);
				break;
			}
		}
		break;
	
	case 4:
		for (int dir = 0; dir < 4; dir++) {
			queue<pair<int, int>> q1,q2,q3;
			switch (dir) {
			case 0:
				q1 = dir_up(p);
				q2 = dir_right(p);
				q3 = dir_down(p);
				func(k + 1);
				while (!q1.empty()) {
					pair<int, int> pa = q1.front();
					q1.pop();
					matrix[pa.first][pa.second] = 0;
				}
				while (!q2.empty()) {
					pair<int, int> pa = q2.front();
					q2.pop();
					matrix[pa.first][pa.second] = 0;
				}
				while (!q3.empty()) {
					pair<int, int> pa = q3.front();
					q3.pop();
					matrix[pa.first][pa.second] = 0;
				}
				break;
			case 1:
				q1 = dir_right(p);
				q2 = dir_down(p);
				q3 = dir_left(p);

				func(k + 1);
				while (!q1.empty()) {
					pair<int, int> pa = q1.front();
					q1.pop();
					matrix[pa.first][pa.second] = 0;
				}
				while (!q2.empty()) {
					pair<int, int> pa = q2.front();
					q2.pop();
					matrix[pa.first][pa.second] = 0;
				}
				while (!q3.empty()) {
					pair<int, int> pa = q3.front();
					q3.pop();
					matrix[pa.first][pa.second] = 0;
				}
				break;
			case 2:
				q1= dir_down(p);
				q2 = dir_left(p);
				q3 = dir_up(p);
				func(k + 1);
				while (!q1.empty()) {
					pair<int, int> pa = q1.front();
					q1.pop();
					matrix[pa.first][pa.second] = 0;
				}
				while (!q2.empty()) {
					pair<int, int> pa = q2.front();
					q2.pop();
					matrix[pa.first][pa.second] = 0;
				}
				while (!q3.empty()) {
					pair<int, int> pa = q3.front();
					q3.pop();
					matrix[pa.first][pa.second] = 0;
				}
				break;
			case 3:
				q1 = dir_left(p);
				q2 = dir_up(p);
				q3 = dir_right(p);
				func(k + 1);
				while (!q1.empty()) {
					pair<int, int> pa = q1.front();
					q1.pop();
					matrix[pa.first][pa.second] = 0;
				}
				while (!q2.empty()) {
					pair<int, int> pa = q2.front();
					q2.pop();
					matrix[pa.first][pa.second] = 0;
				}
				while (!q3.empty()) {
					pair<int, int> pa = q3.front();
					q3.pop();
					matrix[pa.first][pa.second] = 0;
				}
				break;
			default:
				func(k + 1);
				break;
			}
		}
		break;
	case 5:	
		{
			queue<pair<int, int>> q1, q2, q3, q4;
			q1 = dir_up(p);
			q2 = dir_down(p);
			q3 = dir_left(p);
			q4 = dir_right(p);
			func(k + 1);
			while (!q1.empty()) {
				pair<int, int> pa = q1.front();
				q1.pop();
				matrix[pa.first][pa.second] = 0;
			}
			while (!q2.empty()) {
				pair<int, int> pa = q2.front();
				q2.pop();
				matrix[pa.first][pa.second] = 0;
			}
			while (!q3.empty()) {
				pair<int, int> pa = q3.front();
				q3.pop();
				matrix[pa.first][pa.second] = 0;

			}
			while (!q4.empty()) {
				pair<int, int> pa = q4.front();
				q4.pop();
				matrix[pa.first][pa.second] = 0;
			}
		}
		break;
	default:
		func(k + 1);
	}
	v.push_back(p);
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	matrix = new int* [N];
	for (int i = 0; i < N; i++) {
		matrix[i] = new int[M];
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] != 0 && matrix[i][j] != 6)
				v.push_back(make_pair(i, j));
		}
	}

	v_SIZE = v.size();
	func(0);
	
	cout << min_cnt;
	
}