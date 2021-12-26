#include <iostream>
#include <algorithm>
#define MAX 10
using namespace std;

int N, M;
int list[MAX] = { 0, };
int arr[MAX];
bool visited[MAX] = { false, };

void dfs_9(int cur) {
    if (cur == M) {

        for (int i = 0; i < M; i++)
            cout << list[i] << " ";
        cout << "\n";
        return;
    }
    int tmp = -1;
    for (int i = 0; i <N; i++) {
        //아직 선택하지 않았으면서(not visited), 바로 이전에 선택한 값(tmp)과 같지 않은 경우    (tmp는 전역이 아닌 지역변수)
        // 1 7 9 9' 기준 
        // for문을 돌때 같은 값이 중복해서 연속(tmp==arr[i])으로 선택되면 continue
        // 
        // 
        // 1 : tmp는 -1이므로 충돌 x, 다음 dfs는 1빼고 7>9>9'(9에서 9'로 갈때 충돌)
        //                                             7 : tmp는 -1이므로 충돌 x
        //                                             9 : tmp는 7이므로 충돌 x
        //                                             9': tmp는 9이므로 충돌
        // 7 : tmp는 1이므로 충돌 x, 다음 dfs는 7빼고 1>9>9'(9에서 9'로 갈때 충돌)
        //                                             ...
        //                                             ...
        //                                             ...
        // 9 : tmp는 7이므로 충돌 x, 다음 dfs는 9빼고 1>7>9'(충돌 x)
        //                                             ...
        //                                             ...
        //                                             ...
        // 9' : tmp는 9이므로 충돌
        if (!visited[i] && tmp != arr[i]) {
            list[cur] = arr[i];
            tmp = arr[i];
            visited[i] = true;
            dfs_9(cur + 1);
            visited[i] = false;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr+N);

    dfs_9(0);
}