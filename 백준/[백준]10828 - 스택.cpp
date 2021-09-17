#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_STACK_SIZE 10000


int stack[MAX_STACK_SIZE];
static int top = -1;

void push(int item);
int pop();

bool IsEmpty();
bool IsFull();

int main(void) {
	int cmdsize;
	scanf("%d", &cmdsize);

	int x;
	while ((cmdsize--) > 0) {
		char cmd[10];
		scanf("%s", cmd);
		if (strcmp(cmd, "push") == 0)
		{
			scanf("%d", &x);
			push(x);
		}
		else if (strcmp(cmd, "pop") == 0)
		{
			printf("%d\n", pop());
		}
		else  if (strcmp(cmd, "size") == 0)
		{
			printf("%d\n", top + 1);
		}
		else  if (strcmp(cmd, "empty") == 0)
		{
			if (top == -1)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strcmp(cmd, "top") == 0) {

			if (top == -1)
				printf("-1\n");
			else
				printf("%d\n", stack[top]);
		}

	}
	return 0;


}

void push(int item) {
	if (IsFull())
		return;
	stack[++top] = item;
}
int pop() {
	if (IsEmpty())
		return -1;
	return stack[top--];
}




bool IsEmpty() {
	if (top < 0)
		return true;
	else
		return false;
}
bool IsFull() {
	if (top >= (MAX_STACK_SIZE - 1))
		return true;
	else
		return false;
}