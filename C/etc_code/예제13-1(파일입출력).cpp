#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[])
{
	int c;
	FILE *ifp, *ofp;
	if(argc != 3)
	{
		printf("사용법:%s 원본파일 복사본파일\n", argv[0]);
		return 0;
	}
	//assert(ifp!=NULL);
	if((ifp = fopen(argv[1], "rb")) == NULL)
	{
		printf("File open error!\n");
		return 0;
	}
	//assert(ifp!=NULL);
	if((ofp = fopen(argv[2], "wb")) == NULL)
	{
		printf("File open error!\n");
		return 0;
	}
	while((c=fgetc(ifp))!=EOF)
	{
		fputc(c, ofp);
	}
	fclose(ifp);
	fclose(ofp);
	return 0;
}