class Robot
{
	private:
		//char name[20];
		char * name;
		int energy;
		void errRun();	//error �޽��� ���
	public:
		~Robot();	//�Ҹ���
		Robot();	//�������Լ�		
		Robot(char *, int=0);	//�������Լ�
		Robot(Robot &);
		Robot&operator=(Robot&b);
		bool operator==(Robot&b);
		void init(char *, int e);
		void go();		//10 energy ����
		void back();	//20 energy ����
		void turn();	//30 energy ����
		void jump();	//40 energy ����
		void charge(int e);	//����
		char * getName();
		void setName(char *);
		int getEnergy();
		void setEnergy(int);
};