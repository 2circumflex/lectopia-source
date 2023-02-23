class San
{
	private:
		char *name;
		int height;
	public:
		San&operator=(San&b);
		San();	//디폴트 생성자
		San(const char*, int);	//오버로디드 생성자
		San(const San &r);	//복사 생성자
		~San();	//소멸자
		void setName(char *);
		char *getName();
		void setHeight(int);
		int getHeight();
};