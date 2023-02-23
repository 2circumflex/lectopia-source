#include <iostream>
using namespace std;

class Letter
{
private:
	const char ch;
	int num;
public:
	Letter(char c='*', int n=0);
	void n_prn();
	void c_prn() const;
	void show();
};

Letter::Letter(char c, int n): ch(c)
{
	this->num = n;
}

void Letter::n_prn()
{
	//ch='@';
	this->num += 10;
	cout << "const가 아닌 멤버함수 호출..." << endl;
	this->show();
}

void Letter::c_prn() const
{
	//num += 10;
	cout << "const 멤버함수 호출" << endl;
	//show();
}	

void Letter::show()
{
	int i;
	for(i=0; i<num; i++)
	{
		cout << ch;
	}
	cout << endl;
}

int main()
{
	Letter a('@', 5);
	const Letter b('#', 3);

	a.n_prn();
	a.c_prn();
	//b.n_prn();
	b.c_prn();

	return 0;
}