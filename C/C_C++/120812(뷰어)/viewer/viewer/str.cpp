#pragma once
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "str.h"

/*----------------------------------------------------------------------------------------*/

//LinkedList & TextInfo �ʱ�ȭ
void init(LinkedList *list, TextInfo *tp)
{
	tp->chCnt = 0;
	tp->curLine = 0;
	tp->totLine = 0;
	strcpy(tp->t_name, "\0");

	list->headp = (Node *)malloc(sizeof(Node)); // Head Node ���� 
	list->tailp = (Node *)malloc(sizeof(Node)); // Tail Node ����
	list->headp->next = list->tailp;
	list->headp->prev = list->headp;
	list->tailp->prev = list->headp;
	list->tailp->next = list->tailp;
	list->len = 0;
}

//���ϳ�� �տ� �߰�
Node * appendFromTail(LinkedList *list, void *item, size_t size, void(*myMemcpy)(void *, void *))
{
	list->curp = (Node*)malloc(sizeof(Node) + size);
	if(list->curp==NULL) { // �����޸� �Ҵ��� �����ؼ� ��� ������ ���������� NULL pointer�� ���� ��
		return NULL;
	}

	myMemcpy(list->curp+1, item);
	
	list->curp->next = list->tailp;
	list->curp->prev = list->tailp->prev;
	list->tailp->prev = list->curp;
	list->curp->prev->next = list->curp;
	list->len++; // Node�� ����
	
	return list->curp;
}

//����� ����
void destroy(LinkedList *list, void (*dataFree)(void *))
{
	int i;
	Node * res;
	
	list->curp = list->headp->next;

	for(i=0; i<list->len; i++)
	{
		res = list->curp;
		list->curp = list->curp->next;
		dataFree(res+1);
		free(res);
	}
	free(list->headp);
	free(list->tailp);
	list->len = 0;

	//���� ������ ǥ��
	//opentxt = 0;
}

/*----------------------------------------------------------------------------------------*/

//���ڿ�����
void strMemCopy(void *p1, void *p2)
{
	strcpy((char*)p1, (char*)p2);
}

//���ڿ����
void strPrint(void *p)
{
	printf("%s", (char*)p);
}

//�����޸� ����
void strFree(void *p)
{
	//
}
