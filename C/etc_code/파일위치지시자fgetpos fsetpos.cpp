#include <stdio.h>

int main()
{
	fpos_t fpos;

	/* ���ϻ��� */
	FILE * fp = fopen("C:\\test\\text.txt", "wt");
	fputs("12345", fp);
	fclose(fp);

	/* ���ϰ��� */
	fp = fopen("C:\\test\\text.txt", "rt");

	putchar(fgetc(fp));		// 1 ���, ���� ��ġ �����ڴ� 2�� ����Ŵ
	fgetpos(fp, &fpos);		// ����, ���� ���� ��ġ ������ ����

	putchar(fgetc(fp));		// 2 ���, ���� ��ġ �����ڴ� 3�� ����Ŵ
	fsetpos(fp, &fpos);		// ����, ���� ��ġ �����ڴ� �ٽ� 2�� ����Ŵ

	putchar(fgetc(fp));		// 2 ���, ���� ��ġ �����ڴ� 3�� ����Ŵ
	fclose(fp);

	return 0;
}
