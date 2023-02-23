/*
		2012년 8월 16일
		연습문제 5번
		작성자 : 이로운
										*/
#include <iostream>
using namespace std;

void swap_str(char * &p1, char * &p2);
int main()
{
	char *ap = "apple";
	char *bp = "banana";

	cout << "바꾸기 전의 문자열 : " << ap << " " << bp << endl;
	swap_str(ap, bp);
	cout << "바꾼 후의 문자열 : " << ap << " " << bp << endl;
}

//포인터변수의 값을 바꾸는 함수
void swap_str(char * &p1, char * &p2)
{
	char *tmp;

	//swap
	tmp = p1;
	p1 = p2;
	p2 = tmp;

	return;
}