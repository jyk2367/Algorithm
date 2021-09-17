#include <stdio.h>

int main(void)
{
	int n, m;
	int result;
	int a[100] = { 0, };
	scanf("%d %d", &n, &m);
	int p = m;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if ((a[i] + a[j] + a[k]) <= m && (m - (a[i] + a[j] + a[k])) < p)
				{
					p = m - (a[i] + a[j] + a[k]);
					result = (a[i] + a[j] + a[k]);
				}
			}
		}
	}
	printf("%d", result);
}
