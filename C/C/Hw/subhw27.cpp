/* ��¥ : 2012�� 2�� 17��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ���۰� �� �� �Է¹ް� �ΰ����̿� Ȧ���� ¦���� ����ϰ� �� ���ϱ� */
#include <stdio.h>
#pragma warning (disable : 4996)
int main()
{	
	int start, end, esum=0, osum=0, sum, i;
	char eo;

	while(1)
	{
		osum = 0;
		esum = 0;
		printf("# ���۰��� �Է��Ͻÿ� : ");
		scanf("%d", &start);
		while(1)
		{		
			printf("# ������ �Է��Ͻÿ� : ");
			scanf("%d", &end);

			if(end>start)
			{
				break;
			}
		}
		fflush(stdin);
		printf("* %d ���� %d ������ ¦���� ���� ���ұ��?\n  Ȧ���� ���� ���ұ��?(¦��:e/Ȧ��:o) : ", start, end);
		scanf("%c", &eo);

		printf("* %d ���� %d ������ ", start, end);
		if(eo=='e') printf("¦��(");
		else printf("Ȧ��(");

		for(i=start; i<=end; i++)
		{
			if(eo == 'e' && i%2 == 0)
			{
				printf("%d ", i);
				esum += i;
			}
			else if(eo == 'o' && i%2 != 0)
			{
				printf("%d ", i);
				osum += i;
			}
		}
		(eo == 'e') ? (sum = esum) : (sum = osum);
		printf("\b)�� ���� %d �Դϴ�.\n\n", sum);	
	}	
	
	return 0;
}