/* ��¥ : 2012�� 2�� 7��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : 5���� �л��� Ű�� �Է¹޾� ����� ���� ����ϱ� */
#include <stdio.h>
#pragma warning (disable : 4996)

double input();
void output(double);
int main()
{
	double totkey;

	while(1)
	{
		totkey = input();
		output(totkey);	
	}

	return 0;
}

double input()
{
	int i = 1;
	double key, tot=0;
	
	while(i<=5)
	{
		printf("- %d�� �л��� Ű��? ", i);
		scanf("%lf", &key);

		tot += key;
		i++;
	}	

	return tot;
}

void output(double avgkey)
{
	printf("�ټ����� ��� Ű�� %.1lf �Դϴ�.\n\n", avgkey/5);

	return;
}