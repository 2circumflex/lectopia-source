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

	//�ʱ�ȭ
	create(&List);
	//10
	appendFromTail(&List, &a, sizeof(a), intMemCopy);
	//5
	appendFromTail(&List, &b, sizeof(b), intMemCopy);
	//5
	appendFromTail(&List, &b, sizeof(b), intMemCopy);
	//10
	appendFromTail(&List, &a, sizeof(a), intMemCopy);

	//10�˻�
	res = searchUnique(&List, &a, intCompare);
	//10�ڿ� 1�߰�
	insertAfter(&List, res, &c, sizeof(c), intMemCopy);
	//10�ڿ� 3�߰�
	insertAfter(&List, res, &d, sizeof(d), intMemCopy);
	//10�տ� 3�߰�
	insertBefore(&List, res, &d, sizeof(d), intMemCopy);

	//10�˻�
	res = searchUnique(&List, &a, intCompare);
	//10����
	nodeDelete(&List, res, intFree);

	//���
	display(&List, intPrint);
	printf("------------------\n");
	//����
	sort(&List, sizeof(int), intCompare, intMemCopy);
	
	//���
	display(&List, intPrint);
	printf("------------------\n");

	res = searchUnique(&List, &a,intCompare);
	getAt(res, &c, intMemCopy);
	display(&List, intPrint);
	printf("------------------\n");

	//��������
	destroy(&List, intFree);

	//���
	display(&List, intPrint);
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