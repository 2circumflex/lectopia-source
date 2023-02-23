#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>

void mySort(void *, int, size_t, int (*)(void *, void *));
void display(void *, int, size_t, void (*)(void *));
int iCompare(void *, void *);
int dCompare(void *, void *);
int sCompare(void *, void *);
void iPrint(void *), dPrint(void *), sPrint(void *);

int main()
{
	//������������ �����Ͽ� ����ϱ�
	int iArry[10]  = {5,2,9,11,1,8,10,15,20,3};
	mySort(iArry, sizeof(iArry)/sizeof(iArry[0]), sizeof(iArry[0]), iCompare);
	display(iArry, sizeof(iArry)/sizeof(iArry[0]), sizeof(iArry[0]), iPrint);
	
	//�Ǽ��������� �����Ͽ� ����ϱ�
	double dArray[5] = {12.5, 3.12, 7.7, 20.35, 9.8};
	mySort(dArray, sizeof(dArray)/sizeof(dArray[0]), sizeof(dArray[0]), dCompare);
	display(dArray, sizeof(dArray)/sizeof(dArray[0]), sizeof(dArray[0]), dPrint);

	//���ڿ��� ������ �����Ͽ� ����ϱ�
	char sArray[7][10] = {"���", "��", "����", "���", "���", "����", "����"};
	mySort(sArray, sizeof(sArray)/sizeof(sArray[0]), sizeof(sArray[0]), sCompare);	
	display(sArray, sizeof(sArray)/sizeof(sArray[0]), sizeof(sArray[0]), sPrint);	

	return 0;
}

//���
void display(void *p, int cnt, size_t size, void (*dataPrint)(void *))
{
	int i;

	for(i=0; i<cnt; i++)
	{
		printf("%d. ", i+1);
		dataPrint((char*)p+i*size);
	}
	printf("\n");
}

//�������
void iPrint(void *p)
{
	printf("%d\n", *(int*)p);
}

//�Ǽ����
void dPrint(void *p)
{
	printf("%.2lf\n", *(double*)p);
}

//���ڿ����
void sPrint(void *p)
{
	printf("%s\n", (char*)p);
}

//����(��������)
void mySort(void *p, int cnt, size_t size, int (*dataCompare)(void *, void *))
{
	int i, j;
	void *tmp;
	tmp = malloc(size);
	
	for(i=0; i<cnt-1; i++)
	{
		for(j=i+1; j<cnt; j++)
		{
			if(dataCompare((char*)p+i*size, (char*)p+j*size) > 0)
			{
				memcpy(tmp, (char*)p+i*size, size);
				memcpy((char*)p+i*size, (char*)p+j*size, size);
				memcpy((char*)p+j*size, tmp, size);
			}
		}
	}

	free(tmp);
}

//������
int iCompare(void *a, void *b)
{
	if( *(int*)a > *(int*)b)	return 1;
	else if( *(int*)a == *(int*)b)	return 0;
	else	return -1;
}

//�Ǽ���
int dCompare(void *a, void *b)
{
	if( *(double*)a > *(double*)b)	return 1;
	else if( *(double*)a == *(double*)b)	return 0;
	else	return -1;
}

//���ڿ���
int sCompare(void *a, void *b)
{ 
	if( strcmp((char*)a, (char*)b) > 0)	return 1;
	else if( strcmp((char*)a, (char*)b) == 0)	return 0;
	else	return -1;
}