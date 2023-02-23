/* ��¥ : 2012�� 2�� 21��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : string ���� �Լ� ����� ustrcpy(), ustrlen(), ustrcmp() */
#include<stdio.h>

void ustrcpy(char *, char *);
int ustrlen(char *);
int ustrcmp(char *, char *);

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

void ustrcpy(char *p1, char *p2)	//strcpy() ���
{		
	while(*p2!='\0')
	{
		*p1 = *p2;

		p1++;
		p2++;
	}
	*p1 = '\0';
	
	return;
}

int ustrlen(char *p)	//strlen() ���
{	
	int cnt=0;
	
	while(*p!='\0')
	{
		cnt++;
		p++;
	}

	return cnt;
}

int ustrcmp(char *p1, char *p2)	//strcmp() ���
{
	while(*p1==*p2)
	{
		if(*p1=='\0')
		{
			return 0;
		}
		p1++;
		p2++;
	}

	if(*p1>*p2)
	{
		return 1985;
	}
	else
	{
		return -1985;
	}
}
