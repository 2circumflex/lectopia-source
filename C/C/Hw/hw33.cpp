/* ��¥ : 2012�� 2�� 15��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ������ ��Ʈ ���α׷� */
#include <stdio.h>
#pragma warning (disable : 4996)
void input_num(int *);
void output(int *);
int main() 
{
	int num[10];

	while(1)
	{
		input_num(num);
		output(num);
	}
			
	return 0;
}

void input_num(int *num)	// �Է��Լ�
{
	int i;

	fflush(stdin);
	for(i=0; i<10; i++)
	{
		printf("[%d]���� : ", i);
		scanf("%d", &num[i]);
	}

	return;
}

void output(int *num)	// sort & ��� �Լ�
{
	int i, j, tmp;
	
	printf("\n��������!!\n");

	for(i=0; i<=9; i++)
	{
		for(j=i+1; j<10; j++)
		{
			if(num[i] < num[j])
			{
				tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
		}

		printf("%d ", num[i]);
	}
	printf("\n\n");	

	return;
}