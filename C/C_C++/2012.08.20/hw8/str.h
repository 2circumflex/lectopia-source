class MyString
{
	private:
		char *str;	//문자열을 연결하는 포인터
		int len;	//길이 저장
	public:
		MyString();	//디폴트 생성자
		MyString(const char *);	//오버로디드 생성자
		MyString(const MyString &r);	//복사 생성자
		~MyString();	//소멸자
		MyString & operator=(MyString &r);	//대입연산자 함수
		bool operator==(MyString &r);	//equal 연산자 함수
		void setStr(char *);
		char * getStr();
		void setLen(int);
		int getLen();		
};