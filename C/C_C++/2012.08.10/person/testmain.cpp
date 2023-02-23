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

	printf("������ ");
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
		printf("ã�� �̸��� %s�̰� ���̴� %d���Դϴ�\n", ((Person*)res+1)->name, ((Person*)res+1)->age);
		printf("�տ� �Է� 1	�ڿ� �Է� 2 : ");
		scanf("%d", &menu);

		fflush(stdin);
		printf("�̸� : ");
		scanf("%s", name);
		printf("���� : ");
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

//�˻�
Node* search(LinkedList *lp)
{
	Node * res;
	int  menu;
	Person psn;
	Person *pp;
	char name[100];
	
	
	fflush(stdin);
	printf("���̰˻�(1)/�̸��˻�(2)/����(3) : ");
	scanf("%d", &menu);

	if(menu==1)
	{
		fflush(stdin);
		printf("�����Է� : ");
		scanf("%d", &(psn.age));
		pp = &psn;
		res = searchUnique(lp, pp, PersonageCompare);
		return res;
	}
	else if(menu==2)
	{
		fflush(stdin);
		printf("�̸��Է� : ");
		scanf("%s", name);
		psn.name = (char*)malloc(strlen(name)+1);
		strcpy(psn.name, name);
		pp = &psn;
		res = searchUnique(lp, pp, PersonnameCompare);
		return res;
	}
	
}

//�Է�
void input(LinkedList *lp)
{
	char str[200];
	char * tmp;
	int size;
	Person psn;	

	while(1)
	{
		fflush(stdin);
		printf("�̸��� �Է��ϼ���(end����) : ");
		scanf("%s", str);
		if(strcmp(str, "end")==0)	{break;}
		printf("���̸� �Է��ϼ��� : ");
		scanf("%d", &psn.age);
		printf("\n");		
				
		tmp = (char*)malloc(sizeof(char) * (strlen(str)+1));
		strcpy(tmp, str);

		psn.name = tmp;

		size = sizeof(psn.age) + sizeof(psn.name);
		appendFromTail(lp, &psn, size, PersonMemCopy);
	}
}


//display �����Լ�
void intPrint(void *p)
{
	printf("%d\n", (*(int*)p));
}

//myMemcpy �����Լ�
void intMemCopy(void *p1, void *p2)
{
	(*(int*)p1) = (*(int*)p2);
}

//compare �����Լ�
int intCompare(void *p1, void *p2)
{
	if((*(int*)p1) == (*(int*)p2))	return 0;
	else if((*(int*)p1) > (*(int*)p2))	return 1;
	else return -1;
}

//dataFree �����Լ�
void intFree(void *p)
{	
	//����α�
}

