// 기초클래스(MoneyBox) 선언
#include "MyString.h"
class MoneyBox{
private:
	MyString name;  // 예금주
	int sum;   // 잔액
public:
	MoneyBox(const char *np="아무개", int m=0); // 오버로디드생성자
	MoneyBox(const MoneyBox &br);  // 복사생성자
	void save(int m);      // 저금
	void use(int m);       // 사용
	void setName(MyString name);   // name멤버수정
	MyString getName();            // name멤버값리턴
	void setSum(int sum);          // sum멤버수정
	int getSum();                  // sum멤버값리턴	
};