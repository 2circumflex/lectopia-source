class MyString
{
	private:
		char *str;	//���ڿ��� �����ϴ� ������
		int len;	//���� ����
	public:
		MyString();	//����Ʈ ������
		MyString(const char *);	//�����ε�� ������
		MyString(const MyString &r);	//���� ������
		~MyString();	//�Ҹ���
		MyString & operator=(MyString &r);	//���Կ����� �Լ�
		bool operator==(MyString &r);	//equal ������ �Լ�
		void setStr(char *);
		char * getStr();
		void setLen(int);
		int getLen();		
};