/*
		2012�� 8�� 16��
		�������� 5��
		�ۼ��� : �̷ο�
										*/
#include <iostream>
using namespace std;

void swap_str(char * &p1, char * &p2);
int main()
{
	char *ap = "apple";
	char *bp = "banana";

	cout << "�ٲٱ� ���� ���ڿ� : " << ap << " " << bp << endl;
	swap_str(ap, bp);
	cout << "�ٲ� ���� ���ڿ� : " << ap << " " << bp << endl;
}

//�����ͺ����� ���� �ٲٴ� �Լ�
void swap_str(char * &p1, char * &p2)
{
	char *tmp;

	//swap
	tmp = p1;
	p1 = p2;
	p2 = tmp;

	return;
}