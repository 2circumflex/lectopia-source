/* ��¥ : 2012�� 2�� 10��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : �Ҽ� ����ϱ� */
#include <stdio.h>
#include <math.h>
#pragma warning (disable : 4996)
int input();
void prime_number(int);
int main()
{
	int num;

	num = input();

	prime_number(num);	

	return 0;
}
int input()
{
	int su;
	
	printf("*������ �ϳ��� �Է��Ͻÿ� : ");
	scanf("%d", &su);
	
	return su;
}

void prime_number(int num)
{
	int i, j, ox, add=0;
	
	for(i=2; i<=num; i++)
	{		
		ox = 0;
		for(j=2; j<=sqrt((double)i); j++)
		{
			if(i%j==0)
			{
				ox = 1;
				break;
			}			
		}
		if(ox==0)
		{
			add++;
			printf("%-5d", i);

			if(add%5==0)
			{
				printf("\n");
			}
		}
	}
	printf("\n1~%d������ �� �Ҽ��� %d�� �Դϴ�.\n", num, add);
	
	return;
}
