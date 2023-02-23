/* ���������α׷� */
/* ������, �̷ο� */

#pragma warning(disable:4996)
#pragma warning(disable:4244)
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>


//color���
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


//������ ����ü
struct gs
{
	char item[20];
	int amount;
	int sale_amount;
	int stocked_price;
	int con_price;
};

//�ʱ�޴����� ��¥�� ���Ա�
struct intro
{
	int day;
	int proper;
};

//����Ʈ ����ü
struct point
{
	int number;
	int allpoint;
};

//���� ����ü
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


//����!!!!!
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
profit.txt������Ʈ
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
gs25.txt������Ʈ
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
�Ǹż���
ǰ�� �ǸŰ��� �Ѽ��� ������
��ü �Ѽ���
��ü ������
��ȸ�� ��¥�� �Է��ؼ� ��¥�� �Ѽ��� �������� ��Ÿ����
*/
void margin(struct gs * gs25, int size, struct profit pro)
{	
	int i, c_item, s_item, c_tot=0, s_tot=0;
	char day[10], pday[10];
	FILE * fp;

	system("cls");
		
	printf("   [ǰ��]  [�ǸŰ���]  [�Ѽ���]  [������]\n");
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
	printf("��ü ���� : %d\n", c_tot);
	printf("��ü ������ : %d\n", c_tot - s_tot);
	
	//��¥�� ��ü ����, ��ü ������ ��ȸ
	while(1)
	{
		fflush(stdin);
		printf("��ȸ�� ��¥�� �Է��ϼ���(YYYYMMDD) : ");
		scanf("%s", day);
	
		if(strcmp(day, "end") == 0)
		{
			printf("�����մϴ�, �ƹ�Ű�� ������ �޴��� ���ư��ϴ�\n");			
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
					printf("%.4s�� %s�� %s���� �Ѽ����� %d���̰� �������� %d���Դϴ�.\n", day, day[4]+day[5], day[6]+day[7], pro.allpro, pro.netpro);
					fclose(fp);
					break;
				}
			}			
		}		
	}	
}

