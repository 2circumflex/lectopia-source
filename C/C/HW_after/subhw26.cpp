#include <stdio.h>
#pragma warning (disable:4996)
int main() 
{ 
	int cnt=0, egg;

	while(1)
	{
		printf("# ����� ���Ը� �Է��ϼ���(���� : g) : ");
		scanf("%d", &egg);

		if(egg >= 150 && egg<400)
		{
			cnt++;
		}
		else if(egg >= 400)
		{
			printf("Ÿ���� ������ �峭���� ���ÿ�^^\n");
		}
		else
		{
			printf("���߸��� ������ �峭���� ���ÿ�^^\n");
		}

		printf("*���� �ް��� �� : %d\n", cnt);

		if(cnt == 10)	break;
	}

	printf("*** �ް� ������ �������ϴ�.\n");

	return 0;
} 