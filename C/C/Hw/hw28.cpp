/* ��¥ : 2012�� 2�� 13��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ���� ���ϴ� ���α׷� */
#include <stdio.h> 
#include <string.h>
#pragma warning (disable : 4996)
void input(int*, int*, int*);
int year_check(int);
int main(void) 
{
	int year, month, day, tot, i, y_chk;
	char yoil[7];
	int m_ary[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	while(1)
	{
		tot = 0;
		input(&year, &month, &day);	//����� �Է¹ޱ�

		for(i=1; i<=year-1; i++)		//�⵵�� �ѳ���
		{
			y_chk = year_check(i);

			if(y_chk == 1)
			{
				tot += 366;
			}
			else
			{
				tot += 365;
			}
		}

		for(i=0; i<month-1; i++)		//���� �ѳ���
		{
			tot += m_ary[i];
		}

		tot += day;	//���� �ѳ���
		
		if((year_check(year)) == 1 && month >= 3)	//��������
		{
			tot++;
		}

		switch(tot%7)
		{
			case 0 : strcpy(yoil, "�Ͽ���"); break;
			case 1 : strcpy(yoil, "������"); break;
			case 2 : strcpy(yoil, "ȭ����"); break;
			case 3 : strcpy(yoil, "������"); break;
			case 4 : strcpy(yoil, "�����"); break;
			case 5 : strcpy(yoil, "�ݿ���"); break;
			case 6 : strcpy(yoil, "�����"); break;
		}

		printf("%d�� %d�� %d���� %s�Դϴ�.\n\n", year, month, day, yoil);
	}

	return 0; 
}

void input(int *y, int *m, int *d)	//����� �Է��Լ�
{
	printf("* ������� �Է��Ͻÿ� : ");
	scanf("%d %d %d", y, m, d);
}

int year_check(int y)	//���� ����Լ�
{
	if (y%4 != 0)
	{
		return 0;
	}
	else if (y%100 != 0)
	{
		return 1;
	}
	else if (y%400 != 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}