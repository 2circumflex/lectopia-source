/* 날짜 : 2012년 2월 3일   
   작성자 : 이로운   
   프로그램의 기능 : 성과 이름을 입력 받아 입력된 이름을 출력하고 다음 라인에 성과 이름의 글자 수를 각각 성과 이름뒷자리에 맞추어 출력하시오 */
#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996)

int main()
{
	char sung[20], name[20];

	printf("#성을 입력하시오 : ");
	scanf("%s", sung);
	printf("#이름을 입력하시오 : ");
	scanf("%s", name);

	printf("%s %s\n", sung, name);
	printf("%*d %*d\n", strlen(sung), strlen(sung), strlen(name), strlen(name));	

	return 0;
}