#include <bits/stdc++.h>
using namespace std;

typedef struct DP {
	int num;
	int loc;
	int last;
	int dp;
	DP(int num, int loc, int last, int dp) : num(num), loc(loc), last(last), dp(dp) {}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<DP> A,track;
	vector<int> answer;

	DP dp((0x80000000),-1,-1,0);
	A.push_back(dp);
	track.push_back(dp);
	int lastdp = 0,idx=0;

	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		DP tmp(num, i,-1, 1);
		A.push_back(tmp);
	}

	for (int i = 1; i <=N; i++) {
		if (A[i].num> track.back().num) {
			A[i].last = track.back().loc;
			A[i].dp = track.back().dp + 1;
			track.push_back(A[i]);
		}
		else {
			int left = 0, right = track.size()-1;
			while (left < right) {
				int mid = (left + right) / 2;
				if (track[mid].num<A[i].num)
					left = mid + 1;
				else
					right = mid;
			}

			track[right].num = A[i].num;
			track[right].loc = A[i].loc;
			track[right].last = track[right - 1].loc;
			track[right].dp= track[right - 1].dp + 1;
			A[i].last = track[right-1].loc;
			A[i].dp = track[right-1].dp+1;
		}
		
	}

	idx = track.back().last;
	answer.push_back(track.back().num);
	while (idx!=-1) {
		answer.push_back(A[idx].num);
		idx = A[idx].last;
	}


	cout << answer.size() << "\n";
	for (int i = answer.size()-1; i>=0;i--) {
		cout << answer[i] << " ";
	}

	return 0;
}