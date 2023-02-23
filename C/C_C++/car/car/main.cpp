#include <iostream>
#include "companyA.h"
using namespace std;

void my_flush();

int main()
{
	companyA comA;
	Car ca;
	int unum, cnum, km;

	//��10�������� �Է�
	while(comA.getlen() != 10)
	{
		//����ȣ�Է�
		cout << "- ����ȣ(4�ڸ�) : ";
		cin >> unum;
		while(cin.fail() || comA.searchUnique(unum)==1 || unum>9999 || unum<0)
		{
			my_flush();
			cout << "- �ٽ��Է�(4�ڸ�) : ";
			cin >> unum;
		}
		if(unum == 0)	//0�Է½� �Է�����
		{
			cout << endl;
			break;
		}

		//�����ڵ��Է�
		cout << "- �����ڵ�(1~5) : ";
		cin >> cnum;
		while(cin.fail() || cnum<1 || cnum>5)
		{
			my_flush();
			cout << "- �ٽ��Է�(1~5) : ";
			cin >> cnum;
		}

		//����Ÿ��Է�
		cout << "- ����Ÿ�(KM����) : ";
		cin >> km;
		while(cin.fail() || km>999 || km<0)
		{
			my_flush();
			cout << "- �ٽ��Է�(KM����) : ";
			cin >> km;
		}

		cout << endl;

		ca.input(unum, cnum, km);	//����ȣ, �����ڵ�, ����Ÿ� �Է�
		ca.cal();	//�⺻���, �ѿ�ݰ��
		comA.appendFromTail(ca);	//���ϳ��տ� �߰�
	}
	comA.sortList();	//����ȣ ������������ ����
	comA.display();		//���÷���
}

void my_flush()
{
	cin.clear();	//flag���� 0���� ����

	while(cin.get() != '\n');
}
