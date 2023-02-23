/* ��¥ : 2012�� 2�� 17��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ȯǳ�� ���� ���α׷� */
#include <stdio.h>
#include <conio.h>
#pragma warning (disable : 4996)
int menu();
char fanOpen(char);
char fanOff(char);
char fanReverse(char);
char fanDisplay(char);
int main()
{
	char fan=0x00, res;
	int m_num;

	while(1)
	{
		m_num = menu();
		if(m_num == 1)
		{
			res = fanOpen(fan);
		}
		else if(m_num == 2)
		{
			res = fanOff(fan);
		}
		else if(m_num == 3)
		{
			res = fanReverse(fan);
		}
		else
		{			
			break;
		}
		fan = fanDisplay(res);
	}
	return 0;
}

char fanOpen(char fan)	//ȯǳ�� ����
{	
	int num;	
	printf("--------------------------------------------------------------------\n");
	printf("\t\t\tFan ���� �۾� ���� ȭ��\n");
	printf("--------------------------------------------------------------------\n");
	printf(" * OPEN�� FAN ��ȣ�� �Է��Ͻÿ�(1-8) : ");
	while(1)
	{
		fflush(stdin);
		scanf("%d", &num);
		if(num>=1 && num<=8) 
		{
			num--;
			break;
		}
		else
		{
			printf("�߸� �Է��߽��ϴ�. �ٽ��Է��Ͻÿ� : ");		
		}		
	}
	fan = fan|(0x01<<num);
	return fan;
}

char fanOff(char fan)	//ȯǳ�� �ݱ�
{
	int num;	
	printf("--------------------------------------------------------------------\n");
	printf("\t\t\tFan �ݱ� �۾� ���� ȭ��\n");
	printf("--------------------------------------------------------------------\n");
	printf(" * OFF�� FAN ��ȣ�� �Է��Ͻÿ�(1-8) : ");
	while(1)
	{
		fflush(stdin);
		scanf("%d", &num);
		if(num>=1 && num<=8) 
		{
			num--;
			break;
		}
		else
		{
			printf("�߸� �Է��߽��ϴ�. �ٽ��Է��Ͻÿ� : ");		
		}		
	}

	if((fan&(0x01<<num)) != 0)
	{
		fan = fan^(0x01<<num);
	}	
	
	return fan;
}

char fanReverse(char fan)	//ȯǳ�� on/off ������ �ٲٱ�
{
	fan = ~fan;
	return fan;
}

char fanDisplay(char fan)	//ȯǳ�� ���� ���
{	
	int i;
	printf("--------------------------------------------------------------------\n");

	for(i=8; i>=1; i--)
	{
		printf("%d��FAN\t",i);
	}
	printf("\n");

	for(i=7; i>=0; i--)
	{		
		if((fan&(0x01<<i))==0)
		{
			printf("  OFF\t");
		}
		else
		{
			printf("  ON\t");
		}
	}
	printf("\n");
	printf("--------------------------------------------------------------------\n");	
	return fan;
}

int menu(void)	//�޴�
{
	int num;

	printf("1. ȯǳ�� ���� / 2. ȯǳ�� �ݱ� / 3. ȯǳ�� ��ü ��ȯ / 4. ���� : ");
	while(1)
	{		
		fflush(stdin);
		scanf("%d", &num);	
		
		if(num>=1 && num<=4) { break; }
		else
		{
			printf("�߸� �Է��߽��ϴ�. �ٽ��Է��Ͻÿ� : ");
			getch();
			
		}
	}
	return num;
}