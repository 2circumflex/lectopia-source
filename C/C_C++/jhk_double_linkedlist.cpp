#pragma warning (disable : 4996)
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
#include<windows.h>

void create(struct linkedList *), sortList(struct linkedList *), destroy(struct linkedList *);
struct Node * appendFromHead(struct linkedList *, char *);
struct Node * appendFromTail(struct linkedList *, char *);
struct Node * insertBefore(struct linkedList *, struct Node *, char *);
struct Node * insertAfter(struct linkedList *, struct Node *, char *);
struct Node * deleteNode(struct linkedList *, struct Node *);
struct Node * searchUnique(struct linkedList *, char *);

struct Node{  // Node ����ü ����
	struct Node *prev;
	char name[20];
	struct Node *next;
};
struct linkedList{  // LinkedList ����ü ����
	struct Node *headp;
	struct Node *tailp;
	struct Node *curp;
	int len;
};

//----------------------------------------------------------------------------------
void create(linkedList *list) // double linkedlist�� �ʱ�ȭ ��Ų��.
{
	list->headp = (struct Node*)malloc(sizeof(struct Node)); // Head Node ���� 
	list->tailp = (struct Node*)malloc(sizeof(struct Node)); // Tail Node ���� 
	list->headp->next = list->tailp;
	list->headp->prev =list->headp;
	list->tailp->prev = list->headp;
	list->tailp->next = list->tailp;
	list->len = 0;
}
//----------------------------------------------------------------------------------
struct Node* appendFromHead(struct linkedList *list, char *np) //  ����� �ڿ� �� ��� �߰� (������ �Է��� �������� �߰���)
{
	list->curp = (struct Node*)malloc(sizeof(struct Node));
	if(list->curp==NULL) { // �����޸� �Ҵ��� �����ؼ� ��� ������ ���������� NULL pointer�� ���� �� 
		return NULL;
	}
	strcpy(list->curp->name, np);
	list->curp->prev = list->headp;
	list->curp->next = list->headp->next;
	list->headp->next = list->curp;
	list->curp->next->prev = list->curp;
	list->len++; // Node �� ����
	return list->curp;
}
//----------------------------------------------------------------------------------
struct Node* appendFromTail(struct linkedList *list, char *np) // ���ϳ�� �տ� �� ��� �߰� (������ �Է��� �������� �߰���)
{
	list->curp = (struct Node*)malloc(sizeof(struct Node));
	if(list->curp==NULL) { // �����޸� �Ҵ��� �����ؼ� ��� ������ ���������� NULL pointer�� ���� ��
		return NULL;
	}
	strcpy(list->curp->name, np);
	list->curp->next = list->tailp;
	list->curp->prev = list->tailp->prev;
	list->tailp->prev = list->curp;
	list->curp->prev->next = list->curp;
	list->len++; // Node�� ����
	return list->curp;
}

//----------------------------------------------------------------------------------
struct Node* insertBefore(struct linkedList *list, struct Node *tp, char *np) // tp��� �տ� ����� ����
{
	list->curp = (struct Node*)malloc(sizeof(struct Node));
	if(list->curp==NULL) { // �����޸� �Ҵ��� �����ؼ� ��� ������ ���������� NULL pointer�� ���� ��
		return NULL;
	}
	strcpy(list->curp->name, np);
	list->curp->prev = tp->prev;
	list->curp->next = tp;
	tp->prev->next = list->curp;
	tp->prev = list->curp;
	list->len++; // Node�� ����
	return list->curp;
}
//----------------------------------------------------------------------------------
struct Node* insertAfter(struct linkedList *list, struct Node *tp, char *np) // tp��� �ڿ� ����� ����
{
	list->curp = (struct Node*)malloc(sizeof(struct Node));
	if(list->curp==NULL) { // �����޸� �Ҵ��� �����ؼ� ��� ������ ���������� NULL pointer�� ���� ��
		return NULL;
	}
	strcpy(list->curp->name, np);
	list->curp->prev = tp;
	list->curp->next = tp->next;
	tp->next->prev = list->curp;
	tp->next = list->curp;
	list->len++; // Node�� ����
	return list->curp;
}
//----------------------------------------------------------------------------------
struct Node* deleteNode(struct linkedList *list, struct Node *tp) // ������ ����� �����ּҸ� ���޹޾� �� ��� ����
{
	list->curp = tp;
	tp->prev->next = tp->next;
	tp->next->prev = tp->prev;
	free(tp);
	list->len--; // Node�� ����

	return list->curp;
}
//----------------------------------------------------------------------------------
struct Node* searchUnique(struct linkedList *list, char *np) // Ư�� ���ڿ� �˻�
{
	int i;
	list->curp = list->headp->next;
	for(i=0; i<list->len; i++){
		if(strcmp(list->curp->name, np) == 0){ // ã�� �����͸� ã������
			return list->curp;
		}
		list->curp = list->curp->next;
	}
	return NULL;  // for���� �������� ã�� �����Ͱ� �����ٸ� ���°��̹Ƿ� NULL ����
}
//----------------------------------------------------------------------------------
void sortList(struct linkedList *list) // ������ ������������ ����
{
	char tName[20];
	struct Node *tp;

	list->curp = list->headp->next; // ���� ��带 Head Node ���� ���� ����(�������� �����Ͱ� �ִ� ù ������ �˻��ϱ� ����)
	tp = list->curp->next; // tp�� �׻� list->curp�� ����Ű�� ���� ��带 ����Ų��.
	while(list->curp->next != list->tailp){
		while(tp != list->tailp){
			if(strcmp(list->curp->name, tp->name) > 0){ // ���� ����� �̸��� ���� ����� �̸����� ũ�� swap
				strcpy(tName, list->curp->name);
				strcpy(list->curp->name, tp->name);
				strcpy(tp->name, tName);
			}
			tp=tp->next;
		}
		list->curp=list->curp->next;
		tp=list->curp->next;
	}
}
//----------------------------------------------------------------------------------
void destroy(struct linkedList *list) // linkedList���� ��� ��� ����
{
	int i;
	struct Node *tp;
	
	list->curp = list->headp->next; // Head Node �ڸ� ����Ű�� ��
	tp = list->curp->next;
	for(i=0; i<list->len; i++){
		free(list->curp);
		list->curp = tp;
		tp = list->curp->next;
	}
	free(list->headp);
	free(list->tailp);
	list->headp = list->tailp = list->curp = NULL;
	list->len = 0;
}