/*
����������ü �ʱ�ȭ
��ǰ��, �԰�, �Һ��ڰ� �ʱ�ȭ
gs25.txt ������ ������ ����, �Ǹż����� 0����
������ �ؽ�Ʈ���Ͽ��� �о�´�
*/
void init(struct gs * gs25, int size)
{
	int i;
	char str[10][20] = {"�����", "���ڱ�", "���ĸ�", "ġ�佺", "�����۽�", "�ݶ�", "���̴�", "������", "Ŀ��", "����"};
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
ǰ��
ǰ�񺰷� ���� ��Ÿ���� 5���̸��� ǥ��
��ǰ �� ��������
*/
void stock(struct gs * gs25, int size, int * proper)
{	
	int i, num, su;
	char item[20];
	system("cls");
	
	//�Ʒ��� ��ǰ �� ��������
	while(1)
	{
		printf("-------------------------\n");
		printf("  [��ǰ��]\t  [����]\n");

		for(i=0; i<size; i++)
		{
			if(gs25[i].amount < 5)	textcolor(LIGHTRED, BLACK);
			else if(gs25[i].amount >= 5) textcolor(LIGHTGRAY, BLACK);
			printf("%10s       %5d��\n", gs25[i].item, gs25[i].amount);
		}
		textcolor(LIGHTGRAY, BLACK);
		printf("-------------------------\n");		

		fflush(stdin);
		printf("�޴��� �����ϼ���(��ǰ:1, ����:2, ����:0) : ");
		scanf("%d", &num);

		//0�Է��ϸ� ����
		if(num==0)
		{
			printf("�����մϴ�, �ƹ�Ű�� ������ �޴��� ���ư��ϴ�\n");
			getch();
			return;
		}
				
		if(num == 1 || num == 2)
		{
			//��ǰ
			if(num == 1)
			{
				fflush(stdin);
				printf("��ǰ�� ��ǰ�� �Է��ϼ��� : ");
				scanf("%s", item);
					
				for(i=0; i<size; i++)
				{
					if(strcmp(item, gs25[i].item)==0)
					{
						while(1)
						{
							fflush(stdin);
							printf("��ǰ�� ������ �Է��ϼ��� : ");
							scanf("%d", &su);

							if(su>0 && gs25[i].amount>=su)
							{
								gs25[i].amount -= su;
								*proper += gs25[i].stocked_price * su;
								printf("%s��ǰ�� %d�� ��ǰ�Ǿ����ϴ�\n", gs25[i].item, su);
								break;
							}
							else
							{
								printf("*�߸��Է��߽��ϴ�\n");
							}
						}
					}
				}				
			}
			//����
			else if(num == 2)
			{
				
				fflush(stdin);
				printf("������ ��ǰ�� �Է��ϼ��� : ");
				scanf("%s", item);

				for(i=0; i<size; i++)
				{
					if(strcmp(item, gs25[i].item)==0)
					{
						while(1)
						{
							fflush(stdin);
							printf("������ ������ �Է����ּ��� : ");
							scanf("%d", &su);

							if(su>=0)
							{
								gs25[i].amount = su;
									
								printf("%s��ǰ�� %d���� �����Ǿ����ϴ�\n", gs25[i].item, su);
								break;
							}
							else
							{						
								printf("*�߸��Է��߽��ϴ�\n");						
							}
						}
					}
				}				
			}
		}
		else
		{
			printf("*�߸��Է��߽��ϴ�\n");
		}
	}
}

/*
�ؽ�ƮĮ��
����� 5���̸��� ǰ�� ��Ÿ���� ���� ���
*/
void textcolor(int foreground, int background) 
{ 
	int color=foreground+background*16; 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}


/*--------------------------------------------------------------------------------------*/


//�԰� �Լ�
void stocked(struct intro *ap,struct gs *gs25,int size)
{
	int i,j;
	char name[20];
	int amount;//�԰��� ����
	char yn;//�ѹ��� ���� ����
	FILE *fp = fopen("gs25.txt", "rt");
	system("cls");
	if(fp==NULL)
	{
		printf("������ �������� �ʽ��ϴ�");
	}
	else
	{
		printf("[ǰ���]   [�԰�]\n");
		for(i=0; i<10; i++)
		{			
			printf("%3s %5d��\n",gs25[i].item,gs25[i].stocked_price);
		}
		getch();

		while(1)
		{
			fflush(stdin);
			printf("�԰��ϰ��� �ϴ� ǰ����� �Է��ϼ��� :");
			scanf("%s",name);
			if(strcmp(name,"end")==0)
			{
				/*for(i=0; i<10; i++)
		        {
			         printf("ǰ���    ����\n");
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
					printf("�ش��ϴ� �̸��� ǰ���� �����ϴ�\n");
					break;
				}
				if(strcmp(name,gs25[j].item)==0)
				{
					printf("�԰��� ������ �Է��ϼ��� :");
					scanf("%d",&amount);
					fflush(stdin);
					printf("�԰��Ͻðڽ��ϱ�? (y/n)");
					scanf("%c",&yn);
					if(yn=='y' || yn=='Y')
					{
						printf("�԰��Ͽ����ϴ� \n");
						(gs25[j].amount)+=amount;
						ap->proper-=(gs25[j].stocked_price)*amount;
						break; 
					}
					else
					{
						printf("��ҵǾ����ϴ�\n");
						break;
					}
				}
			}
		}
	}
}

//�ʱ�޴�
int propert(struct intro *ap)
{
	char name[10];
	FILE *fp=fopen("profit.txt","at");
	printf("[�� �� �� �� �� �� ��]\n");
	while(1)
	{
		printf("end�� �Է��ϸ� �����մϴ�\n");
		printf("�Ǹ��� ���� �Է��ϼ��� :");
		scanf("%s",&name);
		if(strcmp(name,"end")==0)
		{
			return 0;
		}
		if(strcmp(name,"�̷ο�")==0)
		{
			printf("��¥�� �Է��ϼ��� :");
			scanf("%d",&(ap->day));
			fprintf(fp,"%d",ap->day);
			printf("�ݾ��� �Է��ϼ��� :");
			scanf("%d",&(ap->proper));
			break;
		}
		else
		{
			printf("�̸��� �߸� �Է� �Ǿ����ϴ�.\n");
		}
	}
	fclose(fp);
	return 1;
}
//�޴�
int menu()
{
	int num;
	system("cls");
	printf("1. �԰�\n");
	printf("2. �Ǹ�\n");
	printf("3. ���\n");
	printf("4. �Ǹż���\n");
	printf("5. �ʱ�޴�\n");
	printf("�޴��� �Է��ϼ��� :");
	fflush(stdin);
	scanf("%d",&num);
	return num;
}

//�Ǹ�
void sale(struct gs *gs25, struct point *poin,struct profit *pro,struct intro *ap)
{
	int i,j;
	char name[20];//�Է¹��� ��ǰ���� ������ �迭
	int amount;//������ �Է¹޾����� ������ ����
	int num;//ȸ�� ��ȣ�� �Է¹��� ����
	char yn;//y/n�� �����͸� �����ϱ� ���� ����
	int res;//��������� �����ؾ��� ���� ����� ����
	int pay;//������ �ݾ��� ������ ����

	system("cls");
	printf(" [ǰ���]   [����]    �ǸŰ�\n");
	for(i=0; i<10; i++)
    {	     
		 printf("%5s %5d %10d\n",gs25[i].item,gs25[i].amount,gs25[i].con_price);
	}

	FILE *fp = fopen("point.txt","rt");
	if(fp==NULL)
	{
		printf("������ �������� �ʽ��ϴ�\n");
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
		printf("������ ��ǰ���� �Է��ϼ��� :");
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
					printf("�ش��ϴ� �̸��� ǰ���� �����ϴ�\n");
					break;
				}
				if(strcmp(name,gs25[j].item)==0)
				{
					printf("������ ��ǰ�� ������ �Է��ϼ��� :");
					scanf("%d",&amount);
					if(amount>gs25[j].amount)
					{
						printf("��� �����մϴ�\n");
						break;
					}
					else
					{
						printf("�����Ͻ� �ݾ��� %d�� �Դϴ�\n",gs25[j].con_price*amount);
						fflush(stdin);
						printf("�����Ͻðڽ��ϱ� ?(y/n) ");
						scanf("%c",&yn);
						if(yn=='y' || yn=='Y')
						{
							fflush(stdin);
							printf("����Ʈ ������ �Ͻðڽ��ϱ�? (y/n)");
							scanf("%c",&yn);
							if(yn=='y' || yn=='Y')
						    {
								fflush(stdin);
								printf("ȸ�� ��ȣ�� �Է��� �ּ��� :");
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
												printf("���� �ݾ��� %d�� �Դϴ�. ������ �ݾ��� �����ּ���:",res);
												scanf("%d",&pay);
												printf("�Ž��� ���� %d�� �Դϴ�.\n",pay-(gs25[j].con_price*amount));
								                pro->allpro+=gs25[j].con_price*amount;
								                pro->netpro=(pro->allpro)-(gs25[j].stocked_price*amount);
												break;
											}
										}
										else
										{
											printf("����Ʈ�� �����մϴ�.\n");
											break;
										}
									}
									if(i==9) //9���� �� �˻��ϰ� 10��°�� �˻� �� ��
									{
										printf("��ϵ��� ���� ȸ���Դϴ�");
									}
								}
							}
							else
							{
								printf("������ �ݾ��� �Է��ϼ��� :");
								scanf("%d",&pay);
								printf("ȸ�� ��ȣ�� �Է��� �ּ��� :");
								scanf("%d",&num);
								for(i=0; i<=9; i++)
								{
									if(i==9) //9���� �� �˻��ϰ� 10��°�� �˻� �� ��
									{
										printf("��ϵ��� ���� ȸ���Դϴ�\n");
									}
									if(num==(poin[i].number))
									{
										poin[i].allpoint+=(gs25[j].con_price*amount)*0.01;
										printf("����Ʈ %d���� �����Ǿ����ϴ�.\n",(gs25[j].con_price*amount)*0.01);
									}
								}
								printf("�Ž��� ���� %d�� �Դϴ�.\n",pay-(gs25[j].con_price*amount));
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