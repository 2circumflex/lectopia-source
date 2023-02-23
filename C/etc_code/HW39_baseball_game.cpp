	/*디아도 아닌데 나이트메어 모드로 하는 HW 39*/
	/*숭실대학교 C 특강 작성자 : 김두현 aka 김흑인 */
	/*1차 목표 내가 하는 야구 게임 16:30분 시작  17:50분 종료*/
	/*2차 목표 인공지능의 구현 17:50분 시작 */
	/*3차 목표 단계별 인공지능의 구현(3단계 예정) 09:10분 종료*/


#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

void myFlush(){
	while(getchar()!='\n')
	{;}
}
void gotoxy(int x, int y) ;	//gotoxy 함수
void four_input(int *input);	//4개의 임의의 정수(0~9)까지의 입력
void user_input(int *input,int counter);	//사용자가 4개의 정수를 입력받음
int Baseball_count(int *goal,int *input);	//입력 받은 것 판별하는 함수
void com_input(int *input,int *combrain,int counter,int *goal,int level,int *end);// 컴퓨터 입력 함수
int count_brain(int *goal,int *input,int *combrain);	//컴퓨터 두뇌
int level_input();	//레벨 받기

int main(void){

	int goal[4];	//정답
	int input[4];	//내가 입력하는 값,컴퓨터가 입력하는 값 둘 다
	int counter=1;	//회차를 입력
	int level,end=0;		//레벨 변수, end는 끝내는 변수
	/* 인공지능용 입력 변수들*/
	int combrain[10]={};	//0~9까지 몇번을 맞추었는지...-1은 그 수 제외

		//랜덤 준비
	/* 시작 화면 */
	gotoxy(30,12);
	printf("지금부터 야구 게임을 시작합니다. \n");
	gotoxy(25,14);
	system("pause");
	system("cls");
	level=level_input();
	/* 시작 화면 종료 되고 본격적인 게임 시작*/
	four_input(goal);	//난수 생성이 완료
	gotoxy(35,1);
	printf("PLAY BALL! Good Luck!\n\n");
	printf("답 : %d %d %d %d\n",goal[0],goal[1],goal[2],goal[3]);
	while(1){
	srand(time(NULL));		//매번 시간값을 새로 받아 와야함
	user_input(input,counter);	//사용자가 4자리를 입력받는 그 순간!
	if(Baseball_count(goal,input)==1){	//맞췄으면!
		system("cls");
		gotoxy(10,12);
		printf("사용자 분이 %d 번째 만에 정답인 %d %d %d %d를 맞추셨습니다.짝짝!!\n",counter,goal[0],goal[1],goal[2],goal[3]);
		break;
	}
	com_input(input,combrain,counter,goal,level,&end);
	printf("#컴퓨터 %d차 : %d %d %d %d",counter,input[0],input[1],input[2],input[3]);
	if(count_brain(goal,input,combrain)==1){	//맞췄으면!
		system("cls");
		gotoxy(10,12);
		printf("컴퓨터가 %d 번째 만에 정답인 %d %d %d %d를 맞췄습니다.ㅠㅠ\n",counter,goal[0],goal[1],goal[2],goal[3]);
		break;
	}
	
	if(end>=4+level/3){		//컴퓨터가 바보 되는것을 피함... 정말 혹시나 하는 마음에
		system("cls");
		gotoxy(10,12);
		printf("컴퓨터가 %d 번째 만에 정답인 %d %d %d %d를 맞췄습니다.ㅠㅠ\n",counter,goal[0],goal[1],goal[2],goal[3]);
		break;
	}

	counter++;	//회차 1 증가
	}
	system("pause");
}


/*goto xy;*/
void gotoxy(int x, int y) 
{ 
COORD Pos = {x - 1, y - 1}; 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
} 
/* 4개의 0~9까지의 정수를 입력받음, 중복 안됨*/
void four_input(int *input){

	int count=0,i;	//i를 1으로 초기화

	while(1){
		input[count]=rand()%10;
		for(i=0;i<count;i++){	//처음부터 자기 자신까지 검사
			if(input[i]==input[count]){	//중복된 수를 만들었다면
				count--;		//카운트를 하나 뺌 
				break;		//계속 도는 의미가 없음
			}
		}/*for문 종료*/
		count++;	//잘 들어갔다는 가정하에 1 더함, 어자피 중복이면  count가 -- 되므로 다시 값을 받을 수 있음
		if(count==4){	//4개 다 잘 받았으면 종료
		return;	
		}
	}

}
/* 사용자가 4개의 정수를 입력받는 함수*/
void user_input(int *input,int counter){
	int i;
	printf("#사용자 %d차 : ",counter);
	for(i=0;i<7;i++){
	if(i%2==0){//띄어쓰기는 받으면 안되니까
		input[i/2]=getche()-48;	 
	}
	else{		//띄어쓰기는 받아서 저 어디 휴지통으로
		getche();
	}
	}
}

