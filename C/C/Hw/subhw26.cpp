/* ��¥ : 2012�� 2�� 17��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : �ް� �����ϱ� */
#include <stdio.h>
#pragma warning (disable : 4996)
int main()
{	
	int egg, cnt=0;
	while(1)
	{
		printf("# ����� ���Ը� �Է��ϼ���(���� : g) : ");
		scanf("%d", &egg);

		if(egg >=150 && egg <= 400)
		{
			cnt++;
		}
		else if(egg<150)
		{
			printf("*���߸��� ������ �峭���� ���ÿ�~ ^^\n");
		}
		else if(egg>400)
		{
			printf("Ÿ���� ������ �峭���� ���ÿ�~ ^^\n");
		}

		printf("* ���� �ް��� �� : %d\n", cnt);

		if(cnt == 10)
		{
			printf("\n*** �ް� ������ �������ϴ�\n");
			break;
		}
	}

	return 0;
}