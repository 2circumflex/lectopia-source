#include "Turbo.h"



#define MAX 100
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27



struct Signal
{

	BOOL exist;                // ��ȣ�� ���� ����
	char ch;                 // ����� ����
	int x,y;                   // ���� ��ǥ
	int distance;           // �̵��� �Ÿ�
	int nFrame;                 // �ӵ�
	int nStay;               // �ӵ��� ���� ī��Ʈ
};

Signal S[MAX];



void main()
{

	int i;
	int ch;
	int freq=15;
	int frame=200;


	system("cls");
	gotoxy(0,23);

	printf("��Ʈ���� �䳻����. ����:�ӵ� ����, �¿�:�� ����, ESC:����");

	//randomize();   //���� �ʱ�ȭ. 

	while(1) {  //���ѷ��� 

		gotoxy(60,23);

		printf("�ӵ�:%d, ��:%d    ",frame,freq);



		// Ű �Է� ó��

		if (kbhit()) {

			ch=getch();

			if (ch == 0xE0) {

				ch=getch();

				switch (ch) {

				case UP:

					frame=min(frame+10,1000);  //frame+10�� 1000���� ������ frame+10.

					break;

				case DOWN:

					frame=max(frame-10,10);  //frame-10��10���� ũ�� frame-10 

					break;

				case RIGHT:

					freq=max(freq-1,1);  //freq-1�� 1���� ũ�� freq-1

					break;

				case LEFT:

					freq=min(freq+1,30); //freq+1�� 30���� ������ freq+1

					break;

				}

			} else {
				if (ch == ESC) {  //ESC�Է½� ����

					return;

				}
			}
		}

		// ���ο� ��ȣ ����

		if (random(freq) == 0) {    //random�� 0~freq��ŭ �������� 0�̸� 

			for (i=0;i<MAX;i++) {  //Max��100

				if (S[i].exist == FALSE) {  //�ܾ� 
					S[i].exist=TRUE;
					S[i].ch=random('Z'-'A'+1)+'A';
					S[i].x=random(80);
					S[i].y=0;
					S[i].distance=random(14)+9;
					S[i].nFrame=S[i].nStay=random(15)+5;
					break;

				}
			}
		}

		// �ֱⰡ �� �� ��ȣ �̵� �� ���� ó��

		for (i=0;i<MAX;i++) {
			if (S[i].exist == FALSE)
				continue;

			if (--S[i].nStay == 0) {
				S[i].nStay=S[i].nFrame;
				gotoxy(S[i].x,S[i].y);putch(' ');

				if (++S[i].y < S[i].distance) {
					gotoxy(S[i].x,S[i].y);putch(S[i].ch);
				} else {
					S[i].exist=FALSE;
				}
			}
		}



		delay(1000/frame);
	}

}

