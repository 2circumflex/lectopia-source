/* ��¥ : 2012�� 2�� 17��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : ȸ��(Palindrome) �˻��ϱ� */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#pragma warning (disable : 4996)
int check(char*, int);
int main()
{	
	char ary[20];
	int ox, stl;

	while(1)
	{
		printf("�Է� �Ͻÿ� : ");
		scanf("%s", ary);

		stl = strlen(ary);

		ox = check(ary, stl);

		if(ox == 1)
		{
			printf("ȸ���Դϴ�.\n\n");
		}
		else
		{
			printf("ȸ���� �ƴմϴ�.\n\n");
		}
	}
	
	return 0;
}

int check(char *ary, int stl)	//ȸ���˻�
{	
	int i;
	for(i=0; i<stl/2; i++)
	{
		if(tolower(ary[i]) != tolower(ary[stl-1-i]))
		{				
			return 0;
		}		
	}
	return 1;
}