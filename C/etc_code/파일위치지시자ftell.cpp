#include <stdio.h>

int main()
{
	long fpos;
	int i;

	/* 颇老积己 */
	FILE * fp = fopen("C:\\test\\text.txt", "wt");
	fputs("1234-", fp);
	fclose(fp);

	/* 颇老俺规 */
	fp = fopen("C:\\test\\text.txt", "rt");

	for(i=0; i<4; i++)
	{
		putchar(fgetc(fp));
		fpos = ftell(fp);
		fseek(fp, -1, SEEK_END);
		putchar(fgetc(fp));

		fseek(fp, fpos, SEEK_SET);
	}
	fclose(fp);
	return 0;
}
