#include <iostream>
using namespace std;

class Base
{
public:
	virtual void view()	{ cout << "����Ŭ���� view..." << endl; }
};

class Derived : public Base
{
public:
	void view()	{ cout << "����Ŭ���� view..." << endl; }
};

int main()
{
	Base a;
	Derived b;

	Base *bp = &a;
	Derived *dp = &b;
	//bp->view();	//����Ŭ������ viewȣ��
	//dp->view();	//����Ŭ������ �����ǵ� viewȣ��
	//bp = &b;
	//bp->view();

	bp = &a;
	bp->view();
	dp= &b;
	dp->view();

	return 0;
}