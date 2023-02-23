/* 날짜 : 2012년 2월 17일   
   작성자 : 이로운   
   프로그램의 기능 : 1~20까지의 숫자로만 초기화된 배열을 특정숫자의 개수를 세어 출력하기 */
#include <stdio.h>
#pragma warning (disable : 4996)
int main()
{	
	int ary[] = {2,8,15,1,8,10,5,19,19,3,5,6,6,2,8,2,12,16,3,8,17,12,5,3,14,13,3,2,17,19,16,8,7,12,19,10,13,8,20,16,15,4,12,3,14,14,5,2,12,14,9,8,5,3,18,18,20,4};
	int len, cnt, su, i;
	len = sizeof(ary)/sizeof(ary[0]);

	while(1)
	{
		cnt = 0;
		printf("찾기를 원하는 숫자를 입력하세요(1~20) : ");
		fflush(stdin);
		scanf("%d", &su);

		for(i=0; i<len; i++)
		{
			if(ary[i] == su)
			{
				cnt++;
			}
		}

		printf("숫자 %d 는 배열에 %d개 있습니다.\n\n", su, cnt);
	}
	
	return 0;
}