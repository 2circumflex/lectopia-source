/* ��¥ : 2012�� 2�� 2��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : 1���� 365.2422���̴�. �̴� ����, ��ð�, ���, ���� �ΰ��� ����ϱ�	*/
#include <stdio.h>
int main()
{
	double day = 365.2422;
	double sec;
	int iday, hour, min;	
	
	iday = (int)day;
	hour = (int)((day - iday) * 24);	
	min = (int)(((day - iday) * 24 - hour) * 60);
	sec = (((day - iday) * 24 - hour) * 60 - min) * 60;

	printf("%.4lf���� %d�� %d�ð� %d�� %.2lf���Դϴ�.\n", day, iday, hour, min, sec);

	return 0;
}