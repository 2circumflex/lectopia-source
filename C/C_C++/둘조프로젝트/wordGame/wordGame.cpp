#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include <windows.h> 
#include <conio.h>
#include <assert.h>
#include <string.h>
#include "base.h"
#include "wordGame.h"
#pragma warning (disable:4996)

//-----------------------------------------------------------------------------------------------

#define MAX 100
#define random(n) (rand() % (n))

#define FLOOR "==============================================================================" 
#define F22 "괜찮아~~ 아직까진~"
#define F21 "흠 이정도에서 틀리다니 쯔쯔쯔~"
#define F20 "이제부터 시작이야 각오해~"
#define F19 "단어수가 적어질수록 빨라져~ 조심조심^^"
#define F18 "ㅋㅋㅋ 죽어라!!!~"
#define F17 "내 글을 읽어봐~ 넌 단어 입력 더못해~!!ㅋㅋ~"
#define F16 "후훗~"
#define F15 "이제~ 어떻하지~~??~"
#define F14 "멘붕이겠구만?~"
#define F13 "생각보다 어렵지? 형이 만든거여~~"
#define F12 "함영식!, 이로운!"
#define F11 "김상아~ 아.. 그리고.. 이름..이 뭐.. 였 ... 드라...ㅋ"
#define F10 "아 맞다!  우리 박지수가 만들었지~~ㅎㅎ"
#define F9 "이제 끝날때가 되었군..~"
#define F8 "이쯤에서 계속 치고 있음 넌 이미 고수~"
#define F7 "카운트 다운 들어갑니다잉~"
#define F6 "444444~"
#define F5 "333333~"
#define F4 "222222~"
#define F3 "111111~ 펑! 끝!!"

//-----------------------------------------------------------------------------------------------

int wordGame()
{
	int score=0;
	int floor=22;
	int i=1;
	int j=1;

	Word word[100];
	char ch;
	char inputw[100];
	int inputCnt = 0;
	srand( time(0) );

	beginDisplay();
	system("cls");

	wordLoad(word);  //파일에서 단어를 읽어와 word 구조체에 저장하기 
	floorFrame();	//바닥 틀 찍어주기
	removeCursor();
	

	for(i=0; i>=0; i++)
	{
		if(kbhit())
		{
			gotoxy(32,24);
			ch = getch();
			//엔터
			if(ch == 13)
			{
				stringcheck(word,inputw,&score);
				inputCnt=0;
				inputw[0]='\0';
			}

			//백스페이스
			else if(ch == '\b')
			{
				if(inputCnt>0)
				{
					inputw[inputCnt-1]='\0';
					inputCnt--;
				}
			}
			else
			{
				inputw[inputCnt]=ch;
				inputw[inputCnt+1]='\0';
				inputCnt++;
			}
			clrscr(32,24,42,24);
			gotoxy(32,24);
			printf("%s",inputw);
			
		}

		if(i%1000==0)     //단어 생성 빈도
		{
			wordOk(word);   //단어를 랜덤으로 골라준다 
			i=1;
		}		

		if(i%350==0)  //딜레이
		{
			yPlus(word);
		}
		if(floorUp(&floor,word)==1)break;

		wordDisplay(word);	
	}

	return score;
}

//랜덤으로 단어 하나 출력하기위해 ok를 1로 변경
void wordOk(Word* w)
{
	int num;
	num=random(100)+1;  //0~99까지 랜덤으로 돌려서 랜덤값을 num변수에 저장한다

	if(w[num].ok == 0)	//아직 단어가 출력되지 않은 것들중에서
	{
		w[num].ok=1;	 //num방에 해당하는 ok에 골라졌다는 표시 ok를 1로 넣는다
		w[num].x=(random(80-(w[num].len-1))+1);	//x좌표에 랜덤으로 할당
		w[num].y=1;
	}
}

//단어가 바닥에 닿았는지 검사
int floorUp(int *floor,Word *w)
{
	int i, j;

	if(*floor==2)   //바닥값이 2 가 되면 return 1 
	{
		return 1;
	}

	for(i=0; i<100; i++) //100까지 for문으로 돌리면 
	{
		if(w[i].ok==1)  //랜덤으로 값이 들어오면 
		{
			if(w[i].y==*floor)  //y값이 바닥값하고 같으면
			{
				//잔상지우기
				gotoxy(w[i].x, w[i].y-1);
				for(j=0; j<w[i].len; j++)
				{
					printf(" ");
				}
				w[i].ok=0;  //ok를 0으로 바꾸고 
				(*floor)--;  //바닥을 감소				
				
				floorDisplay(*floor); 
			}
		}
	}

	return 0;
}

