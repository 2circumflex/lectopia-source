#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct _Person
{
	int age;
	char *name;
}Person;


void input(Person *, int);
void sort(Person *, int);
void output(Person *, int);
void myFree(Person *, int);
void assign(Person *, Person *);
void search(Person *, int);
int nameCompare(void *, void *);
int ageCompare(void *, void *);
int searchUnique(Person *ary, int size, void * an, int (*dataCompare)(void * a, void * b), Person *temp);



int main()
{
	Person ary[5];
	int size = sizeof(ary)/sizeof(ary[0]);

	input(ary, size);
	sort(ary, size);
	output(ary, size);
	assign(&ary[3], &ary[4]);
	output(ary, size);
	assign(&ary[3], &ary[4]);
	output(ary, size);
	assign(&ary[3], &ary[4]);
	output(ary, size);

	search(ary, size);
	
	
	myFree(ary, size);
}

//
void search(Person *ary, int size)
{
	Person temp;
	int res;
	int age, menu;
	char name[100];
	
	while(1)
	{
		printf("���̰˻�(1)/�̸��˻�(2)/����(3) : ");
		scanf("%d", &menu);
		if(menu==3)	{break;}
		else if(menu==1)
		{
			printf("�����Է� : ");
			scanf("%d", &age);
			res = searchUnique(ary, size, &age, ageCompare, &temp);
		}
		else if(menu==2)
		{
			fflush(stdin);
			printf("�̸��Է� : ");
			scanf("%s", name);
			res = searchUnique(ary, size, name, nameCompare, &temp);
		}
		if(res==1)//ã������
		{
			printf("ã�� ��� ���� : %s\n", temp.name);
			printf("ã�� ��� ���� : %d\n", temp.age);
			free(temp.name);	//?
		}
	}
}

//
int searchUnique(Person *ary, int size, void * an, int (*dataCompare)(void * a, void * b), Person *temp)
{
	int i;

	for(i=0; i<size; i++)
	{
		if(dataCompare(ary+i, an)==0)
		{			
			temp->name = (char *)malloc((strlen(ary[i].name)+1));
			temp->age = ary[i].age;
			strcpy(temp->name, ary[i].name);
			return 1;
		}
	}
	return 0;
}

//���� ��
int ageCompare(void *p1, void *p2)
{
	if(((Person*)p1)->age > *(int *)p2)	{return 1;}
	else if(((Person*)p1)->age == *(int *)p2)	{return 0;}
	else	{return -1;}
}

//���ڿ� ��
int nameCompare(void *p1, void *p2)
{
	if(strcmp(((Person*)p1)->name, (char*)p2) > 0)	{return 1;}
	else if(strcmp(((Person*)p1)->name, (char*)p2) == 0)	{return 0;}
	else	{return -1;}
}

////�˻�
//void search(Person *p, int size)
//{
//	int i, su, age;
//	char str[100];
//	printf("[�˻�~~]\n");
//
//	while(1)
//	{
//		printf("���̰˻�(1)/�̸��˻�(2)/����(3) : ");
//		scanf("%d", &su);
//		if(su == 3)
//		{	
//			return;
//		}
//		else if(su ==1)
//		{
//			printf("ã�� ���� �Է� : ");
//			scanf("%d", &age);
//		
//			for(i=0; i<size; i++)
//			{
//				if(p[i].age == age)
//				{
//					printf("ã�� ����� ���� : %s\n", p[i].name);
//					printf("ã�� ����� ���� : %d\n", p[i].age);
//				}
//				else if(i== size-1)
//				{
//					printf("�������� �ʽ��ϴ�\n");
//				}
//			}
//			printf("�������� �ʽ��ϴ�\n");		
//		}
//		else if(su == 2)
//		{
//			printf("ã�� �̸� : ");
//			scanf("%s", str);
//
//			for(i=0; i<size; i++)
//			{
//				if(strcmp(p[i].name, str)==0)
//				{				
//					printf("ã�� ����� ���� : %d\n", p[i].age);
//					printf("ã�� ����� ���� : %s\n", p[i].name);
//					break;
//				}
//				else if(i== size-1)
//				{
//					printf("�������� �ʽ��ϴ�\n");
//				}
//			}
//		
//		}
//	}
//}

//
void assign(Person *a, Person *b)
{	
	free(a->name);
	int size = strlen(b->name) + 1;
	a->age = b->age;
	a->name = (char *)malloc(sizeof(char) * size);
	strcpy(a->name, b->name);	
}



//����
void myFree(Person *p, int size)
{
	int i;

	for(i=0; i<size; i++)
	{
		free(p[i].name);
	}
}

//���
void output(Person *p, int size)
{
	int i;

	printf("��¸޴�\n");
	for(i=0; i<size; i++)
	{
		printf("�̸� : %s  ���� : %d\n", p[i].name, p[i].age);
	}
	printf("\n");
}

//����
void sort(Person *p, int size)
{
	int i, j, t_age;
	char *sp;

	for(i=0; i<size-1; i++)
	{
		for(j=i+1; j<size; j++)
		{
			if(strcmp(p[i].name, p[j].name) > 0)
			{
				sp = p[i].name;
				p[i].name = p[j].name;
				p[j].name = sp;

				t_age = p[i].age;
				p[i].age = p[j].age;
				p[j].age = t_age;
			}
		}
	}
}

//�Է�
void input(Person *p, int size)
{
	int i, age;
	char str[100];

	printf("�Է¸޴�\n");
	for(i=0; i<size; i++)
	{
		printf("���̸� �Է��ϼ��� : ");
		scanf("%d", &age);

		fflush(stdin);	
		printf("�̸��� �Է��ϼ��� : ");
		scanf("%s", str);
		
		p[i].age = age;
		p[i].name = (char *)malloc(sizeof(char) * (strlen(str)+1));
		strcpy(p[i].name, str);
	}

	printf("����Է��Ͽ����ϴ�\n\n");
}