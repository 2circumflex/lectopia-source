#include "san.h"
#include <iostream>
using namespace std;

int main()
{
	San a("����", 629);
	//San b=a;
	San b;
	b=a;

	cout << b.getName() << " : " << b.getHeight() << "m" <<endl;

	return 0;
}