//바닥출력
void floorDisplay(int floor)
{
	textcolor(15, 0);
	gotoxy(1, floor);
	printf(FLOOR);
	
	gotoxy(1, floor+1);
	clrscr(1, floor+1, 80, floor+1);
	
	switch(floor)
	{
	case 3 : 
		textcolor(random(15)+1, 0);
		gotoxy(1,4);
		printf("%s",F4); 
		break;
	case 4: 
		textcolor(random(15)+1, 0);
		gotoxy(1,5);
		printf("%80s",F5);
		break;
	case 5 :
		textcolor(random(15)+1, 0);
		gotoxy(1,6);
		printf("%s",F6); 
		break;
	case 6:
		textcolor(random(15)+1, 0);
		gotoxy(1,7);
		printf("%80s",F7);
		break;
	case 7 : 
		textcolor(random(15)+1, 0);
		gotoxy(1,8);
		printf("%s",F8); 
		break;
	case 8: 
		textcolor(random(15)+1, 0);
		gotoxy(1,9);
		printf("%80s",F9);
		break;
	case 9 : 
		textcolor(random(15)+1, 0);
		gotoxy(1,10);
		printf("%s",F10); 
		break;
	case 10: 
		textcolor(random(15)+1, 0);
		gotoxy(1,11);
		printf("%80s",F11);
		break;
	case 11 : 
		textcolor(random(15)+1, 0);
		gotoxy(1,12);
		printf("%s",F12); 
		break;
	case 12: 
		textcolor(random(15)+1, 0);
		gotoxy(1,13);
		printf("%80s",F13);
		break;
	case 13 :
		textcolor(random(15)+1, 0);
		gotoxy(1,14);
		printf("%s",F14); 
		break;
	case 14:
		textcolor(random(15)+1, 0);
		gotoxy(1,15);
		printf("%80s",F15);
		break;
	case 15 : 
		textcolor(random(15)+1, 0);
		gotoxy(1,16);
		printf("%s",F16); 
		break;
	case 16: 
		textcolor(random(15)+1, 0);
		gotoxy(1,17);
		printf("%80s",F17);
		break;
	case 17 : 
		textcolor(random(15)+1, 0);
		gotoxy(1,18);
		printf("%s",F18); 
		break;
	case 18: 
		textcolor(random(15)+1, 0);
		gotoxy(1,19);
		printf("%80s",F19);
		break;
	case 19 : 
		textcolor(random(15)+1, 0);
		gotoxy(1,20);
		printf("%s",F20); 
		break;
	case 20 : 
		textcolor(random(15)+1, 0);
		gotoxy(1,21);
		printf("%80s",F21); 
		break;
	case 21: 
		textcolor(random(15)+1, 0);
		gotoxy(1,22);
		printf("%s",F22);
		break;
	}
	textcolor(15, 0);
	gotoxy(1, floor);
}

void floorFrame(void)
{
	gotoxy(1,22);
	printf("%s",FLOOR);
	gotoxy(60,23);
	printf("┌────────┐");
	gotoxy(60,24);
	printf("│                │");
	gotoxy(60,25);
	printf("└────────┘");
	gotoxy(62,24);
	printf("score : 0");

	//단어 입력 박스 출력 
	gotoxy(30,23);
	printf("┌────────┐");
	gotoxy(30,24);
	printf("│                │");
	gotoxy(30,25);
	printf("└────────┘");
}

//입력한 단어 화면에 출력중인 단어중에 있는지 검사
void stringcheck(Word *w, char *cp, int *score)
{
	int i,j;

	//단어 100개중에 모두검사
	for(i=0; i<100; i++)
	{
		//화면에 출력중(ok==1)이고 입력한 단어랑 일치하면
		if(w[i].ok==1 && strcmp(w[i].word, cp)==0)
		{
			//printf("%s,%s\n",w[i].word,cp);/
			gotoxy(w[i].x,w[i].y); //맞춘 단어를 지워주기 위한 커서이동
			
			for(j=0;j<w[i].len; j++)
			{
				printf(" ");
			}
			(*score)+=1; //단어 맞췄으니 점수 up!
			w[i].ok=0;

			clrscr(70,24,77,24);
			gotoxy(70,24);
			printf("%d",*score);

			break;
		}
	}
}

