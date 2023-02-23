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

struct Node{  // Node 구조체 선언
	struct Node *prev;
	char name[20];
	struct Node *next;
};
struct linkedList{  // LinkedList 구조체 선언
	struct Node *headp;
	struct Node *tailp;
	struct Node *curp;
	int len;
};

//----------------------------------------------------------------------------------
void create(linkedList *list) // double linkedlist를 초기화 시킨다.
{
	list->headp = (struct Node*)malloc(sizeof(struct Node)); // Head Node 생성 
	list->tailp = (struct Node*)malloc(sizeof(struct Node)); // Tail Node 생성 
	list->headp->next = list->tailp;
	list->headp->prev =list->headp;
	list->tailp->prev = list->headp;
	list->tailp->next = list->tailp;
	list->len = 0;
}
//----------------------------------------------------------------------------------
struct Node* appendFromHead(struct linkedList *list, char *np) //  헤드노드 뒤에 새 노드 추가 (데이터 입력의 역순으로 추가됨)
{
	list->curp = (struct Node*)malloc(sizeof(struct Node));
	if(list->curp==NULL) { // 동적메모리 할당이 실패해서 노드 생성이 실패했으면 NULL pointer를 리턴 함 
		return NULL;
	}
	strcpy(list->curp->name, np);
	list->curp->prev = list->headp;
	list->curp->next = list->headp->next;
	list->headp->next = list->curp;
	list->curp->next->prev = list->curp;
	list->len++; // Node 수 증가
	return list->curp;
}
//----------------------------------------------------------------------------------
struct Node* appendFromTail(struct linkedList *list, char *np) // 테일노드 앞에 새 노드 추가 (데이터 입력의 정순으로 추가됨)
{
	list->curp = (struct Node*)malloc(sizeof(struct Node));
	if(list->curp==NULL) { // 동적메모리 할당이 실패해서 노드 생성이 실패했으면 NULL pointer를 리턴 함
		return NULL;
	}
	strcpy(list->curp->name, np);
	list->curp->next = list->tailp;
	list->curp->prev = list->tailp->prev;
	list->tailp->prev = list->curp;
	list->curp->prev->next = list->curp;
	list->len++; // Node수 증가
	return list->curp;
}

//----------------------------------------------------------------------------------
struct Node* insertBefore(struct linkedList *list, struct Node *tp, char *np) // tp노드 앞에 새노드 삽입
{
	list->curp = (struct Node*)malloc(sizeof(struct Node));
	if(list->curp==NULL) { // 동적메모리 할당이 실패해서 노드 생성이 실패했으면 NULL pointer를 리턴 함
		return NULL;
	}
	strcpy(list->curp->name, np);
	list->curp->prev = tp->prev;
	list->curp->next = tp;
	tp->prev->next = list->curp;
	tp->prev = list->curp;
	list->len++; // Node수 증가
	return list->curp;
}
//----------------------------------------------------------------------------------
struct Node* insertAfter(struct linkedList *list, struct Node *tp, char *np) // tp노드 뒤에 새노드 삽입
{
	list->curp = (struct Node*)malloc(sizeof(struct Node));
	if(list->curp==NULL) { // 동적메모리 할당이 실패해서 노드 생성이 실패했으면 NULL pointer를 리턴 함
		return NULL;
	}
	strcpy(list->curp->name, np);
	list->curp->prev = tp;
	list->curp->next = tp->next;
	tp->next->prev = list->curp;
	tp->next = list->curp;
	list->len++; // Node수 증가
	return list->curp;
}
//----------------------------------------------------------------------------------
struct Node* deleteNode(struct linkedList *list, struct Node *tp) // 삭제할 노드의 시작주소를 전달받아 그 노드 삭제
{
	list->curp = tp;
	tp->prev->next = tp->next;
	tp->next->prev = tp->prev;
	free(tp);
	list->len--; // Node수 감소

	return list->curp;
}
//----------------------------------------------------------------------------------
struct Node* searchUnique(struct linkedList *list, char *np) // 특정 문자열 검색
{
	int i;
	list->curp = list->headp->next;
	for(i=0; i<list->len; i++){
		if(strcmp(list->curp->name, np) == 0){ // 찾는 데이터를 찾았으면
			return list->curp;
		}
		list->curp = list->curp->next;
	}
	return NULL;  // for문이 끝나도록 찾는 데이터가 없었다면 없는것이므로 NULL 리턴
}
//----------------------------------------------------------------------------------
void sortList(struct linkedList *list) // 노드들을 오름차순으로 정렬
{
	char tName[20];
	struct Node *tp;

	list->curp = list->headp->next; // 현재 노드를 Head Node 다음 노드로 설정(실질적인 데이터가 있는 첫 노드부터 검색하기 위해)
	tp = list->curp->next; // tp는 항상 list->curp가 가리키는 다음 노드를 가리킨다.
	while(list->curp->next != list->tailp){
		while(tp != list->tailp){
			if(strcmp(list->curp->name, tp->name) > 0){ // 현재 노드의 이름이 다음 노드의 이름보다 크면 swap
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
void destroy(struct linkedList *list) // linkedList내의 모든 노드 삭제
{
	int i;
	struct Node *tp;
	
	list->curp = list->headp->next; // Head Node 뒤를 가리키게 함
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