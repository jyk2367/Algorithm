#include <iostream>
#include <vector>

#define VERTEXSIZE 10'002

using namespace std;

int V, E;
int A, B;


vector<int> al[VERTEXSIZE];
int visitedOrder[VERTEXSIZE];	// 미방문 : 0, 방문 순서가 저장이 됨
int order = 1;
bool CutVertex[VERTEXSIZE];		// 각 정점의 단절점 여부

vector<int> answer;

//현재 노드에 있는 low 정보를 부모 노드에게 넘겨줘야 하므로
int dfs(int now,int parent) {
	visitedOrder[now]=order++;
	
	int minOrder = visitedOrder[now];
	int child = 0;

	for (int next : al[now]) {
		if (next == parent) //바로 이전에 타고온 부모노드인 경우 pass
			continue;
		if (visitedOrder[next]>0) {
			//next를 방문해본적 있는 노드 = 내 조상인데, 나와 연결되어있음 = 다른길이 존재한다는 뜻
			minOrder = min(visitedOrder[next], minOrder);
		}
		else {
			//next를 방문해본적이 없는 경우
			child++;
			int low=dfs(next, now);

			if (parent!=0 && visitedOrder[now] <= low) {
				CutVertex[now] = true;
			}

			//low는 내 자식들 중 가장 작은 순서, minOrder는 내 조상의 방문순서
			minOrder = min(low, minOrder);
		}
	}

	if (parent == 0 && child >= 2)
		CutVertex[now] = true;

	return minOrder;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> A >> B;
		al[A].push_back(B);
		al[B].push_back(A);
	}
	
	//먼저 순서 찾기
	for (int i = 1; i <= V; i++) {
		if (visitedOrder[i] == 0) {
			dfs(i,0);
		}
	}

	//단절점 정보 출력
	for (int i = 1; i <= V; i++) {
		if (CutVertex[i] == true) {
			answer.push_back(i);
		}
	}

	int ASIZE = answer.size();
	cout << ASIZE << "\n";
	for (int i = 0; i < ASIZE; i++) {
		cout << answer[i] << " ";
	}


	return 0;
}