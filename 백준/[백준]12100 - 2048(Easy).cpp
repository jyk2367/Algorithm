#include <iostream>
#include <queue>

using namespace std;

int N;
int** matrix;
int max_block;

void maxBlock() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            max_block = max(max_block, matrix[i][j]);
        }
    }
}

void move(int dir) {
    queue<int> q;
    switch (dir) {
    case 0://left
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == 0)
                    continue;
                q.push(matrix[i][j]);
                matrix[i][j] = 0;
            }
            int j = 0;
            while (!q.empty()) {
                if (matrix[i][j] == 0) {
                    matrix[i][j] = q.front();
                }
                else if (matrix[i][j] == q.front()) {
                    matrix[i][j++] *= 2;
                }
                else {
                    j++;
                    matrix[i][j] = q.front();
                }
                q.pop();
            }
        }
        break;
    case 1://right
        for (int i = 0; i < N; i++) {
            for (int j = N-1; j >=0; j--) {
                if (matrix[i][j] == 0)
                    continue;
                q.push(matrix[i][j]);
                matrix[i][j] = 0;
            }
            int j = N-1;
            while (!q.empty()) {
                if (matrix[i][j] == 0) {
                    matrix[i][j] = q.front();
                }
                else if (matrix[i][j] == q.front()) {
                    matrix[i][j--] *= 2;
                }
                else {
                    j--;
                    matrix[i][j] = q.front();
                }
                q.pop();
            }
        }
        break;
    case 2://up
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[j][i] == 0)
                    continue;
                q.push(matrix[j][i]);
                matrix[j][i] = 0;
            }
            int j = 0;
            while (!q.empty()) {
                if (matrix[j][i] == 0) {
                    matrix[j][i] = q.front();
                }
                else if (matrix[j][i] == q.front()) {
                    matrix[j][i] *= 2;
                    j++;
                }
                else {
                    j++;
                    matrix[j][i] = q.front();
                }
                q.pop();
            }
        }
        break;
    case 3://down
        for (int i = 0; i < N; i++) {
            for (int j = N-1; j>=0; j--) {
                if (matrix[j][i] == 0)
                    continue;
                q.push(matrix[j][i]);
                matrix[j][i] = 0;
            }
            int j = N-1;
            while (!q.empty()) {
                if (matrix[j][i] == 0) {
                    matrix[j][i] = q.front();
                }
                else if (matrix[j][i] == q.front()) {
                    matrix[j][i] *= 2;
                    j--;
                }
                else {
                    j--;
                    matrix[j][i] = q.front();
                }
                q.pop();
            }
        }
        break;
    }
}

void func(int k) {
    if (k == 5) {
        maxBlock();
        return;
    }
    int **before;
    before = new int*[N];
    for (int i = 0; i < N; i++) {
        before[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            before[i][j] = matrix[i][j];
        }
    }

    for (int dir = 0; dir < 4; dir++) {
        move(dir);
        func(k + 1);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j] = before[i][j];
            }
        }
    }

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    matrix = new int* [N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    func(0);

    cout << max_block;
}