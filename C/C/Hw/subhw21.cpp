/* ��¥ : 2012�� 2�� 17��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ���� ���߱� ���� */
#include <stdio.h>
#include<stdlib.h> // rand(), srand() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� �� 
#include<time.h> // time() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� �� 
#include<stdio.h> 
int random(int);
#pragma warning (disable : 4996)
#pragma warning (disable : 4244)
char su_check(int*, int, int*, int*);
int main()
{	
	int rsu, cnt=0, su, a=0, b=101;
	char ox;
	srand( time (0) );
	rsu = random(100);
		
	while(1)
	{
		printf("# ���ڸ� �Է��Ͻÿ�(1~100) : ");
		scanf("%d", &su);
		cnt++;
		ox = su_check(&rsu, su, &a, &b);
		if(ox=='o')
		{
			printf("���~ �¾Ҵ�~~~ ��ī��ī~~ %d ��° ���߼̽��ϴ�.\n", cnt);
			a = 0;
			b = 101;
			cnt = 0;
		}
		else if(ox=='x')
		{
			printf("%d ���ٴ� ũ�� %d ���ٴ� �۽��ϴ�.\n", a, b);
		}	
	}

	return 0;
}

char su_check(int *rsu, int su, int *a, int *b)	//üũ
{
	if(su==(*rsu))
	{
		return 'o';
	}
	else if(su > *rsu && *b >= su)
	{
		*b = su;		
	}
	else if(su < *rsu && su >= *a)
	{
		*a = su;		
	}
	return 'x';
}

int random(int n)	//�����߻�
{ 
	int res; 
	res = (rand() % n)+1; // 0���� n-1������ ���� ���� �߻� 
	return res; 
} 