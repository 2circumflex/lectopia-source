/* 편의점프로그램 */
/* 김지수, 이로운 */

#pragma warning(disable:4996)
#pragma warning(disable:4244)
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>


//color상수
#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 


//편의점 구조체
struct gs
{
	char item[20];
	int amount;
	int sale_amount;
	int stocked_price;
	int con_price;
};

//초기메뉴에서 날짜랑 돈입금
struct intro
{
	int day;
	int proper;
};

//포인트 구조체
struct point
{
	int number;
	int allpoint;
};

//수익 구조체
struct profit
{	
	int allpro;
	int netpro;
};


void init(struct gs *, int);
void stock(struct gs *, int, int *);
void textcolor(int, int);
void margin(struct gs *, int, struct profit);
void gs25_save(struct gs *, int);
void save(int, int, int);
/*--------------------------------------------------------*/
int menu();
int propert(struct intro *ap);
void stocked(struct intro *ap,struct gs *gs25,int size);
void init(struct gs *gs25, int size);
void sale(struct gs *gs25, struct point *poin,struct profit *pro,struct intro *ap);


//메인!!!!!
int main()
{
	struct point poin[9];
	struct profit pro;
	struct gs gs25[10];
	int size  = sizeof(gs25)/sizeof(gs25[0]);

	init(gs25, size);
	struct intro ap;
	int num;
	int esc;

	while(1)
	{
		esc = propert(&ap);
		if(esc == 0)
		{
			break;
		}
		while(1)
		{
			num = menu();
			if(num == 5)
			{
				system("cls");
				break;
			}

			switch(num)
			{
			case 1 : stocked(&ap,gs25, size); gs25_save(gs25, size); break;
			case 2 : sale(gs25,poin,&pro,&ap); gs25_save(gs25, size);break;
			case 3 : stock(gs25, size, &(ap.proper)); gs25_save(gs25, size);break;
			case 4 : margin(gs25, size, pro); break;
			}		
		}
	}

}

/*
profit.txt업데이트
*/
void save(int day, int allpay, int netpay)
{
	int tday, c_tot, s_tot;
	FILE * fp1, *fp2;

	fp1 = fopen("profit.txt", "rt");
	fp2 = fopen("temp.txt", "wt");

	while(!feof(fp1))
	{
		fscanf(fp1, "%d %d %d", &tday, &c_tot, &s_tot);
		if(tday == day)
		{
			c_tot += allpay;
			s_tot += netpay;
		}
		fprintf(fp2, "%d %d %d", tday, c_tot, s_tot);
	}
	fclose(fp1);
	fclose(fp2);

	system("ren temp.txt profit.txt");
}

/*
gs25.txt업데이트
*/
void gs25_save(struct gs * gs25, int size)
{
	int i;
	FILE * fp;

	fp = fopen("gs25.txt", "wt");
	
	for(i=0; i<size; i++)
	{
		fprintf(fp, "%s %d %d\n", gs25[i].item, gs25[i].amount, gs25[i].sale_amount);
	}
	fclose(fp);
}

/*
판매수익
품목별 판매개수 총수익 순수익
전체 총수익
전체 순수익
조회할 날짜를 입력해서 날짜별 총수익 순수익을 나타낸다
*/
void margin(struct gs * gs25, int size, struct profit pro)
{	
	int i, c_item, s_item, c_tot=0, s_tot=0;
	char day[10], pday[10];
	FILE * fp;

	system("cls");
		
	printf("   [품목]  [판매개수]  [총수익]  [순수익]\n");
	for(i=0; i<size; i++)
	{
		c_item = 0, s_item = 0;

		c_item = gs25[i].sale_amount * gs25[i].con_price;
		s_item = gs25[i].sale_amount * gs25[i].stocked_price;
		printf("%10s%10d%10d%10d\n", gs25[i].item, gs25[i].sale_amount, c_item, c_item - s_item);

		c_tot += c_item;
		s_tot += s_item;		
	}
	printf("---------------------------------------\n");
	printf("전체 수익 : %d\n", c_tot);
	printf("전체 순수익 : %d\n", c_tot - s_tot);
	
	//날짜별 전체 수익, 전체 순수익 조회
	while(1)
	{
		fflush(stdin);
		printf("조회할 날짜를 입력하세요(YYYYMMDD) : ");
		scanf("%s", day);
	
		if(strcmp(day, "end") == 0)
		{
			printf("종료합니다, 아무키나 누르면 메뉴로 돌아갑니다\n");			
			getch();
			return;
		}
		else
		{
			fp = fopen("profit.txt", "rt");
			
			fflush(stdin);
			while(!feof(fp))
			{
				fscanf(fp, "%s %d %d", pday, &(pro.allpro), &(pro.netpro));
				if(strcmp(day, pday)==0)
				{
					printf("%.4s년 %s월 %s일의 총수익은 %d원이고 순수익은 %d원입니다.\n", day, day[4]+day[5], day[6]+day[7], pro.allpro, pro.netpro);
					fclose(fp);
					break;
				}
			}			
		}		
	}	
}

