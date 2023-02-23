#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)
int y_ch(int);
void input(int *, int *, int *);
void output(int, int, int, char[]);
int main() 
{
	int year, month, day, i, ych, tot;
	int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char yo[3];

	while(1)
	{
		tot = 0;
		input(&year, &month, &day);

		for(i=1; i<=year-1; i++)
		{			
			tot += 365;
			if((ych=y_ch(i)) == 1)
			{
				tot++;
			}
		}

		for(i=0; i<month-1; i++)
		{
			tot += mon[i];
		}

		tot += day;
		if((y_ch(year)==1) && (month>=3))	tot++;

		switch(tot%7)
		{
			case 0 : strcpy(yo, "일"); break;
			case 1 : strcpy(yo, "월"); break;
			case 2 : strcpy(yo, "화"); break;
			case 3 : strcpy(yo, "수"); break;
			case 4 : strcpy(yo, "목"); break;
			case 5 : strcpy(yo, "금"); break;
			case 6 : strcpy(yo, "토"); break;
		}

		output(year, month, day, yo);
	}
	
	return 0;
}

void output(int y, int m, int d, char yo[3])
{
	printf("%d년 %d월 %d일은 %s요일입니다.\n\n", y, m, d, yo);
}

void input(int *y, int *m, int *d)
{
	printf("* 년월일을 입력하시오 : ");
	scanf("%d %d %d", y, m, d);

	return;
}

int y_ch(int year)
{
	if(year%4 != 0)
	{
		return 0;
	}
	else if(year%100 != 0)
	{
		return 1;
	}
	else if(year%400 != 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}	
}