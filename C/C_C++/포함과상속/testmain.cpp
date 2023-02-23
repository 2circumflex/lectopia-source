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
	Profile  ary[20]; // 프로필 저장 객체 배열
	int profileCnt=0; // 입력 받은 프로필의 개수 카운트 변수
    char ch;  // 메뉴번호 저장 변수 

	while(1){
		ch=menu(); // 입력된 메뉴의 번호를 ch에 리턴받음
		if(ch=='4') {break;}  // 4번 종료하기 메뉴가 입력되었으면 무한반복문을 탈출한다.
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
	char menulist[4][20] = { "프로필 입력", "프로필 수정", "프로필 출력","종료" };
	
	for(i=0; i<4; i++){  // 메뉴 문자열을 출력하는 반복문
		cout << i+1 <<". " << menulist[i]<< endl;
	}
	while(n<'1' || n>'5'){  //입력한 메뉴번호가 유효한 번호가 아니면 다시 입력
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
	  // 입력 받은 프로필의 개수를 카운트하는 변수

	while(1){
		cout << "이름입력 : "; 		cin >> name;
		if(strcmp(name,"끝")==0) {break;}
		cout << "주소입력 : ";		cin >> addr;
		cout << "나이입력 : ";		cin >> age;
		cout << "키입력 : ";		cin >> height;

		ary[cnt]=Profile(name, addr, age, height); // 입력 받은 데이터로 객체 생성하여 배열에 저장
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
		    << ary[i].getAddr().getStr() << " / " << ary[i].getAge() << "세 / "
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
	cout << "수정할 이름 : ";
	cin >> name;

	for(i=0; i<profileCnt; i++)
	{
		if(strcmp(ary[i].getName().getStr(), name)==0)
		{
			cout << "수정할 주소 : ";
			cin >> addr;

			cout << "수정할 나이 : ";
			cin >> age;

			cout << "수정할 키 : ";
			cin >> height;

			tmp.setStr(addr);

			ary[i].setAge(age);
			ary[i].setHeight(height);
			ary[i].setAddr(tmp);

			break;
		}
	}
	


}