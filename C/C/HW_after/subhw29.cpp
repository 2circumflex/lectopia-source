#include <stdio.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)

int palindrome(char *);

int main() 
{	
	char word[10];	
	int p_res;
	
	while(1)
	{
		fflush(stdin);
		printf("�ܾ��Է� : ");
		scanf("%s", word);

		p_res = palindrome(word);

		if(p_res == 1)	printf("ȸ���Դϴ�.\n\n");
		else if(p_res == 0)	printf("ȸ���� �ƴմϴ�.\n\n");		
	}
		
	return 0;
}

int palindrome(char *word)
{
	int i, len;
	len = strlen(word);
	
	for(i=0; i<len/2; i++)
	{
		if(toupper(word[i])!=toupper(word[len-1-i]))	return 0;
	}

	return 1;
}