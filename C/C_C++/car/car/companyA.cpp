#include <iostream>
#include <iomanip>
#include "companyA.h"
using namespace std;

//생성자(create)
companyA::companyA()
{
	this->headp = new Node;
	this->tailp = new Node;
	this->headp->next = this->tailp;
	this->tailp->prev = this->headp;
	this->headp->prev = this->headp;
	this->tailp->next = this->tailp;
	this->len = 0;
}

//사용자코드 검색(존재하면return 1)
int companyA::searchUnique(int &unum)
{
	this->curp = this->headp->next;
	while(this->curp != this->tailp)
	{
		if(this->curp->cr.getuserNum() == unum)
		{
			return 1;
		}
		this->curp = this->curp->next;
	}
	return 0;
}

//출력
void companyA::display()
{
	cout << "[고객번호]   [차종명]   [기본요금]   [운행거리]   [총임대료]" << endl;
	this->curp = this->headp->next;
	while(this->curp != this->tailp)
	{
		cout << "    ";
		cout << setw(4) << setfill('0') << this->curp->cr.getuserNum();
		switch(this->curp->cr.getcarNum())
		{
		case 1 : cout << setw(12) << setfill(' ') << "경  차"; break;
		case 2 : cout << setw(12) << setfill(' ') << "소형차"; break;
		case 3 : cout << setw(12) << setfill(' ') << "중형차"; break;
		case 4 : cout << setw(12) << setfill(' ') << "대형차"; break;
		case 5 : cout << setw(12) << setfill(' ') << "리무진"; break;
		}
		cout << setw(12) << setfill(' ') << this->curp->cr.getdefPay() << "원";
		cout << setw(10) << setfill(' ') << this->curp->cr.getkm() << "KM";
		cout << setw(12) << setfill(' ') << curp->cr.gettotPay() << "원  " << endl;

		this->curp = this->curp->next;
	}
}

//테일노드앞에 추가
Node* companyA::appendFromTail(Car &kr)
{
	this->curp = new Node;
	if(this->curp == NULL)
	{
		return NULL;
	}

	this->curp->cr = kr;
	
	this->curp->next = this->tailp;
	this->curp->prev = this->tailp->prev;
	this->tailp->prev = this->curp;
	this->curp->prev->next = this->curp;
	this->len++;
	return this->curp;
}

//오름차순으로 정렬
void companyA::sortList()
{
	Node *tp;
	Car tmp;

	this->curp = this->headp->next;
	tp = this->curp->next;
	
	while(this->curp->next != this->tailp)
	{
		while(tp != this->tailp)
		{
			if(this->curp->cr.getuserNum() > tp->cr.getuserNum())
			{
				tmp = this->curp->cr;
				this->curp->cr = tp->cr;
				tp->cr = tmp;
			}
			tp=tp->next;
		}
		this->curp = this->curp->next;
		tp = this->curp->next;
	}	
}

//getlen
int companyA::getlen()
{
	return this->len;
}

//소멸자(destroy)
companyA::~companyA()
{
	int i;
	Node *tp;
	this->curp = this->headp->next;
	tp = this->curp->next;
	for(i=0; i<this->len; i++)
	{
		delete this->curp;
		this->curp = tp;
		tp = this->curp->next;
	}
	delete this->headp;
	delete this->tailp;
	this->headp = this->tailp = this->curp = NULL;
	this->len = 0;
}