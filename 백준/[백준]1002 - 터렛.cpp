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
			printf("-1\n");//�� ���� ��ġ
		else if ((ra + rb) * (ra + rb) == (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb))
			printf("1\n");//�� ���� ������ ��, ���� 1
		else if ((ra - rb) * (ra - rb) == (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb))
			printf("1\n");
		else if ((ra + rb) * (ra + rb) < (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb))
			printf("0\n");//�� ���� ���� ������ �ְ� ������ ���� ��, ���� 0
		else if ((ra - rb) * (ra - rb) > (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb))
			printf("0\n");//�� ���� �ٸ� ���� ���ο� �ְ� �� ���� ������ ���� ��, ���� 0. �� �� ���� �߽��� ���� �ʿ�� �����ϴ�!
		else
			printf("2\n");
	}
}