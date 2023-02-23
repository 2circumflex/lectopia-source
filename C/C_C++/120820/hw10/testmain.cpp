#include <iostream>
#include <string.h>
using namespace std;

class Happy
{
	private:
		char name[100];		//이름
		int money;			//잔액
		char * list[100];	//사용 내역을 저장하는 char * 배열
		int index;			//사용 내역 개수
	public:
		Happy(char *np="", int money=10000);	//디폴트 생성자 함수
		Happy(Happy &r);						//복사 생성자 함수
		~Happy();								//소멸자 함수
		Happy & operator=(Happy &r);
		void use(char *lp, int n);				//사용함수(사용내역과 금액을 받는다)
		Happy &winner(Happy &r);				//잔액 비교하여 많은 금액이 남은 사람의 객체를 리턴함
		void setName(char * name);
		char * getName();
		void setMoney(int money);
		int getMoney();
		char ** getList();
		int getIndex();
};

Happy::Happy(char *np, int money)
{
	strcpy(this->name, np);
	this->money = money;
	this->index = 0;
}

Happy::Happy(Happy &r)
{
	int i;
	strcpy(this->name, r.name);
	this->money = r.money;

	this->index = r.index;

	for(i=0; i<r.index; i++)
	{
		this->list[i] = new char[strlen(r.list[i]) + 1];
		strcpy(this->list[i], r.list[i]);
	}
}

Happy::~Happy()
{
	int i;
	for(i=0; i<this->index; i++)
	{
		delete[] this->list[i];
	}
}

Happy & Happy::operator=(Happy &r)
{
	if(this == &r)	return *this;

	int i;
	strcpy(this->name, r.name);
	this->money = r.money;
	
	
	for(i=0; i<this->index; i++)
	{
		delete[] this->list[i];
	}

	this->index = r.index;

	for(i=0; i<r.index; i++)
	{
		this->list[i] = new char[strlen(r.list[i]) + 1];
		strcpy(this->list[i], r.list[i]);
	}
	return *this;
}

void Happy::use(char *lp, int n)
{
	this->list[this->index] = new char[strlen(lp) + 1];
	strcpy(this->list[this->index], lp);
	this->index++;
	this->money -= n;	
}

Happy & Happy::winner(Happy &r)
{
	if(this->money >= r.money)
	{
		return *this;
	}
	else
	{
		return r;
	}
}

void Happy::setName(char * name)
{
	strcpy(this->name, name);
}

char * Happy::getName()
{
	return this->name;
}

void Happy::setMoney(int money)
{
	this->money = money;
}

int Happy::getMoney()
{
	return this->money;
}

char ** Happy::getList()
{
	return this->list;
}

int Happy::getIndex()
{
	return this->index;
}

int main()
{
	int i;
	Happy a("철이"), b("메텔"), w;
	char item[100];
	int price;

	cout << "철이가 돈을 씁니다..." << endl;
	while(1)
	{
		cout << "구입 내역 : ";
		cin >> item;
		if(strcmp(item, "끝")==0)	break;
		cout << "금액 입력 : ";
		cin >> price;
		a.use(item, price);
	}

	cout << "메텔이 돈을 씁니다..." << endl;
	while(1)
	{
		cout << "구입 내역 : ";
		cin >> item;
		if(strcmp(item, "끝")==0)	break;
		cout << "금액 입력 : ";
		cin >> price;
		b.use(item, price);
	}

	cout << "최종 승자는?" << endl;
	w=a.winner(b);
	cout << w.getName() << "이고 총 " << w.getIndex()	 << "건을 사용하고 남은 금액은 " << w.getMoney() << "원 입니다." << endl;
	
	for(i=0; i<w.getIndex(); i++)
	{
		cout << w.getList()[i] << endl;
	}

	Happy t(a);

	return 0;
}

