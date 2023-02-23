#include <iostream>
#include <iomanip>
using namespace std;

class MyArray
{
private:
	int *ary;
	int size;
public:
	MyArray()	{ ary=0; size=0; } //����Ʈ ������
	MyArray(int s);	//�����ε�� ������
	MyArray(const MyArray &br);	//���� ������
	~MyArray() { delete [] ary; }	//�Ҹ���
	MyArray &operator=(const MyArray &br);	//�뿱������
	void put(int index, int val);	//val�� ���� index�濡 ����
	int get(int index);	//�迭��� �� index���� ���� ����
	int getSize();	//�迭����� ���� Ȯ��
	int *getAry(void);	//�迭����� ���� Ȯ��
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
		cout << "�������� �ʽ��ϴ�" << endl;
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
		cout << "�������� �ʽ��ϴ�" << endl;
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
	int max;	//�ְ� ����
public:
	SmartArray() {}	//����Ʈ ������
	SmartArray(int s) : MyArray(s), max(0)	//�����ε�� ������
	{}
	void put(int index, int val);	//put�Լ��� ������
	int getMax();	//max�� ����
	bool operator>(const SmartArray &br);	//�񱳿�����
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

	cout << "ö���� �� ������ ���� �Է� : ";
	for(i=0; i<ch.getSize(); i++)
	{
		cin >> temp[i];
		ch.put(i, temp[i]);
	}

	for(i=0; i<ch.getSize(); i++)
	{
		tot += ch.get(i);
	}
	cout << "ö���� ���� : " << tot << endl;

	avg = tot / 3.0;
	cout << fixed;
	cout << setprecision(2);
	cout << "ö���� ��� : " << avg << endl;

	tot = 0;
	cout << dec;

	cout << "������ �ټ� ������ ���� �Է� : ";
	for(i=0; i<me.getSize(); i++)
	{
		cin >> temp[i];
		me.put(i, temp[i]);
	}

	for(i=0; i<me.getSize(); i++)
	{
		tot += me.get(i);
	}
	cout << "������ ���� : " << tot << endl;

	avg = tot / 5.0;
	cout << fixed;
	cout << setprecision(2);
	cout << "������ ��� : " << avg << endl;

	if(ch > me)
	{
		cout << "������" << endl;
	}
	else
	{
		cout << "ö�̴� �ְ����� ���ں��� ũ�� �ʴ�..." << endl;
	}

	return 0;
}