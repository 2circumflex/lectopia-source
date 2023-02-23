#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)


int main() 
{	
	char str[20];
	int i, len, tot, su;

	while(1)
	{
		tot = 0;
		su = 0;
		printf("ют╥б : ");
		scanf("%s", str);

		len = strlen(str);
		for(i=0; i<len; i++)
		{
			su = str[i] - '0';
			if(su >=0 && su<=9)	tot += su;
		}
		printf("%d\n\n", tot);
	}
		
	return 0;
}