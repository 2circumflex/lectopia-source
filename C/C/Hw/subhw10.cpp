/* ��¥ : 2012�� 2�� 6��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ����, Ű, ������ �Է¹޾� ����ϱ� */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	char name[25];
	double height;
	char sex;
	
	while(1)
	{
		printf("# ���� �Է� : ");
		gets(name);

		printf("# Ű �Է�(cm����) : ");
		scanf("%lf", &height);

		fflush(stdin);

		printf("# ���� �Է�(M/F) : ");
		scanf("%c", &sex);

		fflush(stdin);

		if(sex == 'M' || sex == 'm')
		{
			printf("%s���� Ű�� %.2lfcm�̰� �����Դϴ�.\n\n", name, height);
		}
		else if(sex == 'F' || sex == 'f')
		{
			printf("%s���� Ű�� %.2lfcm�̰� �����Դϴ�.\n\n", name, height);
		}
	}

	return 0;
}