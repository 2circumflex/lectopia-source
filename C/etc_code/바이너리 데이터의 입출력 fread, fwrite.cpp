#pragma warning(disable:4996)
#include <stdio.h>
#define BUF_SIZE 30

int main()
{
	char buf[BUF_SIZE];
	int readCnt;
	
	FILE * src = fopen("C:\\test\\abc.bmp", "rb");
	FILE * des = fopen("C:\\test\\ddd.bmp", "wb");

	if(src == NULL || des == NULL)
	{
		puts("���Ͽ��� ����");
		return -1;
	}

	while(1)
	{
		readCnt = fread((void *)buf, 1, BUF_SIZE, src);

		if(readCnt<BUF_SIZE)
		{
			if(feof(src)!=0)
			{
				fwrite((void *)buf, 1, readCnt, des);
				puts("���Ϻ��� �Ϸ�");

			}
			else
			{
				puts("���Ϻ��� ����");
			}
			break;
		}
		fwrite((void *)buf, 1, BUF_SIZE, des);
	}
	

	fclose(src);
	fclose(des);

	return 0;
}

