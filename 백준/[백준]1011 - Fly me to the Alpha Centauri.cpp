#include <stdio.h>
#include <math.h>
int main()
{
	int t;
	long a, b;
	long long x, y;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%lld%lld", &x, &y);
		a = floor(sqrt(y - x));
		b = ceil(sqrt(y - x));
		if ((y - x) >= (a * a + b * b) / (double)2.0)
			printf("%lld\n", b * 2 - 1);
		else
			printf("%lld\n", b * 2 - 2);
	}
	return 0;
}
