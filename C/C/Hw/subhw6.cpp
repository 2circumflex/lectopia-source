/* ��¥ : 2012�� 2�� 6��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : �����Կ� Ű�� �Է¹޾� ��ü��������(BMI)�� ���ϰ� �񸸵��� ������ִ� ���α׷� */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	double height, kg, bmi;
	
	while(1)
	{
		printf("�����Ը� �Է��ϼ���(kg) : ");
		scanf("%lf", &kg);
		printf("Ű�� �Է��ϼ���(m) : ");
		scanf("%lf", &height);

		bmi = kg / (height * height);

		if(bmi >= 40.0)
		{
			printf("����� BMI�� %.1lf���� �����Դϴ�\n\n", bmi);
		}
		else if(bmi>=30.0)
		{
			printf("����� BMI�� %.1lf���� ���Դϴ�\n\n", bmi);
		}
		else if(bmi>=25.0)
		{
			printf("����� BMI�� %.1lf���� ��ü���Դϴ�\n\n", bmi);
		}
		else if(bmi>=18.5)
		{
			printf("����� BMI�� %.1lf���� ����ü���Դϴ�\n\n", bmi);
		}
		else
		{
			printf("����� BMI�� %.1lf���� ��ü���Դϴ�\n\n", bmi);
		}		
	}

	return 0;
}