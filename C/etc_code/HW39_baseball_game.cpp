	/*��Ƶ� �ƴѵ� ����Ʈ�޾� ���� �ϴ� HW 39*/
	/*���Ǵ��б� C Ư�� �ۼ��� : ����� aka ������ */
	/*1�� ��ǥ ���� �ϴ� �߱� ���� 16:30�� ����  17:50�� ����*/
	/*2�� ��ǥ �ΰ������� ���� 17:50�� ���� */
	/*3�� ��ǥ �ܰ躰 �ΰ������� ����(3�ܰ� ����) 09:10�� ����*/


#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

void myFlush(){
	while(getchar()!='\n')
	{;}
}
void gotoxy(int x, int y) ;	//gotoxy �Լ�
void four_input(int *input);	//4���� ������ ����(0~9)������ �Է�
void user_input(int *input,int counter);	//����ڰ� 4���� ������ �Է¹���
int Baseball_count(int *goal,int *input);	//�Է� ���� �� �Ǻ��ϴ� �Լ�
void com_input(int *input,int *combrain,int counter,int *goal,int level,int *end);// ��ǻ�� �Է� �Լ�
int count_brain(int *goal,int *input,int *combrain);	//��ǻ�� �γ�
int level_input();	//���� �ޱ�

int main(void){

	int goal[4];	//����
	int input[4];	//���� �Է��ϴ� ��,��ǻ�Ͱ� �Է��ϴ� �� �� ��
	int counter=1;	//ȸ���� �Է�
	int level,end=0;		//���� ����, end�� ������ ����
	/* �ΰ����ɿ� �Է� ������*/
	int combrain[10]={};	//0~9���� ����� ���߾�����...-1�� �� �� ����

		//���� �غ�
	/* ���� ȭ�� */
	gotoxy(30,12);
	printf("���ݺ��� �߱� ������ �����մϴ�. \n");
	gotoxy(25,14);
	system("pause");
	system("cls");
	level=level_input();
	/* ���� ȭ�� ���� �ǰ� �������� ���� ����*/
	four_input(goal);	//���� ������ �Ϸ�
	gotoxy(35,1);
	printf("PLAY BALL! Good Luck!\n\n");
	printf("�� : %d %d %d %d\n",goal[0],goal[1],goal[2],goal[3]);
	while(1){
	srand(time(NULL));		//�Ź� �ð����� ���� �޾� �;���
	user_input(input,counter);	//����ڰ� 4�ڸ��� �Է¹޴� �� ����!
	if(Baseball_count(goal,input)==1){	//��������!
		system("cls");
		gotoxy(10,12);
		printf("����� ���� %d ��° ���� ������ %d %d %d %d�� ���߼̽��ϴ�.¦¦!!\n",counter,goal[0],goal[1],goal[2],goal[3]);
		break;
	}
	com_input(input,combrain,counter,goal,level,&end);
	printf("#��ǻ�� %d�� : %d %d %d %d",counter,input[0],input[1],input[2],input[3]);
	if(count_brain(goal,input,combrain)==1){	//��������!
		system("cls");
		gotoxy(10,12);
		printf("��ǻ�Ͱ� %d ��° ���� ������ %d %d %d %d�� ������ϴ�.�Ф�\n",counter,goal[0],goal[1],goal[2],goal[3]);
		break;
	}
	
	if(end>=4+level/3){		//��ǻ�Ͱ� �ٺ� �Ǵ°��� ����... ���� Ȥ�ó� �ϴ� ������
		system("cls");
		gotoxy(10,12);
		printf("��ǻ�Ͱ� %d ��° ���� ������ %d %d %d %d�� ������ϴ�.�Ф�\n",counter,goal[0],goal[1],goal[2],goal[3]);
		break;
	}

	counter++;	//ȸ�� 1 ����
	}
	system("pause");
}


/*goto xy;*/
void gotoxy(int x, int y) 
{ 
COORD Pos = {x - 1, y - 1}; 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
} 
/* 4���� 0~9������ ������ �Է¹���, �ߺ� �ȵ�*/
void four_input(int *input){

	int count=0,i;	//i�� 1���� �ʱ�ȭ

	while(1){
		input[count]=rand()%10;
		for(i=0;i<count;i++){	//ó������ �ڱ� �ڽű��� �˻�
			if(input[i]==input[count]){	//�ߺ��� ���� ������ٸ�
				count--;		//ī��Ʈ�� �ϳ� �� 
				break;		//��� ���� �ǹ̰� ����
			}
		}/*for�� ����*/
		count++;	//�� ���ٴ� �����Ͽ� 1 ����, ������ �ߺ��̸�  count�� -- �ǹǷ� �ٽ� ���� ���� �� ����
		if(count==4){	//4�� �� �� �޾����� ����
		return;	
		}
	}

}
/* ����ڰ� 4���� ������ �Է¹޴� �Լ�*/
void user_input(int *input,int counter){
	int i;
	printf("#����� %d�� : ",counter);
	for(i=0;i<7;i++){
	if(i%2==0){//����� ������ �ȵǴϱ�
		input[i/2]=getche()-48;	 
	}
	else{		//����� �޾Ƽ� �� ��� ����������
		getche();
	}
	}
}

