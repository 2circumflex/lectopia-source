#include <iostream>
using namespace std;
#include "MyFruit.h"

int main()
{
	// �Ф��� ���߽��ϴ�......;;;;;;
	char fName[50];
	char oName[50];
	int quantity;
	int buyPrice;
	int num;
	int fNum;
	int su;

	cout << "ù��° ���� �� ���ڸ� ��ɴϴ�..." << endl;
	cout << "�����Է� : ";
	cin >> fName;
	cout << "������ : ";
	cin >> oName;
	cout << "���԰��� : ";
	cin >> buyPrice;
	cout << "���� : ";
	cin >> quantity;
	MyFruit a(fName, quantity, buyPrice, oName);
	
	cout << "�ι�° ���� �� ���ڸ� ��ɴϴ�..." << endl;
	cout << "�����Է� : ";
	cin >> fName;
	cout << "������ : ";
	cin >> oName;
	cout << "���԰��� : ";
	cin >> buyPrice;
	cout << "���� : ";
	cin >> quantity;
	MyFruit b(fName, quantity, buyPrice, oName);

	while(1)
	{
		cout << "��縦 �����մϴ�..." << endl;
		cout << "�׸� ���� [�Ǹ�-1, ��ǰ-2, ����-3] : ";
		cin >> num;
		if(num != 3)
		{
			cout << "���� ���� "<< a.getItem() << "-1, " << b.getItem() << "-2 :";
			cin >> fNum;
			cout << "���� : ";
			cin >> su;
			
			if(num == 1)
			{
				if(fNum == 1)
				{
					a.setQuantity(a.getQuantity() - su);
				}
				else
				{
					b.setQuantity(b.getQuantity() - su);			
				}				
			}
			else if(num == 2)
			{
				if(fNum == 1)
				{
					a.back(su);
				}
				else
				{
					b.back(su);
				}
			}
			cout << "** ���� ���..." << endl;
			cout << "ǰ�� : " << a.getItem() << " (" << a.getOrigin() << ")" << endl;
			cout << "���� ���� : " << a.getQuantity() << endl;
			cout << "���� ���� : " << a.getbuyPrice() << endl;
			cout << "���� : " << a.getSelprice() << endl;
			cout << "������ : " << a.getSelprice() - a.getbuyPrice() << endl;
			cout << endl;
			cout << "ǰ�� : " << b.getItem() << " (" << b.getOrigin() << ")" << endl;
			cout << "���� ���� : " << b.getQuantity() << endl;
			cout << "���� ���� : " << b.getbuyPrice() << endl;
			cout << "���� : " << b.getSelprice() << endl;
			cout << "������ : " << b.getSelprice() - b.getbuyPrice() << endl;
			cout << endl;
		}
		else
		{
			break;
		}
		
	}
	
	cout << "** ������ �ݾ��� ���� ����..." << endl;
	if(a>b)
	{
		cout << a.getItem() << endl;
	}
	else
	{
		cout << b.getItem() << endl;
	}

	return 0;
}