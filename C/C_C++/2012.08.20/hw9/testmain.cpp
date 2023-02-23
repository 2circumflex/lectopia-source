#include <iostream>
#include "fitness.h"
#include <Windows.h>
#include <conio.h>
using namespace std;

int main()
{
	Fitness *ary[100];
	int cnt=0, num, i;
	char name[100];
	double weight;
	double height;
	double bmi;	

	while(1)
	{
		system("cls");
		cout << "1. ȸ�����"<<endl;
		cout << "2. ȸ����ü����"<<endl;
		cout << "3. ȸ�������˻�"<<endl;
		cout << "4. ȸ��Ż��"<<endl;
		cout << "5. Ư������ ȸ��"<<endl;
		cout << "6. ����"<<endl;
		cout << "�޴��� ������ : ";
		cin >> num;

		switch(num)
		{
		case 1:
			system("cls");
			while(1)
			{
				if(cnt==100)
				{
					break;
				}
				cout << "�̸�(end����) : ";
				cin >> name;
				if(strcmp(name, "end") == 0)	break;
				cout << "������ : ";
				cin >> weight;
				cout << "Ű : ";
				cin >> height;
		
				ary[cnt] = new Fitness(cnt+1, name, weight, height);
				cnt++;		
			}
			break;

		case 2:
			system("cls");
			for(i=0; i<cnt; i++)
			{
				cout << ary[i]->getNum() << " " << ary[i]->getName() << " " << ary[i]->getWeight() << " " << ary[i]->getHeight();
				cout << endl;
			}
			getch();
			break;

		case 3:
			system("cls");
			while(1)
			{
				cout << "�̸� �Է�(end����) : ";
				cin >> name;
				if(strcmp(name, "end")==0)	break;

				for(i=0; i<cnt; i++)
				{
					if(strcmp(name, ary[i]->getName()) == 0)
					{
						cout << ary[i]->getNum() << " " << ary[i]->getName() << " " << ary[i]->getWeight() << " " << ary[i]->getHeight();
						cout << endl;
						break;
					}
				}
				if(i==cnt)
				{
					cout << "����!!" << endl;
				}				
			}
			break;

		case 4:
			system("cls");
			while(1)
			{
				cout << "������ ��ȣ�� ��(-1����) : ";
				cin >> num;
				if(num == -1)	break;
				
				for(i=0; i<cnt; i++)
				{
					if(num == ary[i]->getNum())
					{
						*ary[i] = *ary[cnt-1];
						delete ary[cnt-1];
						cnt--;						
						cout << "�����Ϸ�" << endl;
						break;
					}
				}
				if(i==cnt)
				{
					cout << "����!!" << endl;
				}

			}
			break;
		case 5:
			system("cls");
			for(i=0; i<cnt; i++)
			{
				bmi = ary[i]->bmi();
				if(bmi >= 40.0)
				{
					cout << "[����] " << ary[i]->getNum() << " " << ary[i]->getName() << " " << ary[i]->getWeight() << " " << ary[i]->getHeight() << endl;
				}
				else if(bmi >= 30.0)
				{
					cout << "[��] " << ary[i]->getNum() << " " << ary[i]->getName() << " " << ary[i]->getWeight() << " " << ary[i]->getHeight() << endl;
				}
				else if(bmi >= 25.0)
				{
					cout << "[��ü��] " << ary[i]->getNum() << " " << ary[i]->getName() << " " << ary[i]->getWeight() << " " << ary[i]->getHeight() << endl;
				}				
			}
			getch();
			break;
		
		case 6:
			for(i=0; i<cnt; i++)
			{
				delete ary[i];
			}
			return 0;

		}
	}

	

	return 0;
}
