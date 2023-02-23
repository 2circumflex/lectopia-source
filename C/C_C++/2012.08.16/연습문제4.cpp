/*
		2012�� 8�� 16��
		�������� 4��
		�ۼ��� : �̷ο�
										*/
#include <iostream>
using namespace std;

struct Savings{
	int w500;	//500��¥�� ������ ���� ����
	int w100;	//100��¥�� ������ ���� ����
	int w50;	//50��¥�� ������ ���� ����
	int w10;	//10��¥�� ������ ���� ����
};

void init(Savings &s);
void input(int &unit, int &cnt);
void save(Savings &s, int unit, int cnt);
int total(Savings &s);

int main()
{
	Savings money;
	int coin=0, coinCnt, tot;	//����, ��������, �����ݾ�

	init(money);	//�ʱ�ȭ

	while(1)
	{
		input(coin, coinCnt);
		if(coin < 0)	break;			//0���� �������� �Է������� �׸��Է�
		save(money, coin, coinCnt);		
	}

	tot = total(money);
	cout << "�� ���ݾ� : " << tot << endl;

	return 0;
}

//�������� �ʱ�ȭ
//Savings ����ü���� 4���� ����� ��� 0���� �ʱ�ȭ ��
void init(Savings &s)
{
	s.w500 = 0;
	s.w100 = 0;
	s.w50 = 0;
	s.w10 = 0;
}

//�����ݾ�, ���������� �����Һ���
//Ű����κ��� �����ݾװ� ���� ������ �Է¹޾� unit�� cnt�� ������
void input(int &unit, int &cnt)
{	
	while(1)
	{
		cout << "������ �ݾ� : ";
		cin >> unit;
	
		while(cin.fail())			//�����Է��ؼ� ����������
		{
			cin.clear();
			while(cin.get()!='\n');
			cout << "������ �ݾ� : ";
			cin >> unit;
		}
		if(unit== 500 || unit==100 || unit==50 || unit==10)	break;	//�����Է��� ����� ������  �������� �Է��� ���� break
		else if(unit < 0)	return;		//0���� �������϶� ��������
	}
	
	cout << "������ ���� : ";
	cin >> cnt;
}

//������, ����, ������ ����
//������ ����ü ������ ����� ���� ���� ������ ���� ��ŭ ������
void save(Savings &s, int unit, int cnt)
{
	if(unit == 500)	s.w500 += cnt;			//500��¥�� ����
	else if(unit == 100) s.w100 += cnt;		//100��¥�� ����
	else if(unit == 50) s.w50 += cnt;		//50��¥�� ����
	else if(unit == 10) s.w10 += cnt;		//10��¥�� ����
}

//�������� �� ������� ����Ͽ� �����ϴ� �Լ�
int total(Savings &s)
{
	int tot = 0;	//��������� ������ ����

	tot = (500 * s.w500) + (100 * s.w100) + (50 * s.w50) + (10 * s.w10);	//�����ݾ� ���

	return tot;		//�����ݾ� ����
}