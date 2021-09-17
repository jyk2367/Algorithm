#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);
	int xa, ya, ra, xb, yb, rb;
	int cnt = 0;
	for (int i = 0; i < t; i++)
	{
		scanf("%d%d%d%d%d%d", &xa, &ya, &ra, &xb, &yb, &rb);
		if (xa == xb && ya == yb && ra == rb)
			printf("-1\n");//두 원이 일치
		else if ((ra + rb) * (ra + rb) == (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb))
			printf("1\n");//두 원이 외접할 때, 답은 1
		else if ((ra - rb) * (ra - rb) == (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb))
			printf("1\n");
		else if ((ra + rb) * (ra + rb) < (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb))
			printf("0\n");//두 원이 서로 떨어져 있고 만나지 않을 때, 답은 0
		else if ((ra - rb) * (ra - rb) > (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb))
			printf("0\n");//한 원이 다른 원의 내부에 있고 두 원이 만나지 않을 때, 답은 0. 꼭 두 원의 중심이 같을 필요는 없습니다!
		else
			printf("2\n");
	}
}