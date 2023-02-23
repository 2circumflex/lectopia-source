#include <iostream>
#include <iomanip>
using namespace std;
#include <iostream>
#include <iomanip>
#include "myArray.h"
#include "SmartArray.h"

int main()
{
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	MyArray<double> height(3);

	int i;
	double tot = 0;
	double temp;

	cout << "세 학생의 키 입력 : ";
	for(i=0; i<3; i++)
	{
		cin >> temp;
		height.put(i, temp);
	}

	for(i=0; i<3; i++)
	{
		tot += height.get(i);
	}
	cout << "평균키 : " << tot/3.0 << endl;
	return 0;
}