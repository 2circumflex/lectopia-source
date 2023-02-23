void clrscr(int startX, int startY, int endX, int endY); //부분 삭제함수
void gotoxy(int x, int y);// 커서이동함수
void removeCursor();//커서 없애는 함수
void displayCursor(); //커서 보이게하는 함수
char inKey(int *keyFlag);// 특수키 입력 받을수 있게끔 하는 함수
void textcolor(int foreground, int background); //컬러 바꾸는 함수
int random(int n); 