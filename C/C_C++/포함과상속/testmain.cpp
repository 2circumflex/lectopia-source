#include <iostream>
#include <string.h>
#include "Profile.h"
#include "MyString.h"
using namespace std;

void userScreen(void);
char menu(void);
int proInput(Profile *, int &);
void proDisplay(Profile *,int);
void proUpdate(Profile *, int);

int main()
{
	userScreen();
	return 0;
}
//--------------------------------------------------------------
void userScreen()
{
	Profile  ary[20]; // ������ ���� ��ü �迭
	int profileCnt=0; // �Է� ���� �������� ���� ī��Ʈ ����
    char ch;  // �޴���ȣ ���� ���� 

	while(1){
		ch=menu(); // �Էµ� �޴��� ��ȣ�� ch�� ���Ϲ���
		if(ch=='4') {break;}  // 4�� �����ϱ� �޴��� �ԷµǾ����� ���ѹݺ����� Ż���Ѵ�.
		switch(ch){
			case '1' : proInput(ary, profileCnt); break;
			case '2' : proUpdate(ary,profileCnt); break;
			case '3' : proDisplay(ary,profileCnt); break;
		}
	}
}
//-------------------------------------------------------------
char menu(void)
{
	char n=0, i;
	char menulist[4][20] = { "������ �Է�", "������ ����", "������ ���","����" };
	
	for(i=0; i<4; i++){  // �޴� ���ڿ��� ����ϴ� �ݺ���
		cout << i+1 <<". " << menulist[i]<< endl;
	}
	while(n<'1' || n>'5'){  //�Է��� �޴���ȣ�� ��ȿ�� ��ȣ�� �ƴϸ� �ٽ� �Է�
		cout << "* Select menu No. : _\b";
		cin >> n;
	}
	return(n);
}
 //------------------------------------------------------------
int proInput(Profile *ary, int &cnt){
	char name[50];
	char addr[80];
	int age;
	double height;
	  // �Է� ���� �������� ������ ī��Ʈ�ϴ� ����

	while(1){
		cout << "�̸��Է� : "; 		cin >> name;
		if(strcmp(name,"��")==0) {break;}
		cout << "�ּ��Է� : ";		cin >> addr;
		cout << "�����Է� : ";		cin >> age;
		cout << "Ű�Է� : ";		cin >> height;

		ary[cnt]=Profile(name, addr, age, height); // �Է� ���� �����ͷ� ��ü �����Ͽ� �迭�� ����
		cnt++;
	}

	return cnt;
}
//---------------------------------------------------------------
void proDisplay(Profile *ary, int cnt)
{
	int i;
	for(i=0; i<cnt; i++){
		cout << i+1 <<". " << ary[i].getName().getStr() << " : " 
		    << ary[i].getAddr().getStr() << " / " << ary[i].getAge() << "�� / "
			<< ary[i].getHeight() << "cm" << endl;
	}
}

void proUpdate(Profile *ary, int profileCnt)
{
	int i, age;
	char name[50];
	char addr[100];
	MyString tmp;
	double height;
	cout << "������ �̸� : ";
	cin >> name;

	for(i=0; i<profileCnt; i++)
	{
		if(strcmp(ary[i].getName().getStr(), name)==0)
		{
			cout << "������ �ּ� : ";
			cin >> addr;

			cout << "������ ���� : ";
			cin >> age;

			cout << "������ Ű : ";
			cin >> height;

			tmp.setStr(addr);

			ary[i].setAge(age);
			ary[i].setHeight(height);
			ary[i].setAddr(tmp);

			break;
		}
	}
	


}