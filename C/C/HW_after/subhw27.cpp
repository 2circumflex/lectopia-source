#include <stdio.h>
#pragma warning (disable:4996)
int main() 
{ 
	int ssu, esu, tot;
	int i;
	char eo;

	while(1)
	{
		tot=0;
		printf("# ���۰��� �Է��Ͻÿ� : ");
		scanf("%d", &ssu);

		while(1)
		{
			printf("# ������ �Է��Ͻÿ� : ");
			scanf("%d", &esu);

			if(esu>ssu)	break;
		}

		printf("* %d ���� %d ������ ¦���� ���� ���ұ��? Ȧ���� ���� ���ұ��?(¦��:e/Ȧ��:o) : ", ssu, esu);
		fflush(stdin);
		scanf("%c", &eo);

		printf("%d ���� %d ������ ", ssu, esu);

		if(eo == 'e')	printf("¦��(");
		else if(eo == 'o')	printf("Ȧ��(");

		for(i=ssu; i<=esu; i++)
		{
			if(eo == 'e' && i%2 == 0)
			{
				printf("%d ", i);
				tot += i;
			}
			else if(eo == 'o' && i%2 == 1)
			{
				printf("%d ", i);
				tot += i;
			}
		}

		printf("\b)�� ���� %d �Դϴ�.\n\n", tot);
	}

	return 0;
} 