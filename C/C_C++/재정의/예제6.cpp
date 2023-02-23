#include <iostream>
using namespace std;
#include <string.h>
class Teacher
{
private:
	char name[20];
	int pay;
public:
	Teacher(const char *np="와우!!", int p=0)
	{
		strcpy(name, np);
		pay = p;
	}
	virtual void teach()=0;	//{ cout << "가르친다.." << endl; }
	void view()	{ cout << "이름 : " << name << ", 수업료 : " << pay << endl; }
};

class kTeacher : public Teacher
{
public:
	kTeacher(const char *np="와우!!", int p=0) : Teacher(np, p) {}
	//void teach() { cout << "국어를 가르친다..." << endl; }
};

class eTeacher : public Teacher
{
public:
	eTeacher(const char *np = "와우!!", int p = 0) : Teacher(np, p) {}
	void teach() { cout << "영어를 가르친다..." << endl; }
};

class mTeacher : public Teacher
{
public:
	mTeacher(const char *np = "와우!!", int p = 0) : Teacher(np, p) {}
	void teach() { cout << "수학을 가르친다..." << endl; }
};

int main()
{
	//Teacher ob;
	Teacher * cheoli[2];
	cheoli[0] = new kTeacher("홍길동", 70);
	cheoli[1] = new mTeacher("이순신", 80);

	Teacher * metel[3];
	metel[0] = new kTeacher("신사임당", 200);
	metel[1] = new eTeacher("임꺽정", 50);
	metel[2] = new mTeacher("강감찬", 90);

	int i;
	cout << "철이의 선생님..." << endl;
	for(i=0; i<2; i++)
	{
		cheoli[i]->view();
		cheoli[i]->teach();
	}

	cout << "메텔의 선생님..." << endl;
	for(i=0; i<3; i++)
	{
		metel[i]->view();
		metel[i]->teach();
	}
}