/* StrikeorBall �Ǻ� 1�� �����ϸ� �������*/
int Baseball_count(int *goal,int *input){

	int strike=0, ball=0,i,j;	//��Ʈ����ũ �� for�� ���� 2��
	
	//��Ʈ����ũ �� �˻��
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(goal[i]==input[j]){	//���� ���ڰ� ���� ��!
				if(i==j){		//���� ��ġ�� ������
					strike++;	//��Ʈ����ũ 1 ����
				}
				else{
					ball++;	//�� ����
				}
			break;	//�׷��� �Ǹ� ���̻� �˻� ���ʿ� i�� ���ư�
			}
		}
	}
	//��º�
	if(strike==4){	//�� ��������
		printf("   OK!!!\n");
		return 1;
	}

	else if(strike==0&&ball==0){	//�ϳ��� ����� ������
		printf("   NO!\n");	
	}
	else if(strike==0){	//��Ʈ����ũ�� 0�̸� 
		printf("   %dB\n",ball);
	}
	else if(ball==0){   //���� 0�̸�
		printf("   %dS\n",strike);
	}
	else{		//��Ʈ����ũ �� �Ѵ� ����
		printf("   %dS %dB\n",strike,ball);
	}
	return 0;
}

/*���ݺ��� ��ǻ���� �˰����� �����մϴ�*/

void com_input(int *input,int *combrain,int counter,int *goal,int level,int *end){
	int i,j;
	int count=0;	//
	int strike=0;	//��Ʈ����ũ
	for(i=0;i<4;i++){	//���� ���� ���� -1�� �ʱ�ȭ
		input[i]=-1;
	}

	for(i=0;i<10;i++){
		if(combrain[i]>=level){	//�ΰ������� level �̻��̸�
			for(j=0;j<4;j++){	//�� ���� ��� ��ġ���� �ľ���
				if(i==goal[j]){	//�� ��ġ�� ������
					strike++;		//��Ʈ����ũ 1 ����
					input[j]=goal[j];	//�� ��ġ�� j�� �Է�
					break;			//�׵ڷδ� �ǹ� ����
				}
			}
		}
	}
	if(strike==3){
		(*end)+=1;		//������ ���� 1����
	}


		for(i=0;i<4;i++){	//�Է��� 4�� ����

			if(input[i]!=-1){		//�̹� ���� �˰� �ִ� �κ��̸�
				continue;		//�ƹ��͵� ���ϸ� ���� ����	
			}
			//������� �˰� �ִ� �κ� �˻�
			input[i]=rand()%10;	//�˰� �ִ� �� �ƴ϶�� ���� �޾ƾ� ��¡?

			for(j=0;j<4;j++){
			if(input[i]==input[j]&&i!=j){	//�ߺ��� ���� ������ٸ�,�׸��� �װ��� ���� ��ġ�� �ƴ϶��
				input[i]=-1;
				i--;		//ī��Ʈ�� �ϳ� �� 
				break;		//��� ���� �ǹ̰� ����
			}
			else if(combrain[input[count]]==-1){	//���� ���� �̹� ���ܵ� �����̸�
				i--;		//ī��Ʈ�� �ϳ� ��
				break;
			}
			}
		}/*for�� ����&& ���� �� �޾�����*/

}
/*��ǻ�� �˰��� �� �� ��°, ���ڸ� ��� ������ �˰� �ִ��� �׽�Ʈ*/
int count_brain(int *goal,int *input,int *combrain){

	int strike=0, ball=0,i,j;	//��Ʈ����ũ �� for�� ���� 2��
	
	//��Ʈ����ũ �� �˻��
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(goal[i]==input[j]){	//���� ���ڰ� ���� ��!
				if(i==j){		//���� ��ġ�� ������
					strike++;	//��Ʈ����ũ 1 ����
					combrain[goal[i]]+=2;	//�ΰ����� 2 ����
					
				}
				else{
					ball++;	//�� ����
					combrain[goal[i]]+=1;	//���̸� 1
				}
			break;	//�׷��� �Ǹ� ���̻� �˻� ���ʿ� i�� ���ư�
			}
		}
	}

	//��º�
	if(strike==4){	//�� ��������
		printf("   OK!!!\n");
		return 1;
	}

	else if(strike==0&&ball==0){	//�ϳ��� ����� ������
		printf("   NO!\n");	
	}
	else if(strike==0){	//��Ʈ����ũ�� 0�̸� 
		printf("   %dB\n",ball);
	}
	else if(ball==0){   //���� 0�̸�
		printf("   %dS\n",strike);
	}
	else{		//��Ʈ����ũ �� �Ѵ� ����
		printf("   %dS %dB\n",strike,ball);
	}
	return 0;
}

int level_input(){
	int num;
	while(1){
	
	gotoxy(30,12);
	printf("���̵��� 1~6���� ���� �����Ͻʴϴ�.");
	gotoxy(32,14);
	printf("1�� ���� ��ư� 6�� �Ʊ��Դϴ�.");
	gotoxy(35,16);
	printf("���̵��� �Է��� �ּ��� : ");
	num=getche()-48;		//���̵� �Է¹���
	if(num>=1&&num<=6){		//���� ���̵�
		system("cls");
		return num;
	}
	system("cls");
	gotoxy(35,8);
	printf("�߸� �Է� �ϼ˽��ϴ�.\n");
	}

}