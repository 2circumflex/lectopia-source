#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning (disable:4996)
int random(int);
int main() 
{ 
	int r_su, su, b_su=0, a_su=101, cnt=0;
	srand( time (0) );			
							
	r_su = random(100) + 1;		// 0~9������ ������ �߻���Ŵ
	
	while(1)
	{
		cnt++;
		printf("# ���ڸ� �Է��Ͻÿ� : ");
		scanf("%d", &su);

		if(su == r_su)
		{
			printf("���~ �¾Ҵ�~~~ ��ī��ī~~ %d��° ���� ���߼̽��ϴ�.\n", cnt);
			break;
		}
		else
		{
			if(r_su>su)
			{
				b_su = su;
			}
			else
			{
				a_su = su;
			}
			
			printf("%d���ٴ� ũ�� %d ���ٴ� �۽��ϴ�.\n", b_su, a_su);
		}	
	}		

	return 0;
} 
	
int random(int n) // �����߻� �Լ� - ���� �ۼ��� �Ʒ� �Լ��� �����Ͽ� �ٿ����� ����ϸ�˴ϴ�. 
{ 
	int res; 
	res = rand() % n; // 0���� n-1������ ���� ���� �߻� 
	return res; 
} 