#pragma once
#include <iostream>
#include "Car.h"
using namespace std;

typedef struct _node Node;
typedef struct _node{
	Node *prev;		//prev
	Car cr;			//īŬ����
	Node *next;		//next
}Node;

class companyA
{
private:
	Node *headp;	//headp
	Node *tailp;	//tailp
	Node *curp;		//curp
	int len;		//����count
public:
	companyA();						//������(create)
	void display();					//���
	int searchUnique(int &unum);	//������ڵ� �˻�(�����ϸ�return 1)
	Node* appendFromTail(Car &kr);	//���ϳ��տ� �߰�
	void sortList();				//������������ ����
	int getlen();					//getlen
	~companyA();					//�Ҹ���(destroy)
};