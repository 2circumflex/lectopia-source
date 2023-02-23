// 과제29 한달치 달력출력하기
// 프로그래머 : 렉토피아 정혜경 강사

 #include<stdio.h>
 #include<conio.h>
 #include<windows.h>  

  
 int Leap_check(int);
 long Totdays(int, int);
 void Title_display(int, int);
 void Date_display(int,int);
 void gotoxy(int, int);

 int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
 //--------------------------------------------------------------------------
 int main()
 {
	int year=2009, mon=7, datecnt, yoil;
	long tot_date;

	tot_date=Totdays(year,mon);   // 출력할 달력의 1일까지의 총날수를 구하여 리턴된값을 tot_date에 저장
	Title_display(year, mon);     // 달력의 제목을 출력하는 함수 호출

	if(mon==2 && Leap_check(year)) datecnt = month[mon-1]+1;  // 달력의 마지막 날짜를 계산하는 부분
	else datecnt = month[mon-1];

	yoil = tot_date%7;               // 출력할 달력의 1일의 요일을 계산함
	Date_display(datecnt, yoil);     // 1일 부터 말일까지 출력하는 함수 호출

    printf("\n\n");
    return 0;
 }

//--------------------------------------------------------------------------

 long Totdays(int year, int mon)  // 총날수 구하는 함수 
 {
	int i;
	long tot=0;

	for(i=1; i<year; i++){    // 년도의 총날수 구하기
		if(Leap_check(i)) tot+=366;
		else tot+=365;
	}
	for(i=0; i< mon-1; i++) tot+=month[i];  // 월의 총날수 구하기 
	if(Leap_check(year) && mon>2) tot++;  // 입력년도가 윤년이고 월이 3월이상이면 2월29일 하루 추가
	tot++;        // 해당 월의 1일까지의 합을 구해야 하므로 총날수에 1일 추가 
	return (tot);
 }

 //--------------------------------------------------------------------------

 int Leap_check(int y) // 윤년이면 1, 평년이면 0을 리턴하는 함수
 {
	if( (y%4==0)&&(y%100!=0) || (y%400==0) ) return (1);
	else return (0);
 }

 //--------------------------------------------------------------------------

 void Title_display(int year, int mon)  // 달력 타이틀 출력함수 
 {
	gotoxy(33,8);	printf("[%5d . %2d ]", year, mon);
	gotoxy(20,10);  printf("  SUN  MON  TUE  WED  THU  FRI  SAT");
	gotoxy(20,11);  printf("--------------------------------------");
 }

 //--------------------------------------------------------------------------
 
 void Date_display(int cnt, int yoil)   // 달력의 날짜 부분 출력하는 함수
 {
	int x, y=12, i, sx=20;

	for(i=1; i<=cnt; i++){
		x=sx+5*yoil;      // 요일의 변화에 따른 x 좌표 구하는 공식
		gotoxy(x,y);
		printf("%5d",i);   // 날짜를 5칸의 필드폭을 잡아 출력한다.
		yoil++;
		if(yoil%7==0){    // 토요일 까지 출력하고 일요일 출력할 차례이면
			y++;          // 달력상에서 줄이 바뀌어야 하므로 y좌표를 증가시켜준다.
			yoil = 0;     // x좌표 계산을 위해서 일요일을 출력하기 전에 yoil을 0으로 수정해준다.
		}
	}
 }
 
 //--------------------------------------------------------------------------

 void gotoxy(int x, int y) 
 { 
	COORD Pos = {x - 1, y - 1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
 }
