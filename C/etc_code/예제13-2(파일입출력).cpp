#pragma warning(disable:4996)
#include <stdio.h>
#include <assert.h>


typedef struct _person
{
	char name[10];
	int age;
	double height;
}Person;


int main()
{
	FILE *fp;
	int i, res;
	int size;
	Person ary[5] = {{"이로운", 28, 182.9}, {"이성훈", 28, 165.5}, {"김원민", 29, 178.8}, {"최재경", 28, 178.6}, {"정주필", 28, 183.2}};
	Person temp;
	size = sizeof(ary)/sizeof(ary[0]);

	fp=fopen("C:\\test\\ftest.txt", "wt");
	assert(fp!=NULL);
	for(i=0; i<size; i++)
	{
		fwrite(ary+i, sizeof(Person), 1, fp);
	}
	fclose(fp);

	fp = fopen("C:\\test\\ftest.txt", "rt");
	assert(fp!=NULL);
	printf("1차 출력\n");
	while(!feof(fp))
	{
		res = fread(&temp, sizeof(Person), 1, fp);
		if(res!=1)	break;
		printf("%s %d %.2lf\n", temp.name, temp.age, temp.height);
	}

	rewind(fp);

	printf("2차 출력\n");
	while(!feof(fp))
	{
		res = fread(&temp, sizeof(Person), 1, fp);
		if(res!=1)	break;
		printf("%s %d %.2lf\n", temp.name, temp.age, temp.height);
	}


	return 0;
}

