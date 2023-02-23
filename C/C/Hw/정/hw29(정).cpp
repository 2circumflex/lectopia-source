// ����29 �Ѵ�ġ �޷�����ϱ�
// ���α׷��� : �����Ǿ� ������ ����

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

	tot_date=Totdays(year,mon);   // ����� �޷��� 1�ϱ����� �ѳ����� ���Ͽ� ���ϵȰ��� tot_date�� ����
	Title_display(year, mon);     // �޷��� ������ ����ϴ� �Լ� ȣ��

	if(mon==2 && Leap_check(year)) datecnt = month[mon-1]+1;  // �޷��� ������ ��¥�� ����ϴ� �κ�
	else datecnt = month[mon-1];

	yoil = tot_date%7;               // ����� �޷��� 1���� ������ �����
	Date_display(datecnt, yoil);     // 1�� ���� ���ϱ��� ����ϴ� �Լ� ȣ��

    printf("\n\n");
    return 0;
 }

//--------------------------------------------------------------------------

 long Totdays(int year, int mon)  // �ѳ��� ���ϴ� �Լ� 
 {
	int i;
	long tot=0;

	for(i=1; i<year; i++){    // �⵵�� �ѳ��� ���ϱ�
		if(Leap_check(i)) tot+=366;
		else tot+=365;
	}
	for(i=0; i< mon-1; i++) tot+=month[i];  // ���� �ѳ��� ���ϱ� 
	if(Leap_check(year) && mon>2) tot++;  // �Է³⵵�� �����̰� ���� 3���̻��̸� 2��29�� �Ϸ� �߰�
	tot++;        // �ش� ���� 1�ϱ����� ���� ���ؾ� �ϹǷ� �ѳ����� 1�� �߰� 
	return (tot);
 }

 //--------------------------------------------------------------------------

 int Leap_check(int y) // �����̸� 1, ����̸� 0�� �����ϴ� �Լ�
 {
	if( (y%4==0)&&(y%100!=0) || (y%400==0) ) return (1);
	else return (0);
 }

 //--------------------------------------------------------------------------

 void Title_display(int year, int mon)  // �޷� Ÿ��Ʋ ����Լ� 
 {
	gotoxy(33,8);	printf("[%5d . %2d ]", year, mon);
	gotoxy(20,10);  printf("  SUN  MON  TUE  WED  THU  FRI  SAT");
	gotoxy(20,11);  printf("--------------------------------------");
 }

 //--------------------------------------------------------------------------
 
 void Date_display(int cnt, int yoil)   // �޷��� ��¥ �κ� ����ϴ� �Լ�
 {
	int x, y=12, i, sx=20;

	for(i=1; i<=cnt; i++){
		x=sx+5*yoil;      // ������ ��ȭ�� ���� x ��ǥ ���ϴ� ����
		gotoxy(x,y);
		printf("%5d",i);   // ��¥�� 5ĭ�� �ʵ����� ��� ����Ѵ�.
		yoil++;
		if(yoil%7==0){    // ����� ���� ����ϰ� �Ͽ��� ����� �����̸�
			y++;          // �޷»󿡼� ���� �ٲ��� �ϹǷ� y��ǥ�� ���������ش�.
			yoil = 0;     // x��ǥ ����� ���ؼ� �Ͽ����� ����ϱ� ���� yoil�� 0���� �������ش�.
		}
	}
 }
 
 //--------------------------------------------------------------------------

 void gotoxy(int x, int y) 
 { 
	COORD Pos = {x - 1, y - 1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
 }
