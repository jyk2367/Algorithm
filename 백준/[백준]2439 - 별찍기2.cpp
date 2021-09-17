#include <stdio.h>
int main(void)
{
	int N, i, j, p;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		p = i;
		for (j = i; j < N; j++)
		{
			printf(" ");
		}
		for (; p > 0; p--)
		{
			printf("*");
		}
		printf("\n");
	}
}