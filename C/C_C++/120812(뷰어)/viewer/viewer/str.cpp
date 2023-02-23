#pragma once
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "str.h"

/*----------------------------------------------------------------------------------------*/

//LinkedList & TextInfo 초기화
void init(LinkedList *list, TextInfo *tp)
{
	tp->chCnt = 0;
	tp->curLine = 0;
	tp->totLine = 0;
	strcpy(tp->t_name, "\0");

	list->headp = (Node *)malloc(sizeof(Node)); // Head Node 생성 
	list->tailp = (Node *)malloc(sizeof(Node)); // Tail Node 생성
	list->headp->next = list->tailp;
	list->headp->prev = list->headp;
	list->tailp->prev = list->headp;
	list->tailp->next = list->tailp;
	list->len = 0;
}

//테일노드 앞에 추가
Node * appendFromTail(LinkedList *list, void *item, size_t size, void(*myMemcpy)(void *, void *))
{
	list->curp = (Node*)malloc(sizeof(Node) + size);
	if(list->curp==NULL) { // 동적메모리 할당이 실패해서 노드 생성이 실패했으면 NULL pointer를 리턴 함
		return NULL;
	}

	myMemcpy(list->curp+1, item);
	
	list->curp->next = list->tailp;
	list->curp->prev = list->tailp->prev;
	list->tailp->prev = list->curp;
	list->curp->prev->next = list->curp;
	list->len++; // Node수 증가
	
	return list->curp;
}

//모든노드 삭제
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

	//파일 닫은거 표시
	//opentxt = 0;
}

/*----------------------------------------------------------------------------------------*/

//문자열복사
void strMemCopy(void *p1, void *p2)
{
	strcpy((char*)p1, (char*)p2);
}

//문자열출력
void strPrint(void *p)
{
	printf("%s", (char*)p);
}

//동적메모리 해제
void strFree(void *p)
{
	//
}
