/* ��¥ : 2012�� 2�� 21��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : �߱����� */
#include <stdio.h>
#include <conio.h>
#include<stdlib.h> // rand(), srand() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� �� 
#include<time.h> // time() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� ��
#pragma warning (disable : 4996)
#pragma warning (disable : 4244)
int random(int);
void rd_ary(int*);
void ary_check(int *, int *, int *, int *);
int main()
{
	int com[4], human[4];
	int i, cnt=1, ch_i, st=0, ba=0;
	char ch;

	srand( time (0) );

	rd_ary(com);	//����4�ڸ��Լ�ȣ��

	//for(i=0; i<4; i++)	//����4�ڸ�Ȯ�ο�
	//{
	//	printf("%d\t", com[i]);
	//}
	//printf("\n");

	ch_i = 0;	

	while(1)
	{
		printf("# %d�� : ", cnt);
		
		for(i=0; i<4; i++) //4�ڸ��̸��־�����츦����� 0����
		{
			human[i] = 0;
		}

		while((ch=getche())!='\r')
		{			
			if(ch-48>=0 && ch-48<=9)
			{
				human[ch_i] = ch-48;
				
				ch_i++;
			}
		}
		ch_i=0;

		printf("# %d�� : ", cnt);
		for(i=0; i<4; i++)
		{
			printf("%d ", human[i]);
		}
		
		ary_check(com, human, &st, &ba);
		if(st==4)
		{
			printf(" OK\n");
			break;
		}		
		else if(st==0 && ba==0)
		{
			printf(" No!\n");
		}
		else
		{
			printf(" %dS %dB\n", st, ba);
		}

		cnt++;
	}
	return 0;
}

void ary_check(int *c, int *h, int *s, int *b)	//������ �Է��Ѱ� ��
{
	int i, j;
	*s=0;
	*b=0;
	
	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			if(i==j && c[i] == h[j])
			{
				(*s)++;
			}
			else if(i!=j && c[i] == h[j])
			{
				(*b)++;
			}			
		}
	}
	return;
}

void rd_ary(int *com)	//����4�ڸ� �߻�
{
	int i;		

	for(i=0; i<4; i++)
	{
		com[i] = random(10);
	}		
	while(com[1]==com[0])
	{
		com[1] = random(10);
	}
	while(com[2]==com[0] || com[2]==com[1])
	{
		com[2] = random(10);
	}
	while(com[3]==com[0] || com[3]==com[1] || com[3]==com[2])
	{
		com[3] = random(10);
	}	
	return;
}

int random(int n) // �����߻��Լ�
{ 
	int res; 
	res = rand() % n; // 0���� n-1������ ���� ���� �߻� 
	return res; 
}