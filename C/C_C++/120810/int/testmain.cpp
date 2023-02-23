#include <stdio.h>
#include "doublelinkedlist.h"


void intMemCopy(void *, void *);
void intPrint(void *p);
int intCompare(void *p1, void *p2);
void intFree(void *p);


int main()
{
	int a = 10;
	int b = 5;
	int c = 1;
	int d = 3;
	LinkedList List;
	Node *res;

	//초기화
	create(&List);
	//10
	appendFromTail(&List, &a, sizeof(a), intMemCopy);
	//5
	appendFromTail(&List, &b, sizeof(b), intMemCopy);
	//5
	appendFromTail(&List, &b, sizeof(b), intMemCopy);
	//10
	appendFromTail(&List, &a, sizeof(a), intMemCopy);

	//10검색
	res = searchUnique(&List, &a, intCompare);
	//10뒤에 1추가
	insertAfter(&List, res, &c, sizeof(c), intMemCopy);
	//10뒤에 3추가
	insertAfter(&List, res, &d, sizeof(d), intMemCopy);
	//10앞에 3추가
	insertBefore(&List, res, &d, sizeof(d), intMemCopy);

	//10검색
	res = searchUnique(&List, &a, intCompare);
	//10삭제
	nodeDelete(&List, res, intFree);

	//출력
	display(&List, intPrint);
	printf("------------------\n");
	//정렬
	sort(&List, sizeof(int), intCompare, intMemCopy);
	
	//출력
	display(&List, intPrint);
	printf("------------------\n");

	res = searchUnique(&List, &a,intCompare);
	getAt(res, &c, intMemCopy);
	display(&List, intPrint);
	printf("------------------\n");

	//모든노드삭제
	destroy(&List, intFree);

	//출력
	display(&List, intPrint);
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