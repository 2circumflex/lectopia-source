#pragma once
#pragma warning(disable:4996)
#include <stddef.h>

/*----------------------------------------------------------------------------------------*/

//텍스트노드
typedef struct _node Node;
struct _node
{
	Node *prev;
	Node *next;
};

//링크드리스트
typedef struct _linkedlist
{
	Node * headp;
	Node * curp;
	Node * tailp;
	int len;
}LinkedList;

//텍스트 정보
typedef struct text_info
{
	char t_name[50];
	int curLine;
	int totLine;
	int chCnt;
}TextInfo;

/*----------------------------------------------------------------------------------------*/

//텍스트칼라
#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15

//특수기 확장키코드
#define COMMON_KEY 1 
#define SPECIAL_KEY 0 
#define F1 59 
#define F2 60 
#define F3 61 
#define F4 62 
#define F5 63 
#define F6 64 
#define F7 65 
#define F8 66 
#define F9 67 
#define F10 68 
#define UP_ARROW 72 
#define DOWN_ARROW 80 
#define LEFT_ARROW 75 
#define RIGHT_ARROW 77 
#define PAGEUP 73 
#define PAGEDOWN 81 
#define ENTER 13 
#define ESC 27

/*----------------------------------------------------------------------------------------*/

void init(LinkedList *list, TextInfo *tp);
Node * appendFromTail(LinkedList *list, void *item, size_t size, void(*myMemcpy)(void *, void *));
void destroy(LinkedList *list, void (*dataFree)(void *));
void strMemCopy(void *p1, void *p2);
void strPrint(void *p);
void strFree(void *p);