#include <stdio.h>
int main()
{
	int T, W, H, N;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d%d%d", &H, &W, &N);
		if (N % H != 0)
			printf("%d\n", (N % H) * 100 + N / H + 1);
		else if (N % H == 0)
			printf("%d\n", (H * 100) + (N / H));
	}
}