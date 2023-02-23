#include <iostream>
using namespace std;

class Save
{
private:
	char name[20];	//������
	int capital;	//����
	int profit;		//����
	static double ratio;	//������
	int total;		//1���� ���ɱݾ�
public:
	Save(char *name, int capital);
	~Save();
	void calculate();	//���ɾװ��
	void setName(char *np);
	char* getName();
	void setCapital(int);
	int getCapital() const;
	void setProfit(int);
	int getProfit() const;
	static void setRatio(double);
	static double getRaio();
	void setTotal(int);
	int getTotal()const;
};

double Save::ratio=0;

Save::Save(char *name, int capital2) : capital(capital2)
{
	strcpy(this->name, name);
	//this->capital = capital;
	this->profit = 0;
	this->total = 0;
}

Save::~Save()
{

}

void Save::calculate()
{
	this->profit = this->capital * ratio;
	this->total = this->capital + this->profit;
}

void Save::setName(char *name)
{
	strcpy(this->name, name);
}

char * Save::getName()
{
	return this->name;
}

void Save::setCapital(int capital)
{
	this->capital = capital;
}

int Save::getCapital() const
{
	return this->capital;
}

void Save::setProfit(int profit)
{
	this->profit = profit;
}

int Save::getProfit() const
{
	return this->profit;
}

void Save::setRatio(double ratio1)
{
	ratio = ratio1;
}

double Save::getRaio()
{
	return ratio;
}

void Save::setTotal(int total)
{
	this->total = total;
}

int Save::getTotal() const
{
	return this->total;
}

int main()
{
	char name[20];
	int capital;
	double ratio;
	cout << "�����ָ� : ";
	cin >> name;
	cout << "���� : ";
	cin >> capital;
	cout<<"������ :";
	cin>>ratio;

	Save r1(name,capital);
	Save::setRatio(ratio);
	r1.calculate();
	cout<<"�ѱݾ� : "<<r1.getTotal()<<endl;



	cout<<"������2 : ";
	cin>>ratio;
	Save::setRatio(ratio);
	r1.calculate();
	cout<<"�ѱݾ� : "<<r1.getTotal()<<endl;

	return 0;
}


