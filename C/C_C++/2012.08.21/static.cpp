#include <iostream>
using namespace std;

class Save
{
private:
	char name[20];	//예금주
	int capital;	//원금
	int profit;		//이자
	static double ratio;	//이자율
	int total;		//1년후 수령금액
public:
	Save(char *name, int capital);
	~Save();
	void calculate();	//수령액계산
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
	cout << "예금주명 : ";
	cin >> name;
	cout << "원금 : ";
	cin >> capital;
	cout<<"이자율 :";
	cin>>ratio;

	Save r1(name,capital);
	Save::setRatio(ratio);
	r1.calculate();
	cout<<"총금액 : "<<r1.getTotal()<<endl;



	cout<<"이자율2 : ";
	cin>>ratio;
	Save::setRatio(ratio);
	r1.calculate();
	cout<<"총금액 : "<<r1.getTotal()<<endl;

	return 0;
}


