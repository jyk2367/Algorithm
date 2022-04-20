#include <stdio.h>
void dn();
int main(void)
{
	dn();
	return 0;
}
void dn()
{
	int a[10001] = { 0, };
	int i, p = 0, sum = 0;
	for (i = 0; i < 10001; i++)
	{
		sum = i;
		for (p = i; p!=0;p /= 10)
		{
			sum +=p%10;
		}
		if (sum < 10000) {
			a[sum]++;
		}
		sum = 0;
	}
	for (i = 0; i < 10000; i++)
	{
		if (a[i] == 0)
			printf("%d\n", i);
	}
}