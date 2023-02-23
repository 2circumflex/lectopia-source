typedef struct _Word
{
	char word[100];
	int x,y;	//좌표
	int len;	//단어길이
	int ok;		//화면에 출력여부
}Word;

struct Signal
{
	int ok;			//화면에 출력여부
	char ch;		//출력할 문자
	int x,y;		//좌표
	int distance;	//이동할 거리
	int nFrame;		//속도
	int nStay;		//속도에 대한 카운트
};

void wordLoad(Word* w);
void wordDisplay(Word* w);
void stringcheck(Word *w, char *cp, int *score);
void floorDisplay(int floor);
int floorUp(int *floor,Word *w);
void wordOk(Word* w);
void yPlus(Word* w);
void floorFrame(void);
void beginDisplay(void);
int wordGame(void);