//100개 단어중에 ok가 1인것만 y값 1씩 증가
void yPlus(Word* w)
{
	int i;
	for(i=0; i<100; i++)
	{
		if(w[i].ok == 1)
		{
			w[i].y++;
		}
	}
}

//화면에 단어출력
void wordDisplay(Word* w)
{
	int i, j;

	//단어 100개중에 화면 출력여부(ok)가 1인것만 출력하기
	for(i=0; i<100; i++)
	{
		if(w[i].ok==1)
		{
			//잔상지우기
			gotoxy(w[i].x,w[i].y-1);
			for(j=0; j<w[i].len; j++)
			{
				printf(" ");
			}
			//단어 출력하기
			gotoxy(w[i].x,w[i].y);
			printf("%s",w[i].word);
		}
	}
}

//단어읽어오기
void wordLoad(Word* w)
{
	FILE *ifp;
	int i=0;

	ifp=fopen("C:\\data\\단어.txt","rt");
	assert(ifp!=NULL);

	while(1)
	{
		//한줄씩 읽어와서 구조체 배열에 저장하기
		//리턴값이 NULL이면 while문을 빠져나간다.
		if(fgets(w[i].word, sizeof(w[i].word), ifp)==NULL)
		{
			break;
		}
		w[i].word[strlen(w[i].word)-1]=NULL;		//마지막방에 NULL넣기
		w[i].ok = 0;							//화면 출력여부 0으로 초기화(안나옴)
		w[i].len = strlen(w[i].word);			//글자수
		i++;
	}
	fclose(ifp);
}

//초기메뉴
void beginDisplay()
{
	int i;
	system("cls");
	struct Signal S[MAX];
	//srand( time(0) );

	//ok 초기화
	for(i=0; i<MAX; i++)
	{
		S[i].ok = 0;
	}

	while(1)
	{
		if(kbhit())	break;

		if (random(5) == 0)
		{
			for (i=0;i<MAX;i++)
			{
				if (S[i].ok == 0)
				{  
					S[i].ok= 1;
					S[i].ch=random('Z'-'A'+1)+'A';
					S[i].x=random(80);
					S[i].y=0;
					S[i].distance=random(16)+9;
					S[i].nFrame=S[i].nStay=random(15)+5;
					break;
				}
			}
		}
	
		//
		for (i=0;i<MAX;i++)
		{
			if (S[i].ok == 0)
				continue;

			if (--S[i].nStay == 0)
			{
				S[i].nStay=S[i].nFrame;
				gotoxy(S[i].x,S[i].y);
				putch(' ');

				if (++S[i].y < S[i].distance)
				{
					gotoxy(S[i].x,S[i].y);
					textcolor(random(15), 0);
					putch(S[i].ch);
				}
				else
				{
					S[i].ok=0;
				}
			}
		}

		Sleep(5);

		textcolor(15, 0);
		gotoxy(10,8);
		printf("▩▩▩  ▩    ▩▩▩  ▩     ▩▩▩      ▩      ▩▩   ▩▩▩");
		gotoxy(10,9);
		printf("▩      ▩      ▩    ▩    ▩     ▩   ▩▩    ▩▩▩  ▩");
		gotoxy(10,10);
		printf("▩▩▩  ▩▩    ▩    ▩▩  ▩  ▩     ▩▩▩  ▩ ▩ ▩ ▩▩▩");
		gotoxy(10,11);
		printf("▩      ▩     ▩▩   ▩    ▩   ▩   ▩    ▩ ▩ ▩ ▩ ▩");
		gotoxy(10,12);
		printf("▩▩▩  ▩    ▩  ▩  ▩      ▩▩▩  ▩    ▩ ▩ ▩ ▩ ▩▩▩");

		gotoxy(28, 23);
		textcolor(15, 0);
		printf("Please~ press any key!");
	}
}