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
#define F22 "������~~ ��������~"
#define F21 "�� ���������� Ʋ���ٴ� ������~"
#define F20 "�������� �����̾� ������~"
#define F19 "�ܾ���� ���������� ������~ ��������^^"
#define F18 "������ �׾��!!!~"
#define F17 "�� ���� �о��~ �� �ܾ� �Է� ������~!!����~"
#define F16 "����~"
#define F15 "����~ �����~~??~"
#define F14 "����̰ڱ���?~"
#define F13 "�������� �����? ���� ����ſ�~~"
#define F12 "�Կ���!, �̷ο�!"
#define F11 "����~ ��.. �׸���.. �̸�..�� ��.. �� ... ���...��"
#define F10 "�� �´�!  �츮 �������� �������~~����"
#define F9 "���� �������� �Ǿ���..~"
#define F8 "���뿡�� ��� ġ�� ���� �� �̹� ���~"
#define F7 "ī��Ʈ �ٿ� ���ϴ���~"
#define F6 "444444~"
#define F5 "333333~"
#define F4 "222222~"
#define F3 "111111~ ��! ��!!"

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

	wordLoad(word);  //���Ͽ��� �ܾ �о�� word ����ü�� �����ϱ� 
	floorFrame();	//�ٴ� Ʋ ����ֱ�
	removeCursor();
	

	for(i=0; i>=0; i++)
	{
		if(kbhit())
		{
			gotoxy(32,24);
			ch = getch();
			//����
			if(ch == 13)
			{
				stringcheck(word,inputw,&score);
				inputCnt=0;
				inputw[0]='\0';
			}

			//�齺���̽�
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

		if(i%1000==0)     //�ܾ� ���� ��
		{
			wordOk(word);   //�ܾ �������� ����ش� 
			i=1;
		}		

		if(i%350==0)  //������
		{
			yPlus(word);
		}
		if(floorUp(&floor,word)==1)break;

		wordDisplay(word);	
	}

	return score;
}

//�������� �ܾ� �ϳ� ����ϱ����� ok�� 1�� ����
void wordOk(Word* w)
{
	int num;
	num=random(100)+1;  //0~99���� �������� ������ �������� num������ �����Ѵ�

	if(w[num].ok == 0)	//���� �ܾ ��µ��� ���� �͵��߿���
	{
		w[num].ok=1;	 //num�濡 �ش��ϴ� ok�� ������ٴ� ǥ�� ok�� 1�� �ִ´�
		w[num].x=(random(80-(w[num].len-1))+1);	//x��ǥ�� �������� �Ҵ�
		w[num].y=1;
	}
}

//�ܾ �ٴڿ� ��Ҵ��� �˻�
int floorUp(int *floor,Word *w)
{
	int i, j;

	if(*floor==2)   //�ٴڰ��� 2 �� �Ǹ� return 1 
	{
		return 1;
	}

	for(i=0; i<100; i++) //100���� for������ ������ 
	{
		if(w[i].ok==1)  //�������� ���� ������ 
		{
			if(w[i].y==*floor)  //y���� �ٴڰ��ϰ� ������
			{
				//�ܻ������
				gotoxy(w[i].x, w[i].y-1);
				for(j=0; j<w[i].len; j++)
				{
					printf(" ");
				}
				w[i].ok=0;  //ok�� 0���� �ٲٰ� 
				(*floor)--;  //�ٴ��� ����				
				
				floorDisplay(*floor); 
			}
		}
	}

	return 0;
}

//�ٴ����
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
	printf("��������������������");
	gotoxy(60,24);
	printf("��                ��");
	gotoxy(60,25);
	printf("��������������������");
	gotoxy(62,24);
	printf("score : 0");

	//�ܾ� �Է� �ڽ� ��� 
	gotoxy(30,23);
	printf("��������������������");
	gotoxy(30,24);
	printf("��                ��");
	gotoxy(30,25);
	printf("��������������������");
}

//�Է��� �ܾ� ȭ�鿡 ������� �ܾ��߿� �ִ��� �˻�
void stringcheck(Word *w, char *cp, int *score)
{
	int i,j;

	//�ܾ� 100���߿� ��ΰ˻�
	for(i=0; i<100; i++)
	{
		//ȭ�鿡 �����(ok==1)�̰� �Է��� �ܾ�� ��ġ�ϸ�
		if(w[i].ok==1 && strcmp(w[i].word, cp)==0)
		{
			//printf("%s,%s\n",w[i].word,cp);/
			gotoxy(w[i].x,w[i].y); //���� �ܾ �����ֱ� ���� Ŀ���̵�
			
			for(j=0;j<w[i].len; j++)
			{
				printf(" ");
			}
			(*score)+=1; //�ܾ� �������� ���� up!
			w[i].ok=0;

			clrscr(70,24,77,24);
			gotoxy(70,24);
			printf("%d",*score);

			break;
		}
	}
}

//100�� �ܾ��߿� ok�� 1�ΰ͸� y�� 1�� ����
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

//ȭ�鿡 �ܾ����
void wordDisplay(Word* w)
{
	int i, j;

	//�ܾ� 100���߿� ȭ�� ��¿���(ok)�� 1�ΰ͸� ����ϱ�
	for(i=0; i<100; i++)
	{
		if(w[i].ok==1)
		{
			//�ܻ������
			gotoxy(w[i].x,w[i].y-1);
			for(j=0; j<w[i].len; j++)
			{
				printf(" ");
			}
			//�ܾ� ����ϱ�
			gotoxy(w[i].x,w[i].y);
			printf("%s",w[i].word);
		}
	}
}

//�ܾ��о����
void wordLoad(Word* w)
{
	FILE *ifp;
	int i=0;

	ifp=fopen("C:\\data\\�ܾ�.txt","rt");
	assert(ifp!=NULL);

	while(1)
	{
		//���پ� �о�ͼ� ����ü �迭�� �����ϱ�
		//���ϰ��� NULL�̸� while���� ����������.
		if(fgets(w[i].word, sizeof(w[i].word), ifp)==NULL)
		{
			break;
		}
		w[i].word[strlen(w[i].word)-1]=NULL;		//�������濡 NULL�ֱ�
		w[i].ok = 0;							//ȭ�� ��¿��� 0���� �ʱ�ȭ(�ȳ���)
		w[i].len = strlen(w[i].word);			//���ڼ�
		i++;
	}
	fclose(ifp);
}

//�ʱ�޴�
void beginDisplay()
{
	int i;
	system("cls");
	struct Signal S[MAX];
	//srand( time(0) );

	//ok �ʱ�ȭ
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
		printf("�̢̢�  ��    �̢̢�  ��     �̢̢�      ��      �̢�   �̢̢�");
		gotoxy(10,9);
		printf("��      ��      ��    ��    ��     ��   �̢�    �̢̢�  ��");
		gotoxy(10,10);
		printf("�̢̢�  �̢�    ��    �̢�  ��  ��     �̢̢�  �� �� �� �̢̢�");
		gotoxy(10,11);
		printf("��      ��     �̢�   ��    ��   ��   ��    �� �� �� �� ��");
		gotoxy(10,12);
		printf("�̢̢�  ��    ��  ��  ��      �̢̢�  ��    �� �� �� �� �̢̢�");

		gotoxy(28, 23);
		textcolor(15, 0);
		printf("Please~ press any key!");
	}
}