#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning (disable:4996)
int random(int);
int main() 
{ 
	int r_su, win=0, same=0, u_su;
	char kbb[3][5] = {"����", "����", "��"};
	srand( time (0) );
	
	while(1)
	{
		r_su = random(3);		// 0~9������ ������ �߻���Ŵ

		printf("# ������ 1, ������ 2, ���� 3 �߿��� �����ϼ��� : ");
		scanf("%d", &u_su);

		printf("����� %s ����, ��ǻ�ʹ� %s ���� : ", kbb[u_su-1], kbb[r_su-1]);

		if(u_su == r_su)
		{
			printf("�����ϴ�.\n\n");
			same++;
		}
		else if((u_su == 1 && r_su == 2) || (u_su == 2 && r_su == 3) || (u_su == 3 && r_su == 1))
		{
			printf("�̰���ϴ�.\n\n");
			win++;
		}
		else
		{
			printf("����� �����ϴ�.\n");
			printf("���Ӱ�� : %d �� %d ��\n\n", win, same);
			break;
		}				
	}

	return 0;
} 
	
int random(int n) // �����߻� �Լ� - ���� �ۼ��� �Ʒ� �Լ��� �����Ͽ� �ٿ����� ����ϸ�˴ϴ�. 
{ 
	int res; 
	res = rand() % n + 1; // 0���� n-1������ ���� ���� �߻� 
	return res; 
} 