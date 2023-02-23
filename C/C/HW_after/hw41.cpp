#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable:4996)

void input(char **, int);
void mySort(char **, int);
void output(char **, int);

int main()
{
	char *p[5];
	int cnt = sizeof(p)/sizeof(p[0]);

	input(p, cnt);
	mySort(p, cnt);
	output(p, cnt);
	
	return 0;
}

void output(char **cp, int cnt)
{
	int i;

	for(i=0; i<cnt; i++)
	{
		printf("%d. %s\n", i+1, cp[i]);
	}
}

void mySort(char **cp, int cnt)
{
	int i, j;
	char *tmp;
	
	for(i=0; i<cnt-1; i++)
	{
		for(j=i+1; j<cnt; j++)
		{
			if(strcmp(cp[i], cp[j]) > 0)
			{
				tmp = (char*)malloc(strlen(cp[i])+1);

				strcpy(tmp, cp[i]);
				strcpy(cp[i], cp[j]);
				strcpy(cp[j], tmp);

				free(tmp);
			}
		}
	}

}

void input(char **cp, int cnt)
{
	int i;
	char str[20];

	for(i=0; i<cnt; i++)
	{
		printf("# ¹®ÀÚ¿­ %d : ", i+1);
		scanf("%s", str);
		cp[i] = (char*)malloc(sizeof(char) * (strlen(str) + 1));
		strcpy(cp[i], str);
	}
	printf("\n");
}