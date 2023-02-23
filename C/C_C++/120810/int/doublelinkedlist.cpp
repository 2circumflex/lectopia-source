#include <malloc.h>
#include <stdio.h>
#include "doublelinkedlist.h"


//double linkedlist를 초기화 시킨다.
void create(LinkedList *list) // double linkedlist를 초기화 시킨다.
{	
	list->headp = (Node*)malloc(sizeof(Node)); // Head Node 생성 
	list->tailp = (Node*)malloc(sizeof(Node)); // Tail Node 생성
	list->headp->next = list->tailp;
	list->headp->prev = list->headp;
	list->tailp->prev = list->headp;
	list->tailp->next = list->tailp;
	list->len = 0;
}

//테일노드 앞에 새 노드 추가 (데이터 입력의 정순으로 추가됨)
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

//헤드노드 뒤에 새 노드 추가 (데이터 입력의 역순으로 추가됨)
Node * appendFromHead(LinkedList *list, void *item, size_t size, void(*myMemcpy)(void *, void *))
{
	list->curp = (Node*)malloc(sizeof(Node) + size);
	if(list->curp==NULL) { // 동적메모리 할당이 실패해서 노드 생성이 실패했으면 NULL pointer를 리턴 함
		return NULL;
	}

	myMemcpy(list->curp+1, item);

	list->curp->prev = list->headp;
	list->curp->next = list->headp->next;
	list->headp->next = list->curp;
	list->curp->next->prev = list->curp;
	list->len++; // Node 수 증가


	return list->curp;
}

//출력
void display(LinkedList *list, void(*dataPrint)(void*))
{
	int i;
	
	list->curp = list->headp->next;
	for(i=0; i<list->len; i++)
	{
		
		dataPrint(list->curp+1);	
		list->curp = list->curp->next;
	}
	
	return;
}

//검색된노드 뒤에 추가
Node* insertAfter(LinkedList *list, Node *index, void *item, size_t size, void(*myMemcpy)(void *, void *))
{
	list->curp = (Node *)malloc(sizeof(Node) + size);
	if(list->curp==NULL) { // 동적메모리 할당이 실패해서 노드 생성이 실패했으면 NULL pointer를 리턴 함
		return NULL;
	}

	myMemcpy(list->curp+1, item);

	list->curp->prev = index;
	list->curp->next = index->next;
	index->next->prev = list->curp;
	index->next = list->curp;;
	
	list->len++; // Node수 증가
	return list->curp;
}

//검색된노드 앞에 추가
Node* insertBefore(LinkedList *list, Node *index, void *item, size_t size, void(*myMemcpy)(void *, void *))
{
	list->curp = (Node *)malloc(sizeof(Node) + size);
	if(list->curp==NULL) { // 동적메모리 할당이 실패해서 노드 생성이 실패했으면 NULL pointer를 리턴 함
		return NULL;
	}

	myMemcpy(list->curp+1, item);

	list->curp->prev = index->prev;;
	list->curp->next = index;
	index->prev->next = list->curp;
	index->prev = list->curp;

	list->len++; // Node수 증가
	return list->curp;
}

//특정데이터 검색
Node* searchUnique(LinkedList *list, void *pos, int (*compare)(void *, void *))
{
	list->curp = list->headp->next;

	while(list->curp != list->tailp)
	{
		if(compare(list->curp+1, pos)==0)	return list->curp;
		list->curp = list->curp->next;
	}
	return NULL;
}

//특정데이터 삭제
Node* nodeDelete(LinkedList *list, Node *index, void (*dataFree)(void *))
{
	list->curp = index;

	list->curp->prev->next = list->curp->next;
	list->curp->next->prev = list->curp->prev;
	
	dataFree(index);
	
	
	list->len--;
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
		dataFree(res);
	}
	dataFree(list->headp);
	dataFree(list->tailp);
	list->len = 0;
	printf("모든 노드 삭제 완료\n");
}

//정렬
void sort(LinkedList *list, size_t size, int (*compare)(void *, void *), void (*myMemcpy)(void *, void *))
{
	int i, j;
	Node * temp, *tp;

	list->curp = list->headp->next;

	temp = (Node *)malloc(sizeof(Node) + size);

	for(i=0; i<list->len-1; i++)
	{	
		tp = list->curp;
		for(j=i+1; j<list->len; j++)
		{
			tp = tp->next;
			if(compare(list->curp+1, tp+1) > 0)
			{
				myMemcpy(temp+1, list->curp+1);
				myMemcpy(list->curp+1, tp+1);
				myMemcpy(tp+1, temp+1);
			}					
		}
		list->curp = list->curp->next;
	}
}

//
void getAt(Node *index, void *getData, void(*myMemcpy)(void *, void *))
{
	myMemcpy(index+1, getData);
}