#include <iostream>
#include "time.h"
using namespace std;

int main()
{
	Time a(3, 20), b(4.7);
	cout << a.getHour() << ":" << a.getMin() << endl;
	cout << b.getHour() << ":" << b.getMin() << endl;

	Time res = a.plus(b);
	cout << "�� �ð��� ���ϸ� : ";
	cout << res.getHour() << ":" << res.getMin() << endl;

	return 0;
}