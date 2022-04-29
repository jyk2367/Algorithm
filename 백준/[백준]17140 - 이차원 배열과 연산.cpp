#include <bits/stdc++.h>

using namespace std;

int r, c, k;
int A[102][102];
int numCnt[102];

bool comp(const pair<int,int> &p1, const pair<int, int>& p2){
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	return p1.second < p2.second;
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> k;
	
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> A[i][j];
		}
	}

	int Time = 0;
	int mxRow = 3, mxCol = 3;

	while (Time <=100) {
		if (A[r][c] == k)
			break;
		
		Time++;

		if (mxRow >= mxCol) {		//R연산
			// [1][1]~[1][N]까지 numCnt로 ++
			for (int i = 1; i <= mxRow; i++) {
				for (int j = 1; j <= mxCol; j++) {
					if (A[i][j] == 0)
						continue;
					numCnt[A[i][j]]++;
					A[i][j] = 0;
				}
				// numCnt[i]>0인 i들을 대상으로 vector생성, 숫자정리 { 숫자 , 횟수}
				vector<pair<int, int>> tmp;
				for (int j = 1; j < 101; j++) {
					if (numCnt[j] == 0)
						continue;
					tmp.push_back({ j,numCnt[j] });
					numCnt[j] = 0;
				}
				// 횟수 순 정렬 후 숫자 순 정렬+maxRow 증가
				sort(tmp.begin(), tmp.end(), comp);

				int idx = 1;
				for (int k = 0; k < tmp.size(); k++) {
					if (idx >= 100)
						continue;
					A[i][idx++] = tmp[k].first;
					A[i][idx++] = tmp[k].second;
				}
				mxCol = max(mxCol, (int)tmp.size() * 2);
			}

		}
		else {		//C연산
			for (int i = 1; i <= mxCol; i++) {
				for (int j = 1; j <= mxRow; j++) {
					if (A[j][i] == 0)
						continue;
					numCnt[A[j][i]]++;
					A[j][i] = 0;
				}
				// numCnt[i]>0인 i들을 대상으로 vector생성, 숫자정리 { 숫자 , 횟수}
				vector<pair<int, int>> tmp;
				for (int j = 1; j < 101; j++) {
					if (numCnt[j] == 0)
						continue;
					tmp.push_back({ j,numCnt[j] });
					numCnt[j] = 0;
				}
				// 횟수 순 정렬 후 숫자 순 정렬+maxRow 증가
				sort(tmp.begin(), tmp.end(), comp);

				int idx = 1;
				for (int k = 0; k < tmp.size(); k++) {
					if (idx >= 100)
						continue;
					A[idx++][i] = tmp[k].first;
					A[idx++][i] = tmp[k].second;
				}
				mxRow = max(mxRow, (int)tmp.size()*2);
			}
		}

		/*for (int i = 1; i <= mxRow; i++) {
			for (int j = 1; j <= mxCol; j++) {
				cout << A[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";*/
	}
	
	if (Time > 100)
		cout << -1 << "\n";
	else
		cout << Time << "\n";
	return 0;
}