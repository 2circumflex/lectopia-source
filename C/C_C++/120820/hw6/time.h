class Time
{
	private:
		int hour;
		int min;
	public:
		Time();	//디폴트 생성자
		Time(int, int);	//시간, 분으로 초기화하는 생성자
		Time(double);	//시간을 실수값으로 초기화하는 생성자
		Time(const Time &tr);	//복사 생성자
		Time plus(const Time &tr);	//두 객체의 시간을 더해서 리턴한다.
		void setHour(int);	//hour멤버의 값을 전달인자로 수정하는 함수
		int getHour();	//hour멤버의 값을 리턴하는 함수
		void setMin(int);	//min멤버의 값을 전달인자로 수정하는 함수
		int getMin();	//min멤버의 값을 리턴한느 함수
};