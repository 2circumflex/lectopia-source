/* ��¥ : 2012�� 2�� 17��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : �迭�� ������ ���ڸ� �ʱ�ȭ�� �Ŀ� �� ���ڵ��� ��ġ�� �ݴ�� �ٲٴ� ���α׷� */
#include <stdio.h>
#include<stdlib.h> // rand(), srand() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� �� 
#include<time.h> // time() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� �� 
#pragma warning (disable : 4996)
int random(int);
int main()
{	
	int rsu, *p, i, tmp;
	srand( time (0) );
	
	rsu = random(20);
	p = (int *)malloc(rsu * sizeof(int));	//�����޸� �Ҵ�

	for(i=0; i<rsu; i++)	//�迭�� ������ �Է�
	{
		p[i] = random(100);
	}

	printf("ó�� �迭�� ����� �� : ");		//ó���� ����ϱ�
	for(i=0; i<rsu; i++)
	{
		printf("%2d ", p[i]);
	}
	printf("\n");
	
	for(i=0; i<rsu/2; i++)	//swap
	{		
		tmp = p[i];
		p[i] = p[rsu-1-i];
		p[rsu-1-i] = tmp;
	}

	printf("�ٲ� �迭�� ����� �� : ");		//�ٲﰪ ����ϱ�
	for(i=0; i<rsu; i++)
	{
		printf("%2d ", p[i]);
	}
	printf("\n\n");

	free(p);

	return 0;	
}

int random(int n)	//�����߻�
{ 
	int res; 
	res = (rand() % n)+1; // 0���� n-1������ ���� ���� �߻� 
	return res; 
}