#include "robot.h"
#include <iostream>
using namespace std;
//Robot t("¯��", 200);
//Robot ex("��ʽ�", 100);
int main()
{
	Robot ary[3];
	int i, num, ene;
	char temp[50];
	int energy;

	for(i=0; i<3; i++)
	{
		cout << i+1 << "�� Robot �̸� : ";
		cin >> temp;

		cout << temp << "�� energy �Է� : ";
		cin >> energy;
		
		ary[i].setName(temp);
		ary[i].setEnergy(energy);		
	}


	while(1)
	{
		cout << "�Ͻ�ų �κ� ����(�κ���ȣ 1~3/4�Է½� ����) : ";
		cin >> i;
		if(i == 4)	break;
		i-=1;
		cout << ary[i].getName() << "��ų ����?(1����/2����/3��/4����/5����) : ";
		cin >> num;
	
		switch(num)
		{
		case 1:
			ary[i].go();
			break;
		case 2:
			ary[i].back();
			break;
		case 3:
			ary[i].turn();
			break;
		case 4:
			ary[i].jump();
			break;
		case 5:
			cout << "������ �Է� : ";
			cin >> ene;
			ary[i].charge(ene);
			break;
		}
	}

	for(i=0; i<3; i++)
	{
		cout << ary[i].getName() << " : " << ary[i].getEnergy() << endl;
	}

	//Robot r1;	//�޸� �� ����
	//Robot r2;	//�޸� �� ����

	//Robot r1;
	//
	//Robot r2("��Ű", 350);

	//Robot r3(r2);

	//r1.setName("�±Ǻ���");

	//r1=r2;
	//r1=r1;

	//if(r1==r2)
	//{		
	//	cout << "����" << endl;
	//}
	//else
	//{		
	//	cout << "�ٸ���" << endl;
	//}

	//Robot r3("��ʽ�");

	/*r1.setName("�±�v");
	r1.setEnergy(300);

	r1.init("�±�v", 300);
	r2.init("��¡��z", 250);*/
	
	/*cout << r1.getName() << " " << r1.getEnergy() << endl;
	cout << r2.getName() << " " << r2.getEnergy() << endl;

	cout<<"-------------------------------"<<endl;

	r1.go();
	r2.go();
	r1.back();
	r2.back();
	r1.turn();
	r2.turn();
	r1.jump();
	r2.jump();

	cout<<"-------------------------------"<<endl;

	r1.go();
	r2.go();
	r1.back();
	r2.back();
	r1.turn();
	r2.turn();
	r1.jump();
	r2.jump();

	cout<<"-------------------------------"<<endl;

	r1.go();
	r2.go();
	r1.back();
	r2.back();
	r1.turn();
	r2.turn();
	r1.jump();
	r2.jump();

	cout<<"-------------------------------"<<endl;

	r1.go();
	r2.go();
	r1.back();
	r2.back();
	r1.turn();
	r2.turn();
	r1.jump();
	r2.jump();

	cout<<"-------------------------------"<<endl;

	r1.charge(50);
	r2.charge(100);

	cout<<"-------------------------------"<<endl;

	cout << r1.getName() << " " << r1.getEnergy() << endl;
	cout << r2.getName() << " " << r2.getEnergy() << endl;*/

	return 0;
}