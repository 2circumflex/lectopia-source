/* 날짜 : 2012년 2월 21일   
   작성자 : 이로운   
   프로그램의 기능 : string 제어 함수 만들기 ustrcpy(), ustrlen(), ustrcmp() */
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
	printf("str내의 문자열의 길이 : %d\n", len);

	res=ustrcmp("ABC", "ABCD");
	if(res==0){
		printf("두 문자열은 같습니다.\n");
	}
	else if(res<0){
		printf("앞의 문자열이 작은 문자열입니다.\n");
	}
	else{
		printf("앞의 문자열이 큰 문자열입니다.\n");
	}

	res=ustrcmp("ABCD", "ABC");
	if(res==0){
		printf("두 문자열은 같습니다.\n");
	}
	else if(res<0){
		printf("앞의 문자열이 작은 문자열입니다.\n");
	}
	else{
		printf("앞의 문자열이 큰 문자열입니다.\n");
	}
	res=ustrcmp("ABC", "ABC");
	if(res==0){
		printf("두 문자열은 같습니다.\n");
	}
	else if(res<0){
		printf("앞의 문자열이 작은 문자열입니다.\n");
	}
	else{
		printf("앞의 문자열이 큰 문자열입니다.\n");
	}

	return 0;
}

void ustrcpy(char *p1, char *p2)	//strcpy() 기능
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

int ustrlen(char *p)	//strlen() 기능
{	
	int cnt=0;
	
	while(*p!='\0')
	{
		cnt++;
		p++;
	}

	return cnt;
}

int ustrcmp(char *p1, char *p2)	//strcmp() 기능
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
