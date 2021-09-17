#include <stdio.h>

int main()
{
	int t=0, M,N,p=0;
	int cnt = 0;
	scanf("%d%d", &M,&N);
	for (int i = M; i <=N; i++)
	{
		if (i == 2) {
			t = 2;
			p=1;
			cnt += 2;
		}
		for (int j = 2; j < i; j++) 
		{
			if (i % j == 0)
				break;
			else if(j==i-1)
			{
				cnt += i;
				if (p == 0) 
				{
					t = i;
					p = 1;
				}
			}
		}
	}
	if (cnt == 0) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n%d\n", cnt, t);
}