/*
편의점구조체 초기화
물품명, 입고가, 소비자가 초기화
gs25.txt 파일이 없으면 수량, 판매수량은 0으로
있으면 텍스트파일에서 읽어온다
*/
void init(struct gs * gs25, int size)
{
	int i;
	char str[10][20] = {"새우깡", "감자깡", "양파링", "치토스", "프링글스", "콜라", "사이다", "설레임", "커피", "우유"};
	int pay[10] = {500, 600, 700, 700, 1500, 800, 800, 1000, 1200, 1000};

	FILE * fp = fopen("gs25.txt", "rt");

	
	if(fp==NULL)
	{
		fp = fopen("gs25.txt", "wt");
		for(i=0; i<size; i++)
		{
			strcpy(gs25[i].item, *(str+i));
			gs25[i].amount = 0;
			gs25[i].sale_amount = 0;
			gs25[i].stocked_price = pay[i];
			gs25[i].con_price = pay[i] * 1.5;
			fprintf(fp, "%s %d %d\n", gs25[i].item, gs25[i].amount, gs25[i].sale_amount);
		}
		fclose(fp);
	}	
	else
	{
		struct gs temp;
		fp = fopen("gs25.txt", "rt");
				
		for(i=0; i<size; i++)
		{
			fscanf(fp, "%s %d %d", temp.item, &(temp.amount), &(temp.sale_amount));

			strcpy(gs25[i].item, *(str+i));
			gs25[i].amount = 0;
			gs25[i].sale_amount = 0;
			gs25[i].stocked_price = pay[i];
			gs25[i].con_price = pay[i] * 1.5;

			if((strcmp(gs25[i].item, temp.item))==0)
			{
				gs25[i].amount = temp.amount;
				gs25[i].sale_amount = temp.sale_amount;
			}
		}
		
		fclose(fp);
	}		
}

/*
품목
품목별로 개수 나타내고 5개미만은 표시
반품 및 수정가능
*/
void stock(struct gs * gs25, int size, int * proper)
{	
	int i, num, su;
	char item[20];
	system("cls");
	
	//아래는 반품 및 수량수정
	while(1)
	{
		printf("-------------------------\n");
		printf("  [물품명]\t  [수량]\n");

		for(i=0; i<size; i++)
		{
			if(gs25[i].amount < 5)	textcolor(LIGHTRED, BLACK);
			else if(gs25[i].amount >= 5) textcolor(LIGHTGRAY, BLACK);
			printf("%10s       %5d개\n", gs25[i].item, gs25[i].amount);
		}
		textcolor(LIGHTGRAY, BLACK);
		printf("-------------------------\n");		

		fflush(stdin);
		printf("메뉴를 선택하세요(반품:1, 수정:2, 종료:0) : ");
		scanf("%d", &num);

		//0입력하면 종료
		if(num==0)
		{
			printf("종료합니다, 아무키나 누르면 메뉴로 돌아갑니다\n");
			getch();
			return;
		}
				
		if(num == 1 || num == 2)
		{
			//반품
			if(num == 1)
			{
				fflush(stdin);
				printf("반품할 물품을 입력하세요 : ");
				scanf("%s", item);
					
				for(i=0; i<size; i++)
				{
					if(strcmp(item, gs25[i].item)==0)
					{
						while(1)
						{
							fflush(stdin);
							printf("반품할 개수를 입력하세요 : ");
							scanf("%d", &su);

							if(su>0 && gs25[i].amount>=su)
							{
								gs25[i].amount -= su;
								*proper += gs25[i].stocked_price * su;
								printf("%s물품이 %d개 반품되었습니다\n", gs25[i].item, su);
								break;
							}
							else
							{
								printf("*잘못입력했습니다\n");
							}
						}
					}
				}				
			}
			//수정
			else if(num == 2)
			{
				
				fflush(stdin);
				printf("수정할 물품을 입력하세요 : ");
				scanf("%s", item);

				for(i=0; i<size; i++)
				{
					if(strcmp(item, gs25[i].item)==0)
					{
						while(1)
						{
							fflush(stdin);
							printf("수정될 갯수를 입력해주세요 : ");
							scanf("%d", &su);

							if(su>=0)
							{
								gs25[i].amount = su;
									
								printf("%s물품이 %d개로 수정되었습니다\n", gs25[i].item, su);
								break;
							}
							else
							{						
								printf("*잘못입력했습니다\n");						
							}
						}
					}
				}				
			}
		}
		else
		{
			printf("*잘못입력했습니다\n");
		}
	}
}

