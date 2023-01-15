#include <bits/stdc++.h>

using namespace std;

int N,M;

struct PhotoFrame{
	PhotoFrame(int Score,int Order,int candidateNum):score(Score), order(Order),num(candidateNum)
	{}


	int score = 0;
	int order = 0;
	int num = 0;
};

vector<PhotoFrame> pf;

bool compare(const PhotoFrame& pf1, const PhotoFrame& pf2) {
	if (pf1.score == pf2.score) {
		return pf1.order > pf2.order;
	}
	else {
		return pf1.score > pf2.score;
	}
}

bool resultcompare(const PhotoFrame& pf1, const PhotoFrame& pf2) {
	return pf1.num < pf2.num;
}
bool checkFrame(int candidateNum) {
	sort(pf.begin(), pf.end(), compare);
	for (int i = 0; i < pf.size(); i++) {
		if (pf[i].num != candidateNum)
			continue;
		pf[i].score++;
		return true;
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N; //사진틀의 개수
	cin >> M; //총 추천 횟수(1000번 이하)
	for (int i = 0; i <M; i++) {
		// 추천 후보
		int candidateNum;
		cin >> candidateNum;
		
		bool state = checkFrame(candidateNum);
		if(pf.size()<N && !state){ // 1. 다 안찬 상황에서 사진틀에 없다면
			pf.push_back(PhotoFrame(1, i, candidateNum));
		}
		else if (state)
		// 1~N의 pf에서 값이 없는 경우엔 삭제하고 넣어야 하므로
		// 값이 있으면 값을 더해주고 true, 값이 없으면 false
		{
			//checkFrame함수에서 이
		}
		else {
			//값이 없으니 삭제 후 넣어주기
			pf.pop_back();
			pf.push_back(PhotoFrame(1, i, candidateNum));
		}
	}


	sort(pf.begin(), pf.end(),resultcompare);
	for (int i = 0; i < pf.size(); i++) {
		cout << pf[i].num << " ";
	}


	return 0;
}