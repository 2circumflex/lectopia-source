#include <stdio.h>

int main()
{
	/* ���� ���� */
	FILE * fp = fopen("C:\\test\\text.txt", "wt");
	fputs("123456789", fp);
	fclose(fp);

	/* ���� ���� */
	fp = fopen("C:\\test\\text.txt", "rt");

	/* SEEK_END test */
	fseek(fp, -2, SEEK_END);
	putchar(fgetc(fp));

	/* SEEK_SET test */
	fseek(fp, 2, SEEK_SET);
	putchar(fgetc(fp));

	/* SEEK_CUR test */
	fseek(fp, 2, SEEK_CUR);
	putchar(fgetc(fp));

	fclose(fp);
	
	return 0;
}