/* StrikeorBall 판별 1을 리턴하면 맞춘거임*/
int Baseball_count(int *goal,int *input){

	int strike=0, ball=0,i,j;	//스트라이크 볼 for문 변수 2개
	
	//스트라이크 볼 검사부
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(goal[i]==input[j]){	//같은 숫자가 있을 때!
				if(i==j){		//같은 위치에 있으면
					strike++;	//스트라이크 1 증가
				}
				else{
					ball++;	//볼 증가
				}
			break;	//그렇게 되면 더이상 검사 불필요 i로 돌아감
			}
		}
	}
	//출력부
	if(strike==4){	//다 맞췄으면
		printf("   OK!!!\n");
		return 1;
	}

	else if(strike==0&&ball==0){	//하나도 맞춘게 없으면
		printf("   NO!\n");	
	}
	else if(strike==0){	//스트라이크만 0이면 
		printf("   %dB\n",ball);
	}
	else if(ball==0){   //볼이 0이면
		printf("   %dS\n",strike);
	}
	else{		//스트라이크 볼 둘다 있음
		printf("   %dS %dB\n",strike,ball);
	}
	return 0;
}

/*지금부터 컴퓨터의 알고리즘을 시작합니다*/

void com_input(int *input,int *combrain,int counter,int *goal,int level,int *end){
	int i,j;
	int count=0;	//
	int strike=0;	//스트라이크
	for(i=0;i<4;i++){	//시작 전에 전부 -1로 초기화
		input[i]=-1;
	}

	for(i=0;i<10;i++){
		if(combrain[i]>=level){	//인공지능이 level 이상이면
			for(j=0;j<4;j++){	//그 값이 어느 위치인지 파악해
				if(i==goal[j]){	//그 위치를 잡으면
					strike++;		//스트라이크 1 증가
					input[j]=goal[j];	//그 위치에 j를 입력
					break;			//그뒤로는 의미 없음
				}
			}
		}
	}
	if(strike==3){
		(*end)+=1;		//끝내는 변수 1증가
	}


		for(i=0;i<4;i++){	//입력을 4개 받음

			if(input[i]!=-1){		//이미 답을 알고 있는 부분이면
				continue;		//아무것도 안하면 다음 숫자	
			}
			//여기까지 알고 있는 부분 검사
			input[i]=rand()%10;	//알고 있는 게 아니라면 값을 받아야 겟징?

			for(j=0;j<4;j++){
			if(input[i]==input[j]&&i!=j){	//중복된 수를 만들었다면,그리고 그것이 같은 위치가 아니라면
				input[i]=-1;
				i--;		//카운트를 하나 뺌 
				break;		//계속 도는 의미가 없음
			}
			else if(combrain[input[count]]==-1){	//받은 것이 이미 제외된 숫자이면
				i--;		//카운트를 하나 뺌
				break;
			}
			}
		}/*for문 종료&& 선언 다 받았지롱*/

}
/*컴퓨터 알고리즘 그 두 번째, 숫자를 어느 정도나 알고 있는지 테스트*/
int count_brain(int *goal,int *input,int *combrain){

	int strike=0, ball=0,i,j;	//스트라이크 볼 for문 변수 2개
	
	//스트라이크 볼 검사부
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(goal[i]==input[j]){	//같은 숫자가 있을 때!
				if(i==j){		//같은 위치에 있으면
					strike++;	//스트라이크 1 증가
					combrain[goal[i]]+=2;	//인공지능 2 증가
					
				}
				else{
					ball++;	//볼 증가
					combrain[goal[i]]+=1;	//볼이면 1
				}
			break;	//그렇게 되면 더이상 검사 불필요 i로 돌아감
			}
		}
	}

	//출력부
	if(strike==4){	//다 맞췄으면
		printf("   OK!!!\n");
		return 1;
	}

	else if(strike==0&&ball==0){	//하나도 맞춘게 없으면
		printf("   NO!\n");	
	}
	else if(strike==0){	//스트라이크만 0이면 
		printf("   %dB\n",ball);
	}
	else if(ball==0){   //볼이 0이면
		printf("   %dS\n",strike);
	}
	else{		//스트라이크 볼 둘다 있음
		printf("   %dS %dB\n",strike,ball);
	}
	return 0;
}

int level_input(){
	int num;
	while(1){
	
	gotoxy(30,12);
	printf("난이도는 1~6까지 선택 가능하십니다.");
	gotoxy(32,14);
	printf("1이 가장 어렵고 6은 아기입니다.");
	gotoxy(35,16);
	printf("난이도를 입력해 주세요 : ");
	num=getche()-48;		//난이도 입력받음
	if(num>=1&&num<=6){		//정상 난이도
		system("cls");
		return num;
	}
	system("cls");
	gotoxy(35,8);
	printf("잘못 입력 하셧습니다.\n");
	}

}