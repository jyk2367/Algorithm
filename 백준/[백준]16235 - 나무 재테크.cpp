
#include <bits/stdc++.h>

using namespace std;

//N : 땅크기, M : 나무개수 
int N, M, K;

//나무위치 x,y / 나이 z
int x, y, z;

//양분 추가량
int A[12][12];

//나무 양분
int land[12][12];


bool comp(const pair<pair<int, int>, int>& p1, const pair<pair<int, int>, int>& p2) {
	return p1.second < p2.second;
}


//나무 나이
deque<pair<pair<int, int>, int>> tree;

const int dx[] = { -1,-1,-1,0,0,1,1,1 };
const int dy[] = { -1,0,1,-1,1,-1,0,1 };

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			land[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		tree.push_back({ {x,y},z });
	}

	vector< pair<pair<int, int>, int >> dead;
	int year = 0;
	while (year < K) {
		//봄
		int TSIZE = tree.size();
		for (int i = 0; i < TSIZE; i++) {
			int x = tree.front().first.first;
			int y = tree.front().first.second;
			int age = tree.front().second;
			tree.pop_front();

			//양분 충분하면 먹고
			if (land[x][y] >= age) {
				land[x][y] -= age;
				tree.push_back({ {x,y},age + 1 });
			}
			else {//부족하면 죽음
				dead.push_back({ { x,y }, age });
			}
		}

		//여름
		int DSIZE = dead.size();
		for (int i = 0; i < DSIZE; i++) {
			int deadX = dead[i].first.first;
			int deadY = dead[i].first.second;
			int deadtreeage = dead[i].second;
			land[deadX][deadY] += deadtreeage / 2;
		}

		//가을
		vector< pair<pair<int, int>, int >> tmp;
		TSIZE = tree.size();
		for (int i = 0; i < TSIZE; i++) {
			int x = tree.front().first.first;
			int y = tree.front().first.second;
			int age = tree.front().second;
			tree.pop_front();
			tmp.push_back({ { x,y }, age });
			if (age % 5 == 0) {
				for (int dir = 0; dir < 8; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];

					if (nx <= 0 || ny <= 0 || nx > N || ny > N)
						continue;
					tree.push_back({ { nx,ny }, 1 });
				}
			}
		}

		for (int i = 0; i < tmp.size(); i++) {
			tree.push_back(tmp[i]);
		}

		//겨울
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				land[i][j] += A[i][j];
			}
		}
		year++;
		dead.clear();
	}

	cout << tree.size() << "\n";

	return 0;
}
/*
#include <bits/stdc++.h>

using namespace std;

//N : 땅크기, M : 나무개수 
int N, M, K;

//나무위치 x,y / 나이 z
int x, y, z;

//양분 추가량
int A[12][12];

//나무 양분
int land[12][12];

//나무 나이
vector<int> tree[12][12];

const int dx[] = { -1,-1,-1,0,0,1,1,1 };
const int dy[] = { -1,0,1,-1,1,-1,0,1 };

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N>>M>>K;
	for (int i = 1; i <=N; i++) {
		for (int j = 1; j <=N; j++){
			cin >> A[i][j];
			land[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		tree[x][y].push_back(z);
	}


	for(int year=0;year<K;year++){
		//봄
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {	



				if (tree[i][j].size() == 0)
					continue;
				vector<int> tmp;
				int dead_tree_age = 0;

				sort(tree[i][j].begin(), tree[i][j].end());


				for (int t = 0; t < tree[i][j].size(); t++) {
					int age = tree[i][j][t];
					if (land[i][j] >= age) {
						land[i][j] =land[i][j]- age;
						tmp.push_back(age+1);
					}
					else {
						//여름
						dead_tree_age += (age / 2);
					}
				}
				tree[i][j].clear();

				for (int t = 0; t < tmp.size(); t++) {
					tree[i][j].push_back(tmp[t]);
				}

				land[i][j] += dead_tree_age;


			}
		}



		//가을
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				
				
				for (int t = 0; t < tree[i][j].size(); t++) {
					
					if (tree[i][j][t] % 5 == 0) {
						for (int dir = 0; dir < 8; dir++) {
							int ni = i + dx[dir];
							int nj = j + dy[dir];

							if (ni <= 0 || nj <= 0 || ni > N || nj > N)
								continue;
							tree[ni][nj].push_back(1);
						}
					}

				}
			}
		}

		
		//겨울
		for (int i = 1; i <=N; i++) {
			for (int j = 1; j <=N; j++) {
				land[i][j] += A[i][j];
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			answer += tree[i][j].size();
		}
	}
	cout << answer <<endl;

	return 0;
}
*/