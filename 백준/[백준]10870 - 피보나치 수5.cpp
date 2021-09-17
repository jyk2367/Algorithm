#include <stdio.h>
int factorial(int n);
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", factorial(n));
}
int factorial(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else if (n >= 2)
		return factorial(n - 1) + factorial(n - 2);
}