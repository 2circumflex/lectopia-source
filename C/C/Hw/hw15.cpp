/* ��¥ : 2012�� 2�� 7��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ������ �칰���� ���α׷� */
#include <stdio.h>
#pragma warning (disable : 4996)

int input();
void output(int);
int main()
{
	int cm;
	
	while(1)
	{		
		cm = input();
		
		if(cm>=0)
		{
			output(cm);
		}
		else if(cm<0)
		{
			break;
		}

	}	

	return 0;
}

int input()
{
	int num;

	printf("* �칰�� ���̸� �Է��Ͻÿ�(cm����) : ");
	scanf("%d", &num);

	return num;
}

void output(int n)
{	
	int day, dd;	
	
	if(n == 0)
	{
		day = 0;
	}
	else
	{
		dd = n - 50;
		day = 1;
		while(dd>0)
		{
			day++;
			dd -= 30;
									
			if(dd<=0)
			{
				break;
			}		
		}
	}
	printf("%.2lf���� ������ �칰�� Ż���ϱ� ���ؼ��� %d���� �ɸ��ϴ�.\n\n", n * 0.01, day);
	
	return;
}