/*
텍스트칼라
재고에서 5개미만인 품목 나타내기 위해 사용
*/
void textcolor(int foreground, int background) 
{ 
	int color=foreground+background*16; 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}


/*--------------------------------------------------------------------------------------*/


//입고 함수
void stocked(struct intro *ap,struct gs *gs25,int size)
{
	int i,j;
	char name[20];
	int amount;//입고할 수량
	char yn;//한번더 묻는 변수
	FILE *fp = fopen("gs25.txt", "rt");
	system("cls");
	if(fp==NULL)
	{
		printf("파일이 존재하지 않습니다");
	}
	else
	{
		printf("[품목명]   [입고가]\n");
		for(i=0; i<10; i++)
		{			
			printf("%3s %5d원\n",gs25[i].item,gs25[i].stocked_price);
		}
		getch();

		while(1)
		{
			fflush(stdin);
			printf("입고하고자 하는 품목명을 입력하세요 :");
			scanf("%s",name);
			if(strcmp(name,"end")==0)
			{
				/*for(i=0; i<10; i++)
		        {
			         printf("품목명    개수\n");
			         printf("%3s %5d\n",gs25[i].item,gs25[i].amount);
		        }
				printf("%d",ap->proper);*/
				getch();
				return;
			}
			for(j=0; j<=10; j++)
			{
				if(j==10)
				{
					printf("해당하는 이름의 품목이 없습니다\n");
					break;
				}
				if(strcmp(name,gs25[j].item)==0)
				{
					printf("입고할 개수를 입력하세요 :");
					scanf("%d",&amount);
					fflush(stdin);
					printf("입고하시겠습니까? (y/n)");
					scanf("%c",&yn);
					if(yn=='y' || yn=='Y')
					{
						printf("입고하였습니다 \n");
						(gs25[j].amount)+=amount;
						ap->proper-=(gs25[j].stocked_price)*amount;
						break; 
					}
					else
					{
						printf("취소되었습니다\n");
						break;
					}
				}
			}
		}
	}
}

//초기메뉴
int propert(struct intro *ap)
{
	char name[10];
	FILE *fp=fopen("profit.txt","at");
	printf("[편 의 점 프 로 그 램]\n");
	while(1)
	{
		printf("end를 입력하면 종료합니다\n");
		printf("판매자 명을 입력하세요 :");
		scanf("%s",&name);
		if(strcmp(name,"end")==0)
		{
			return 0;
		}
		if(strcmp(name,"이로운")==0)
		{
			printf("날짜를 입력하세요 :");
			scanf("%d",&(ap->day));
			fprintf(fp,"%d",ap->day);
			printf("금액을 입력하세요 :");
			scanf("%d",&(ap->proper));
			break;
		}
		else
		{
			printf("이름이 잘못 입력 되었습니다.\n");
		}
	}
	fclose(fp);
	return 1;
}
//메뉴
int menu()
{
	int num;
	system("cls");
	printf("1. 입고\n");
	printf("2. 판매\n");
	printf("3. 재고\n");
	printf("4. 판매수익\n");
	printf("5. 초기메뉴\n");
	printf("메뉴를 입력하세요 :");
	fflush(stdin);
	scanf("%d",&num);
	return num;
}

