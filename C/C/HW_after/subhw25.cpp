#include <stdio.h>
int main() 
{ 
	int pay = 3500;
	int cream = 500;
	int kang = 700;
	int coke = 400;

	int i,j,k;

	printf("���� ����� �����ϰ� �ִ� �ݾ� : %d��\n", pay);

	for(i=1; i<=((pay-kang-coke)/cream); i++)
	{
		for(j=1; j<=((pay-cream-coke)/kang); j++)
		{
			for(k=1; k<=((pay-cream-kang)/coke); k++)
			{
				if((cream*i)+(kang*j)+(coke*k)==pay)
				{
					printf("ũ����(%d ��), �����(%d ����), �ݶ�(%d ��)\n", i,j,k);
				}
			}
		}
	}
	printf("��� �����Ͻðڽ��ϱ�?\n");

	return 0;
} 