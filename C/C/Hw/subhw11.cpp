/* ��¥ : 2012�� 2�� 6��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ���̵��� ���尴�� ���̿� �ο����� �Է� �޾� ����Ḧ ����Ͽ� ����ϱ� */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int age, su, tot, tmoney, per;
	
	while(1)
	{
		printf("���尴�� ���̸� �Է��Ͻÿ� : ");
		scanf("%d", &age);

		printf("���尴�� ���� �Է��Ͻÿ� : ");
		scanf("%d", &su);

		if(age >= 56 || age<=7)
		{
			tmoney = 500;
		}
		else if(age >=20)
		{
			tmoney = 1500;
		}
		else if(age >=14)
		{
			tmoney = 1000;
		}
		else if(age >=8)
		{
			tmoney = 700;
		}
		

		if(su>=5)
		{
			per = (int)(tmoney * su * 0.1);
			tmoney = tmoney * su;
			tot = tmoney - per;
		}
		else
		{
			tmoney = tmoney * su;
			per = 0;
			tot = tmoney - per;
		}

		printf("����� => %d��\n", tmoney);
		printf("���αݾ� => %d��\n", per);
		printf("�����ݾ� => %d��\n\n", tot);
	}

	return 0;
}