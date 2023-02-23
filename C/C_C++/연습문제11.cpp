#include <iostream>
#include <iomanip>
using namespace std;

class MyArray
{
private:
	int *ary;
	int size;
public:
	MyArray()	{ ary=0; size=0; } //디폴트 생성자
	MyArray(int s);	//오버로디드 생성자
	MyArray(const MyArray &br);	//복사 생성자
	~MyArray() { delete [] ary; }	//소멸자
	MyArray &operator=(const MyArray &br);	//대엽연산자
	void put(int index, int val);	//val의 값을 index방에 저장
	int get(int index);	//배열요소 중 index방의 값을 리턴
	int getSize();	//배열요소의 개수 확인
	int *getAry(void);	//배열요소의 내용 확인
};

MyArray::MyArray(int s) : size(s)
{
	this->ary = new int[s];
}

MyArray::MyArray(const MyArray &br)
{
	int i;

	this->ary = new int[br.size];
	this->size = br.size;
	
	for(i=0; i<br.size; i++)
	{
		this->ary[i] = br.ary[i];
	}
}

MyArray& MyArray::operator=(const MyArray &br)
{
	int i;
	if(this==&br) return *this;
	this->size = br.size;
	delete[] ary;

	ary = new int[this->size];
	
	for(i=0; i<this->size; i++)
	{
		ary[i] = br.ary[i];
	}

	return *this;
}

void MyArray::put(int index, int val)
{
	if(index > this->size || index < 0)
	{
		cout << "존재하지 않습니다" << endl;
	}
	else
	{
		this->ary[index] = val;
	}
}

int MyArray::get(int index)
{
	if(index > this->size || index < 0)
	{
		cout << "존재하지 않습니다" << endl;
		return 0;
	}
	else
	{
		return this->ary[index];
	}	
}

int MyArray::getSize()
{
	return this->size;
}

int *MyArray::getAry(void)
{
	return this->ary;
}

class SmartArray : public MyArray
{
private:
	int max;	//최고값 저장
public:
	SmartArray() {}	//디폴트 생성자
	SmartArray(int s) : MyArray(s), max(0)	//오버로디드 생성자
	{}
	void put(int index, int val);	//put함수의 재정의
	int getMax();	//max값 리턴
	bool operator>(const SmartArray &br);	//비교연산자
};

void SmartArray::put(int index, int val)
{
	if(max<val)
	{
		max = val;
	}
	
	MyArray::put(index, val);
}

int SmartArray::getMax()
{
	return this->max;
}

bool SmartArray::operator>(const SmartArray &br)
{
	if(this->max > br.max)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int i;
	int temp[5];
	int tot=0;
	double avg;
	SmartArray ch(3), me(5);

	cout << "철이의 세 과목의 점수 입력 : ";
	for(i=0; i<ch.getSize(); i++)
	{
		cin >> temp[i];
		ch.put(i, temp[i]);
	}

	for(i=0; i<ch.getSize(); i++)
	{
		tot += ch.get(i);
	}
	cout << "철이의 총점 : " << tot << endl;

	avg = tot / 3.0;
	cout << fixed;
	cout << setprecision(2);
	cout << "철이의 평균 : " << avg << endl;

	tot = 0;
	cout << dec;

	cout << "메텔의 다섯 과목의 점수 입력 : ";
	for(i=0; i<me.getSize(); i++)
	{
		cin >> temp[i];
		me.put(i, temp[i]);
	}

	for(i=0; i<me.getSize(); i++)
	{
		tot += me.get(i);
	}
	cout << "메텔의 총점 : " << tot << endl;

	avg = tot / 5.0;
	cout << fixed;
	cout << setprecision(2);
	cout << "메텔의 평균 : " << avg << endl;

	if(ch > me)
	{
		cout << "ㅋㅋㅋ" << endl;
	}
	else
	{
		cout << "철이는 최고점은 메텔보다 크지 않다..." << endl;
	}

	return 0;
}