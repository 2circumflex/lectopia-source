class San
{
	private:
		char *name;
		int height;
	public:
		San&operator=(San&b);
		San();	//����Ʈ ������
		San(const char*, int);	//�����ε�� ������
		San(const San &r);	//���� ������
		~San();	//�Ҹ���
		void setName(char *);
		char *getName();
		void setHeight(int);
		int getHeight();
};