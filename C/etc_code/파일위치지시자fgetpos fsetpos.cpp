#include <stdio.h>

int main()
{
	fpos_t fpos;

	/* 파일생성 */
	FILE * fp = fopen("C:\\test\\text.txt", "wt");
	fputs("12345", fp);
	fclose(fp);

	/* 파일개방 */
	fp = fopen("C:\\test\\text.txt", "rt");

	putchar(fgetc(fp));		// 1 출력, 파일 위치 지시자는 2를 가리킴
	fgetpos(fp, &fpos);		// 저장, 현재 파일 위치 지시자 정보

	putchar(fgetc(fp));		// 2 출력, 파일 위치 지시자는 3을 가리킴
	fsetpos(fp, &fpos);		// 복원, 파일 위치 지시자는 다시 2를 가리킴

	putchar(fgetc(fp));		// 2 출력, 파일 위치 지시자는 3을 가리킴
	fclose(fp);

	return 0;
}
