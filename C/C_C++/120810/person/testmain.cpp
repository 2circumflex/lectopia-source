#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "person.h"


void intMemCopy(void *, void *);
void intPrint(void *p);
int intCompare(void *p1, void *p2);
void intFree(void *p);


//person
void input(LinkedList *lp);
Node* search(LinkedList *lp);
void pInput(LinkedList *lp, Node *res);


int main()
{
	LinkedList List;
	Node *res;
	Person tmp;

	create(&List);
	input(&List);
	display(&List, PersonPrint);
	printf("\n");
	res = search(&List);
	if(res!=NULL) {	pInput(&List, res);}
	display(&List, PersonPrint);

	printf("삭제할 ");
	res = search(&List);
	if(res!=NULL) {	nodeDelete(&List, res, PersonFree);}
	display(&List, PersonPrint);

	sort(&List, sizeof(Person), PersonnameCompare, PersonMemCopy);
	display(&List, PersonPrint);

	printf("***");
	destroy(&List, PersonFree);	
}



void pInput(LinkedList *lp, Node *res)
{
	int menu, size;
	char name[100];
	Person psn;
	
	while(1)
	{
		printf("찾은 이름은 %s이고 나이는 %d살입니다\n", ((Person*)res+1)->name, ((Person*)res+1)->age);
		printf("앞에 입력 1	뒤에 입력 2 : ");
		scanf("%d", &menu);

		fflush(stdin);
		printf("이름 : ");
		scanf("%s", name);
		printf("나이 : ");
		scanf("%d", &psn.age);

		psn.name = (char*)malloc(sizeof(strlen(name)+1));
		strcpy(psn.name, name);

		size = sizeof(int) + sizeof(strlen(name)+1);

		if(menu==1)
		{
			insertBefore(lp, res, &psn, size, PersonMemCopy);
			return;
		}
		else if(menu==2)
		{
			insertAfter(lp, res, &psn, size, PersonMemCopy);
			return;
		}
	}
}

//검색
Node* search(LinkedList *lp)
{
	Node * res;
	int  menu;
	Person psn;
	Person *pp;
	char name[100];
	
	
	fflush(stdin);
	printf("나이검색(1)/이름검색(2)/종료(3) : ");
	scanf("%d", &menu);

	if(menu==1)
	{
		fflush(stdin);
		printf("나이입력 : ");
		scanf("%d", &(psn.age));
		pp = &psn;
		res = searchUnique(lp, pp, PersonageCompare);
		return res;
	}
	else if(menu==2)
	{
		fflush(stdin);
		printf("이름입력 : ");
		scanf("%s", name);
		psn.name = (char*)malloc(strlen(name)+1);
		strcpy(psn.name, name);
		pp = &psn;
		res = searchUnique(lp, pp, PersonnameCompare);
		return res;
	}
	
}

//입력
void input(LinkedList *lp)
{
	char str[200];
	char * tmp;
	int size;
	Person psn;	

	while(1)
	{
		fflush(stdin);
		printf("이름을 입력하세요(end종료) : ");
		scanf("%s", str);
		if(strcmp(str, "end")==0)	{break;}
		printf("나이를 입력하세요 : ");
		scanf("%d", &psn.age);
		printf("\n");		
				
		tmp = (char*)malloc(sizeof(char) * (strlen(str)+1));
		strcpy(tmp, str);

		psn.name = tmp;

		size = sizeof(psn.age) + sizeof(psn.name);
		appendFromTail(lp, &psn, size, PersonMemCopy);
	}
}


//display 보조함수
void intPrint(void *p)
{
	printf("%d\n", (*(int*)p));
}

//myMemcpy 보조함수
void intMemCopy(void *p1, void *p2)
{
	(*(int*)p1) = (*(int*)p2);
}

//compare 보조함수
int intCompare(void *p1, void *p2)
{
	if((*(int*)p1) == (*(int*)p2))	return 0;
	else if((*(int*)p1) > (*(int*)p2))	return 1;
	else return -1;
}

//dataFree 보조함수
void intFree(void *p)
{	
	//비워두기
}

