#include <iostream>
#include <string.h>
using namespace std;

class Happy
{
	private:
		char name[100];		//�̸�
		int money;			//�ܾ�
		char * list[100];	//��� ������ �����ϴ� char * �迭
		int index;			//��� ���� ����
	public:
		Happy(char *np="", int money=10000);	//����Ʈ ������ �Լ�
		Happy(Happy &r);						//���� ������ �Լ�
		~Happy();								//�Ҹ��� �Լ�
		Happy & operator=(Happy &r);
		void use(char *lp, int n);				//����Լ�(��볻���� �ݾ��� �޴´�)
		Happy &winner(Happy &r);				//�ܾ� ���Ͽ� ���� �ݾ��� ���� ����� ��ü�� ������
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
	Happy a("ö��"), b("����"), w;
	char item[100];
	int price;

	cout << "ö�̰� ���� ���ϴ�..." << endl;
	while(1)
	{
		cout << "���� ���� : ";
		cin >> item;
		if(strcmp(item, "��")==0)	break;
		cout << "�ݾ� �Է� : ";
		cin >> price;
		a.use(item, price);
	}

	cout << "������ ���� ���ϴ�..." << endl;
	while(1)
	{
		cout << "���� ���� : ";
		cin >> item;
		if(strcmp(item, "��")==0)	break;
		cout << "�ݾ� �Է� : ";
		cin >> price;
		b.use(item, price);
	}

	cout << "���� ���ڴ�?" << endl;
	w=a.winner(b);
	cout << w.getName() << "�̰� �� " << w.getIndex()	 << "���� ����ϰ� ���� �ݾ��� " << w.getMoney() << "�� �Դϴ�." << endl;
	
	for(i=0; i<w.getIndex(); i++)
	{
		cout << w.getList()[i] << endl;
	}

	Happy t(a);

	return 0;
}

