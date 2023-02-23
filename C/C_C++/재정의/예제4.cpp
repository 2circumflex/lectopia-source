#include <iostream>
using namespace std;

class Base
{
public:
	virtual void view()	{ cout << "기초클래스 view..." << endl; }
};

class Derived : public Base
{
public:
	void view()	{ cout << "유도클래스 view..." << endl; }
};

int main()
{
	Base a;
	Derived b;

	Base *bp = &a;
	Derived *dp = &b;
	//bp->view();	//기초클래스의 view호출
	//dp->view();	//유도클래스의 재정의된 view호출
	//bp = &b;
	//bp->view();

	bp = &a;
	bp->view();
	dp= &b;
	dp->view();

	return 0;
}