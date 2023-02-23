typedef struct _Word
{
	char word[100];
	int x,y;	//��ǥ
	int len;	//�ܾ����
	int ok;		//ȭ�鿡 ��¿���
}Word;

struct Signal
{
	int ok;			//ȭ�鿡 ��¿���
	char ch;		//����� ����
	int x,y;		//��ǥ
	int distance;	//�̵��� �Ÿ�
	int nFrame;		//�ӵ�
	int nStay;		//�ӵ��� ���� ī��Ʈ
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