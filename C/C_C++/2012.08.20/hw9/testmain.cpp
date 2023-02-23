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
		cout << "1. 회원등록"<<endl;
		cout << "2. 회원전체보기"<<endl;
		cout << "3. 회원정보검색"<<endl;
		cout << "4. 회원탈퇴"<<endl;
		cout << "5. 특별관리 회원"<<endl;
		cout << "6. 종료"<<endl;
		cout << "메뉴를 고르세요 : ";
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
				cout << "이름(end종료) : ";
				cin >> name;
				if(strcmp(name, "end") == 0)	break;
				cout << "몸무게 : ";
				cin >> weight;
				cout << "키 : ";
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
				cout << "이름 입력(end종료) : ";
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
					cout << "없음!!" << endl;
				}				
			}
			break;

		case 4:
			system("cls");
			while(1)
			{
				cout << "삭제할 번호를 입(-1종료) : ";
				cin >> num;
				if(num == -1)	break;
				
				for(i=0; i<cnt; i++)
				{
					if(num == ary[i]->getNum())
					{
						*ary[i] = *ary[cnt-1];
						delete ary[cnt-1];
						cnt--;						
						cout << "삭제완료" << endl;
						break;
					}
				}
				if(i==cnt)
				{
					cout << "없음!!" << endl;
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
					cout << "[고도비만] " << ary[i]->getNum() << " " << ary[i]->getName() << " " << ary[i]->getWeight() << " " << ary[i]->getHeight() << endl;
				}
				else if(bmi >= 30.0)
				{
					cout << "[비만] " << ary[i]->getNum() << " " << ary[i]->getName() << " " << ary[i]->getWeight() << " " << ary[i]->getHeight() << endl;
				}
				else if(bmi >= 25.0)
				{
					cout << "[과체중] " << ary[i]->getNum() << " " << ary[i]->getName() << " " << ary[i]->getWeight() << " " << ary[i]->getHeight() << endl;
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
