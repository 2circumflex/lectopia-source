#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "pattern.h"

int myStr(char *sp, char **tp, int su);

int main()
{
	LinkedList List;
	Node *res;
	FILE * fp = fopen("pattern_data.txt", "rt");
	int su, ch;
	char str[100];
	char *sp;
	char *tp;
	Pattern ptn;		

	printf("* 검사할 패턴의 길이를 입력하시오 : ");
	scanf("%d", &su);
	//예외처리하기
	


	while(!feof(fp))
	{
		create(&List);
		fgets(str, 100, fp);
		str[strlen(str)-1] = '\0';
	
		res = NULL;
		sp = str;
		while(1)
		{
			tp = (char*)malloc(su + 1);
			
			strncpy(tp, sp, su);	
			tp[su] = '\0';
			if(tp[su-1] == '\0')
			{
				free(tp);
				break;
			}
			//printf("%s ", tp);
			//free(tp);
			sp+=1;
			
			ptn.pstr = (char*)malloc(strlen(tp)+1);
			strcpy(ptn.pstr, tp);
			ptn.pcnt = 1;
			//printf("%s %d", ptn.pstr, ptn.pcnt);
			free(tp);
			res = searchUnique(&List, &ptn, ptnNameCompare);

			if(res != NULL)
			{
				List.curp = res;
				ptn.pcnt = ((Pattern*)(List.curp+1))->pcnt + 1;
				ptnMemCopy(List.curp+1, &ptn);
				free(ptn.pstr);
			}
			else
			{
				appendFromTail(&List, &ptn, sizeof(Pattern), ptnMemCopy);		
			}
		}
		sort(&List, sizeof(Pattern), ptnNameCompare, ptnMemCopy);
		display(&List, ptnPrint);
		destroy(&List, ptnFree);
		printf("\n\n");
	}
				
	fclose(fp);
}