//판매
void sale(struct gs *gs25, struct point *poin,struct profit *pro,struct intro *ap)
{
	int i,j;
	char name[20];//입력받은 물품명을 저장할 배열
	int amount;//수량을 입력받았을때 저장할 변수
	int num;//회원 번호를 입력받을 변수
	char yn;//y/n의 데이터를 저장하기 위한 변수
	int res;//결과적으로 지불해야할 돈이 저장된 변수
	int pay;//지불한 금액을 저장할 변수

	system("cls");
	printf(" [품목명]   [개수]    판매가\n");
	for(i=0; i<10; i++)
    {	     
		 printf("%5s %5d %10d\n",gs25[i].item,gs25[i].amount,gs25[i].con_price);
	}

	FILE *fp = fopen("point.txt","rt");
	if(fp==NULL)
	{
		printf("파일이 존재하지 않습니다\n");
	}
	else
	{
	for(i=0; i<9; i++)
	{
		fscanf(fp,"%d %d",&(poin[i].number),&(poin[i].allpoint));
		printf("%d %d",poin[i].number, poin[i].allpoint);
	}
	}
	fclose(fp);
	/*for(i=0; i<9; i++)
	{
		printf("%d %d",poin[i].number, poin[i].allpoint);
	}*/
	while(1)
	{
		printf("구입할 물품명을 입력하세요 :");
	    scanf("%s",name);
	    if(strcmp(name,"end")==0)
		{
			fp=fopen("point.txt","wt");
			for(i=0; i<9; i++)
			{
				fprintf(fp,"%d %d",&(poin[i].number), &(poin[i].allpoint));
			}
			fclose(fp);
			return;
		}
		for(j=0; j<=10; j++)
			{
				if(j==10)
				{
					printf("해당하는 이름의 품목이 없습니다\n");
					break;
				}
				if(strcmp(name,gs25[j].item)==0)
				{
					printf("구매할 물품의 수량을 입력하세요 :");
					scanf("%d",&amount);
					if(amount>gs25[j].amount)
					{
						printf("재고가 부족합니다\n");
						break;
					}
					else
					{
						printf("지불하실 금액은 %d원 입니다\n",gs25[j].con_price*amount);
						fflush(stdin);
						printf("구매하시겠습니까 ?(y/n) ");
						scanf("%c",&yn);
						if(yn=='y' || yn=='Y')
						{
							fflush(stdin);
							printf("포인트 결제를 하시겠습니까? (y/n)");
							scanf("%c",&yn);
							if(yn=='y' || yn=='Y')
						    {
								fflush(stdin);
								printf("회원 번호를 입력해 주세요 :");
								scanf("%d",&num);
								for(i=0; i<=9; i++)
								{
									if(num==(poin[i].number))
									{
										printf("d");
										if(poin[i].allpoint>=1000)
										{
											res=gs25[j].con_price*amount-poin[i].allpoint;
											poin[i].allpoint=0;
											if(res!=0)
											{
												printf("남은 금액은 %d원 입니다. 지불할 금액을 적어주세요:",res);
												scanf("%d",&pay);
												printf("거스름 돈은 %d원 입니다.\n",pay-(gs25[j].con_price*amount));
								                pro->allpro+=gs25[j].con_price*amount;
								                pro->netpro=(pro->allpro)-(gs25[j].stocked_price*amount);
												break;
											}
										}
										else
										{
											printf("포인트가 부족합니다.\n");
											break;
										}
									}
									if(i==9) //9개를 다 검사하고 10번째로 검사 할 시
									{
										printf("등록되지 않은 회원입니다");
									}
								}
							}
							else
							{
								printf("지불할 금액을 입력하세요 :");
								scanf("%d",&pay);
								printf("회원 번호를 입력해 주세요 :");
								scanf("%d",&num);
								for(i=0; i<=9; i++)
								{
									if(i==9) //9개를 다 검사하고 10번째로 검사 할 시
									{
										printf("등록되지 않은 회원입니다\n");
									}
									if(num==(poin[i].number))
									{
										poin[i].allpoint+=(gs25[j].con_price*amount)*0.01;
										printf("포인트 %d점이 적립되었습니다.\n",(gs25[j].con_price*amount)*0.01);
									}
								}
								printf("거스름 돈은 %d원 입니다.\n",pay-(gs25[j].con_price*amount));
								pro->allpro+=gs25[j].con_price*amount;
								pro->netpro=(pro->allpro)-(gs25[j].stocked_price*amount);
								break;
							}
						}
						else
						{
							break;
						}
					}
				}
		}
	}
}