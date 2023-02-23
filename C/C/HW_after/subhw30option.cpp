#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main() 
{	
	char str[100], temp[20];
	int i=0, tot=0, cnt=0;
		
	printf("ют╥б : ");
	scanf("%s", str);	

	while(str[i++]!='\0')
	{		
		if(str[i]=='-' && cnt==0)
		{
			temp[0] = '-';
			cnt++;
		}
		else if(str[i]>='0' && str[i]<='9')
		{
			temp[cnt] = str[i];
			cnt++;
		}
		else
		{
			temp[cnt] = '\0';
			cnt=0;			
			tot+=atoi(temp);
		}
	}

	printf("%d\n", tot);	
		
	return 0;
}