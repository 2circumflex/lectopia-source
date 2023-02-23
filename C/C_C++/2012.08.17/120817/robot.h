class Robot
{
	private:
		//char name[20];
		char * name;
		int energy;
		void errRun();	//error 메시지 출력
	public:
		~Robot();	//소멸자
		Robot();	//생성자함수		
		Robot(char *, int=0);	//생성자함수
		Robot(Robot &);
		Robot&operator=(Robot&b);
		bool operator==(Robot&b);
		void init(char *, int e);
		void go();		//10 energy 감소
		void back();	//20 energy 감소
		void turn();	//30 energy 감소
		void jump();	//40 energy 감소
		void charge(int e);	//충전
		char * getName();
		void setName(char *);
		int getEnergy();
		void setEnergy(int);
};