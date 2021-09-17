#pragma warning(disable:4996)
#include <stdio.h>

#define MAX_QUEUE_SIZE 5001

int front = -1, rear = -1;

void addq(int a, int cqueue[]);
int deleteq(int cqueue[]);

int main(void) {
    int cqueue[MAX_QUEUE_SIZE] = { 0 };
    int newqueue[MAX_QUEUE_SIZE] = { 0 };
    int i, j, tmp;
    int n, k;
    scanf("%d%d", &n, &k);

    for (i = 0; i < n; i++)
    {
        addq(i + 1, cqueue);
    }
    printf("<");
    for (i = 0; i < n; i++) {
        for (j = 0; j < k - 1; j++) {
            tmp = deleteq(cqueue);
            addq(tmp, cqueue);
        }
        if (i == n - 1)
            printf("%d>", deleteq(cqueue));
        else
            printf("%d, ", deleteq(cqueue));
    }
    return 0;
}
void addq(int a, int queue[]) {
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    if (rear == front)
        return;
    queue[rear] = a;
}
int deleteq(int queue[]) {
    if (front == rear)
        return 0;
    front = (front + 1) % MAX_QUEUE_SIZE;
    return queue[front];
}