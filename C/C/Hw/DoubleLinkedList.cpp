/* ��¥ : 2012�� 2�� 22��   
   �ۼ��� : �̷ο�   
   ���α׷��� ��� : DoubleLinkedList �ۼ�!! */
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>
#pragma warning (disable : 4996)

typedef struct _node Node;
typedef struct _node{
	Node *prev;
	char name[20];
	Node *next;
}Node;

typedef struct _linkedlist{
	Node *headp;
	Node *tailp;
	Node *curp;
	int len;
}LinkedList;

void create(LinkedList *);
void input(LinkedList *);
void display(LinkedList *);
void search(LinkedList *);
Node *appendFromTail(LinkedList *, char *);
Node *appendFromHead(LinkedList *, char *);
Node *searchUnique(LinkedList *, char *);
Node *insertBefore(LinkedList *, Node *, char *);
Node *insertAfter(LinkedList *, Node *, char *);
Node *deleteNode(LinkedList *, Node *);
void sortList(LinkedList *);
void destroy(LinkedList *);

int main()
{	
	LinkedList List;
	Node *res;

	create(&List);
	input(&List);
	display(&List);
	search(&List);

	res = searchUnique(&List, "HGD");

	insertBefore(&List, res, "JHK");	
	display(&List);
	printf("�� HGD�տ� JHK�߰�\n\n");

	insertAfter(&List, res, "HSY");	
	display(&List);
	printf("�� HGD�ڿ� HSY�߰�\n\n");

	deleteNode(&List, res);	
	display(&List);
	printf("�� HGD����\n\n");
	
	sortList(&List);	
	display(&List);
	printf("�� ������������\n\n");

	destroy(&List);
	display(&List);	

	return 0;
}

void input(LinkedList *lp)	///
{
	char temp[20];
	while(1)
	{
		printf("���� �Է� : ");
		gets(temp);
		if(strcmp(temp, "��")==0) { break; }
		appendFromTail(lp, temp);		//���ϳ��տ������
		//appendFromHead(lp, temp);		//�����ڿ������
	}
}

Node *appendFromHead(LinkedList *lp, char *np)	//����� �ڿ� �� ��� �߰�
{
	lp->curp=(Node *)malloc(sizeof(Node));
	assert(lp->curp!=NULL);
	lp->curp->prev=lp->headp;
	lp->curp->next=lp->headp->next;
	lp->curp->prev->next=lp->curp;
	lp->curp->next->prev=lp->curp;
	strcpy(lp->curp->name, np);
	lp->len++;
	return lp->curp;
}

Node *appendFromTail(LinkedList *lp, char *np)	//���ϳ�� �տ� �� ��� �߰�
{
	lp->curp=(Node *)malloc(sizeof(Node));
	assert(lp->curp!=NULL);
	lp->curp->prev=lp->tailp->prev;
	lp->curp->next=lp->tailp;
	lp->curp->prev->next=lp->curp;
	lp->tailp->prev=lp->curp;
	strcpy(lp->curp->name, np);
	lp->len++;
	return lp->curp;	
}

Node * insertBefore(LinkedList *lp, Node *tp, char *np)	//tp��� �տ� ��������
{
	lp->curp=(Node *)malloc(sizeof(Node));
	assert(lp->curp!=NULL);
	lp->curp->prev=tp->prev;
	lp->curp->next=tp;
	lp->curp->prev->next=lp->curp;
	lp->curp->next->prev=lp->curp;
	strcpy(lp->curp->name, np);
	lp->len++;
	return lp->curp;
}

Node * insertAfter(LinkedList *lp, Node *tp, char *np)	//tp��� �ڿ� ��������
{
	lp->curp=(Node *)malloc(sizeof(Node));
	assert(lp->curp!=NULL);
	lp->curp->next=tp->next;
	lp->curp->prev=tp;
	lp->curp->prev->next=lp->curp;
	lp->curp->next->prev=lp->curp;
	strcpy(lp->curp->name, np);
	lp->len++;
	return lp->curp;
}

Node * deleteNode(LinkedList *lp, Node *tp)	//���� ���� �ּ��� ��� ����
{
	tp->prev->next=tp->next;
	tp->next->prev=tp->prev;
	free(tp);
	lp->len--;
	return lp->curp;
}

void sortList(LinkedList *lp)	//������ �������� ����
{
	int i, j;
	char temp[20];
	Node *fp;
	lp->curp=lp->headp->next;
	fp=lp->curp->next;
	for(i=0; i<lp->len; i++)
	{
		for(j=i+1; j<lp->len; j++)
		{
			if(strcmp(lp->curp->name, fp->name)>0)	//sort
			{
				strcpy(temp, lp->curp->name);
				strcpy(lp->curp->name, fp->name);
				strcpy(fp->name, temp);				
			}
			fp=fp->next;
		}	
		lp->curp=lp->curp->next;
		fp=lp->curp->next;
		if(fp==lp->tailp) { break; }
	}
	return;
}

void destroy(LinkedList *lp)	//LinedList���� ��� ��� ����
{
	Node *fp;	
	lp->curp=lp->headp->next;
	fp=lp->curp;
	free(lp->headp);
	while(fp!=lp->tailp)
	{		
		lp->curp=lp->curp->next;
		free(fp);
		fp=lp->curp;
		lp->len--;
	}	
	free(lp->tailp);
	printf("��� ��� ���� �Ϸ�\n");
	
	return;
}

void create(LinkedList *lp)	//double linkedlist�� �ʱ�ȭ
{
	lp->headp=(Node*)malloc(sizeof(Node));	//headnode �����޸��Ҵ�
	assert(lp->headp!=NULL);
	lp->tailp=(Node*)malloc(sizeof(Node));	//tailnode �����޸��Ҵ�
	assert(lp->tailp!=NULL);
	lp->headp->prev=lp->headp;
	lp->headp->next=lp->tailp;
	lp->tailp->prev=lp->headp;
	lp->tailp->next=lp->tailp;
	lp->curp=NULL;
	lp->len=0;
	return;
}

void display(LinkedList *lp)	//����Ʈ���� ��� ������ ��� ���
{
	int i;
	lp->curp = lp->headp->next;
	for(i=0; i<lp->len; i++)
	{
		printf("%s\n", lp->curp->name);
		lp->curp=lp->curp->next;	//���������̵�
	}
}

void search(LinkedList *lp)	///
{
	char temp[20];
	Node *res;
	
	while(1)
	{
		printf("ã�� �̸� : ");
		gets(temp);
		if(strcmp(temp, "��")==0) { break; }
		res = searchUnique(lp, temp);
		if(res==NULL) { printf("����\n"); }
		else { printf("����\n"); }
	}
}

Node *searchUnique(LinkedList *lp, char *np)	//Ư�� ������ �˻�
{
	lp->curp=lp->headp->next;
	while(lp->curp!=lp->tailp)
	{
		if(strcmp(lp->curp->name, np)==0)
		{ return lp->curp; }
		lp->curp=lp->curp->next;		
	}
	return NULL;
}