#pragma once
#include <iostream>
#include "Car.h"
using namespace std;

typedef struct _node Node;
typedef struct _node{
	Node *prev;		//prev
	Car cr;			//카클래스
	Node *next;		//next
}Node;

class companyA
{
private:
	Node *headp;	//headp
	Node *tailp;	//tailp
	Node *curp;		//curp
	int len;		//개수count
public:
	companyA();						//생성자(create)
	void display();					//출력
	int searchUnique(int &unum);	//사용자코드 검색(존재하면return 1)
	Node* appendFromTail(Car &kr);	//테일노드앞에 추가
	void sortList();				//오름차순으로 정렬
	int getlen();					//getlen
	~companyA();					//소멸자(destroy)
};