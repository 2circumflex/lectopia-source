/* ��¥ : 2012�� 2�� 17��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ���� 3500������ ũ����(500��), �����(700��), �ݶ�(400��) ��� */
#include <stdio.h>
int main()
{	
	int i,j,k, cream=500, kang=700, coke=400, money=3500;

	for(i=1; i<(money/cream); i++)
	{
		for(j=1; j<(money/kang); j++)
		{
			for(k=1; k<(money/coke); k++)
			{
				if( (cream*i)+(kang*j)+(coke*k) == money )
				{
					printf("ũ����(%d��), �����(%d��), �ݶ�(%d��)\n", i, j, k);
				}				
			}
		}
	}
	printf("��� �����Ͻðڽ��ϱ�?\n");

	return 0;
}