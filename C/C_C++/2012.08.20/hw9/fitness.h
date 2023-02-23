class Fitness
{
	private:
		int num;		//회원번호
		char *name;		//성명
		double weight;	//몸무게(kg단위)
		double height;	//신장(키-cm단위)
	
	public:
		//생성자함수, 소멸자함수
		Fitness();		//회원번호는 0, 성명은 null string, 몸무게는 0kg, 신장은 0cm로 초기화
		Fitness(int num, char *name, double weight, double height);
		Fitness(Fitness &r);
		~Fitness();	//동적 할당된 메모리 해제
		//연산자 함수
		Fitness & operator=(Fitness &r);
		bool operator==(Fitness &r);
		//setter, getter 함수
		void setNum(int num);			//num 멤버 초기화 함수
		int getNum();					//num 멤버값 리턴 하는 함수
		void setName(char *name);		//name 멤버값 초기화 함수
		char* getName();				//name 멤버값 리턴 하는 함수
		void setWeight(double weight);	//weight 멤버 초기화 함수
		double getWeight();				//weight 멤버값 리턴 하는 함수
		void setHeight(double height);	//height 멤버 초기화 함수
		double getHeight();				//height 멤버값 리턴 하는 함수
		//기타멤버함수
		double bmi();					//해당회원의 bmi를 계산하여 리턴하는 함수
};