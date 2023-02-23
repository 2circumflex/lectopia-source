#include <stdio.h>

int ustrlen(char *);
int ustrcmp(char *, char *);
void ustrcpy(char *, char *);
int main()
{
	char chr[10], str[20]="apple";
	int len, res;

	ustrcpy(chr, str);
	printf("str : %s, chr : %s\n", str,chr);

	len = ustrlen(chr);
	printf("str���� ���ڿ��� ���� : %d\n", len);

	res=ustrcmp("ABC", "ABCD");
	if(res==0){
		printf("�� ���ڿ��� �����ϴ�.\n");
	}
	else if(res<0){
		printf("���� ���ڿ��� ���� ���ڿ��Դϴ�.\n");
	}
	else{
		printf("���� ���ڿ��� ū ���ڿ��Դϴ�.\n");
	}

	res=ustrcmp("ABCD", "ABC");
	if(res==0){
		printf("�� ���ڿ��� �����ϴ�.\n");
	}
	else if(res<0){
		printf("���� ���ڿ��� ���� ���ڿ��Դϴ�.\n");
	}
	else{
		printf("���� ���ڿ��� ū ���ڿ��Դϴ�.\n");
	}
	res=ustrcmp("ABC", "ABC");
	if(res==0){
		printf("�� ���ڿ��� �����ϴ�.\n");
	}
	else if(res<0){
		printf("���� ���ڿ��� ���� ���ڿ��Դϴ�.\n");
	}
	else{
		printf("���� ���ڿ��� ū ���ڿ��Դϴ�.\n");
	}

	return 0;
}

int ustrlen(char *cp)
{
	int i=0, cnt=0;
	
	while(cp[i++] != '\0')
	{
		cnt++;
	}	
	return cnt;
}

void ustrcpy(char *cp1, char *cp2)
{
	while(*cp2 != '\0')
	{		
		*cp1 = *cp2;
		cp2++;
		cp1++;
	}
	*cp1='\0';
}

int ustrcmp(char *cp1, char*cp2)
{
	char ch1, ch2;

	while(1)	
	{
		ch1 = *cp1++;
		ch2 = *cp2++;

		if(ch1 > ch2)	return 1;
		else if(ch1 < ch2)	return -1;
		else if(ch1 == '\0' && ch1 == ch2)	return 0;
	}
}