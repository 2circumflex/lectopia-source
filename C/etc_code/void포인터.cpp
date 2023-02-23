#include<stdio.h>
#include<malloc.h>
#include<memory.h>
#include<string.h>
void mySort(void *, int, size_t, int (*)(void *, void *));
void display(void *, int, size_t, void (*)(void *));
int integerCompare(void *, void *);
int doubleCompare(void *, void *);
int stringCompare(void *, void *);
void integerPrint(void *), doublePrint(void *), stringPrint(void *);
//-------------------------------------------------------------------
int main()
{
	//정수형데이터 정렬하여 출력하기
	int iArray[10]={5,2,9,11,1,8,10,15,20,3};
	mySort(iArray, sizeof(iArray)/sizeof(iArray[0]), sizeof(iArray[0]),
		integerCompare);
	printf("[[정수형 데이터 정렬하여 출력하기]]\n");
	display(iArray, sizeof(iArray)/sizeof(iArray[0]), sizeof(iArray[0]), 
		integerPrint);

	//실수형데이터 정렬하여 출력하기
	double dArray[5]={12.5, 3.12, 7.7, 20.35, 9.8};
	mySort(dArray, sizeof(dArray)/sizeof(dArray[0]), sizeof(dArray[0]),
		doubleCompare);
	printf("[[실수형 데이터 정렬하여 출력하기]]\n");
	display(dArray, sizeof(dArray)/sizeof(dArray[0]), sizeof(dArray[0]), 
		doublePrint);

	//문자열형데이터 정렬하여 출력하기
	char sArray[7][10]={"희망", "꿈", "도전", "용기", "노력", "믿음",
		"협력"};
	mySort(sArray, sizeof(sArray)/sizeof(sArray[0]), sizeof(sArray[0]),
		stringCompare);
	printf("[[문자열형 데이터 정렬하여 출력하기]]\n");
	display(sArray, sizeof(sArray)/sizeof(sArray[0]), sizeof(sArray[0]), 
		stringPrint);
	return 0;
} // end of main()
//-------------------------------------------------------------------
void mySort(void *p, int count, size_t size, 
	int (*dataCompare)(void *, void *))
{
	int i, j;
	void *tmp;
	tmp=malloc(size);

	for(i=0; i<count-1; i++)
	{
		for(j=i+1; j<count; j++)
		{
			if(dataCompare((char *)p+i*size, (char *)p+j*size)>0)
			{
				memcpy(tmp, (char *)p+i*size, size);
				memcpy((char *)p+i*size, (char *)p+j*size, size);
				memcpy((char *)p+j*size, tmp, size);
			}
		}
	}
	free(tmp);
}
//-------------------------------------------------------------------
void display(void *p, int count, size_t size, 
	void (*dataPrint)(void *))
{
	int i;
	for(i=0; i<count; i++){
		printf("%d. ", i+1);
		dataPrint( (char *)p+i*size );
	}
}
//-------------------------------------------------------------------
int integerCompare(void *p1, void *p2)
{
	if( *(int *)p1 > *(int *)p2 ) {return 1;}
	else if(  *(int *)p1 == *(int *)p2 ) {return 0;}
	else {return -1;}
}
//-------------------------------------------------------------------
void integerPrint(void *p)
{
	printf("%d\n", *(int *)p);
}
//-------------------------------------------------------------------
int doubleCompare(void *p1, void *p2)
{
	if( *(double *)p1 > *(double *)p2 ) {return 1;}
	else if(  *(double *)p1 == *(double *)p2 ) {return 0;}
	else {return -1;}
}
//-------------------------------------------------------------------
void doublePrint(void *p)
{
	printf("%.2lf\n", *(double *)p);
}
//-------------------------------------------------------------------
int stringCompare(void *p1, void *p2)
{
	if( strcmp((char *)p1, (char *)p2)>0 ) {return 1;}
	else if(  strcmp((char *)p1, (char *)p2)==0 ) {return 0;}
	else {return -1;}
}
//-------------------------------------------------------------------
void stringPrint(void *p)
{
	printf("%s\n",(char *)p);
}
