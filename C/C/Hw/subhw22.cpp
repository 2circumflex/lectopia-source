/* ��¥ : 2012�� 2�� 17��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ���� ���� �� ���� */
#include <stdio.h>
#include<stdlib.h> // rand(), srand() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� �� 
#include<time.h> // time() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� �� 
#include<stdio.h> 
int random(int);
#pragma warning (disable : 4996)
int main()
{	
	int rsu, su, vcnt=0, mcnt=0;
	char kbb[3][5] = {{"����"}, {"����"}, {"��"}};

	while(1)
	{
		rsu = random(3);

		printf("# [����1], [����2], [��3] �߿��� �����ϼ��� : ");
		scanf("%d", &su);

		if(su == rsu)
		{
			mcnt++;	
			printf("����� %s ����, ��ǻ�ʹ� %s ���� : �����ϴ�.\n\n", kbb[su-1], kbb[rsu-1]);
		}
		else if( (su == 1 && rsu == 2) || (su == 2 && rsu == 3) || (su == 3 && rsu == 1) )
		{
			vcnt++;
			printf("����� %s ����, ��ǻ�ʹ� %s ���� : �̰���ϴ�.\n\n", kbb[su-1], kbb[rsu-1]);
		}
		else if( (su == 1 && rsu == 3) || (su == 2 && rsu == 1) || (su == 3 && rsu == 2) )
		{
			printf("����� %s ����, ��ǻ�ʹ� %s ���� : ����� �����ϴ�.\n\n", kbb[su-1], kbb[rsu-1]);
			printf("���Ӱ�� : %d �� %d ��\n\n", vcnt, mcnt);
			break;
		}		
	}	

	return 0;
}

int random(int n)	//�����߻�
{ 
	int res; 
	res = (rand() % n)+1; // 0���� n-1������ ���� ���� �߻� 
	return res; 
} 