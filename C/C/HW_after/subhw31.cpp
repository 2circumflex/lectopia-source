#include <stdio.h>
#pragma warning (disable : 4996)
int main()
{	
	double su_ary[5], su=0;
	int i;

	printf("�ټ� ���� ���ڸ� �Է��ϼ��� : ");
	for(i=0; i<5; i++)
	{
		scanf("%lf", &su_ary[i]);
		if(su_ary[i]>su)	su = su_ary[i];
	}

	printf("���� ū ���� %.2lf �Դϴ�.\n", su);
	
	return 0;
}