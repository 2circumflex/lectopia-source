/* ��¥ : 2012�� 2�� 2��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ����Ÿ��� �ü��� �Է� �޾� ����ð��� ����Ͽ� ����ϱ�	*/
#include <stdio.h>
int main()
{
	double dist, speed;
	int hour, min;
	double sec;
	
	printf("����Ÿ� �Է� : ");
	scanf("%lf", &dist);

	printf("�ü��� �Է� : ");
	scanf("%lf", &speed);

	hour = (int)(dist / speed);
	min = (dist / speed - hour) * 60;
	sec = ((dist / speed - hour) * 60 - min) * 60;
	
	printf("%.0lf km => %d�ð� %d�� %.3lf�� �ҿ��\n", dist, hour, min, sec);

	return 0;
}