#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char stack[50];
int top = -1;
void push(char a);
char pop();

int main(void) {
	int t, i, status;
	char a[50], tmp;
	scanf("%d", &t);
	while (t > 0) {
		scanf("%s", a);
		status = 0;
		top = -1;
		for (i = 0; i < strlen(a); i++) {
			if (a[i] == '(')
				push(a[i]);
			else {
				tmp = pop();
				if (tmp == 'a') {
					status = 1;
					break;
				}
			}
		}

		if (status == 1 || top != -1)
			printf("NO\n");
		else
			printf("YES\n");

		t--;
	}
}

void push(char a) {
	if (top >= 49)
		return;
	stack[++top] = a;
}
char pop() {
	if (top < 0)
		return 'a';
	return stack[top--];
}