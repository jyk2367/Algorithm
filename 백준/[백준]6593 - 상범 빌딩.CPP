#include <bits/stdc++.h>
#define threepair pair<int,pair<int,int>> 
using namespace std;

char mtrx[32][32][32];
bool visited[32][32][32];
int L, R, C;

int dz[] = { 0,0,0,0,-1,1 };
int dx[] = { 0,0,-1,1,0,0 };
int dy[] = { -1,1,0,0,0,0 };

bool func(threepair st,int &cnt) {
	queue<threepair> q;
	q.push(st);
	visited[st.first][st.second.first][st.second.second] = true;

	while (!q.empty()) {
		cnt++;
		int QSIZE = q.size();
		for (int i = 0; i < QSIZE; i++) {
			threepair p = q.front();
			q.pop();
			int nowz = p.first;
			int nowx = p.second.first;
			int nowy = p.second.second;

			for (int dir = 0; dir < 6; dir++) {
				int nextz = nowz + dz[dir];
				int nextx = nowx + dx[dir];
				int nexty = nowy + dy[dir];

				if (nextz < 0 || nextx < 0 || nexty < 0 || nextz >= L || nextx >= R || nexty >= C)
					continue;
				if (visited[nextz][nextx][nexty])
					continue;
				if (mtrx[nextz][nextx][nexty] == '#')
					continue;
				if (mtrx[nextz][nextx][nexty] == 'E') {
					return true;
				}
				q.push({ nextz,{nextx,nexty} });
				visited[nextz][nextx][nexty] = true;
			}
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	while (true) {
		memset(visited, 0, sizeof(visited));
		cin >> L >> R >> C;
		
		if (L == 0 && R == 0 && C == 0)
			break;
		threepair st;
		int answer = 0;
		for (int k = 0; k < L; k++) {
			for (int i = 0; i < R; i++) {
				string tmp;
				cin >> tmp;
				for (int j = 0; j < C; j++) {
					mtrx[k][i][j] = tmp[j];
					if (tmp[j] == 'S')
						st = { k,{i,j} };
				}
			}
		}
		
		if (func(st,answer))
			cout << "Escaped in " << answer << " minute(s).\n";
		else
			cout << "Trapped!\n";
	}
	

	return 0;
}