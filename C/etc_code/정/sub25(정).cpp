// subhw25  �������� ũ����, �����, �ݶ� �����ϱ�
// ���α׷��� : �����Ǿ� ������ ����


#include<stdio.h>
#include<conio.h>

int main()
{
	int i,j,k;
	long money=3500;
	
	for(i=1; i*500<=money; i++)
	{
		for(j=1; j*700<=money; j++)
		{
			for(k=1; k*400<=money; k++)
			{
				if((i*500+j*700+k*400)==money) // ������ ������ ������ ������ �ݾ��� 3500�� �̸� ������ �����.
				{ 
					printf("ũ����(%d��), �����(%d����), �ݶ�(%d��) \n", i,j,k);
				}
			}
		}
	}
	printf("��� �����Ͻðڽ��ϱ�?\n");
    return 0;

}