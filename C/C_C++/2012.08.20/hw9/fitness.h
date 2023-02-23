class Fitness
{
	private:
		int num;		//ȸ����ȣ
		char *name;		//����
		double weight;	//������(kg����)
		double height;	//����(Ű-cm����)
	
	public:
		//�������Լ�, �Ҹ����Լ�
		Fitness();		//ȸ����ȣ�� 0, ������ null string, �����Դ� 0kg, ������ 0cm�� �ʱ�ȭ
		Fitness(int num, char *name, double weight, double height);
		Fitness(Fitness &r);
		~Fitness();	//���� �Ҵ�� �޸� ����
		//������ �Լ�
		Fitness & operator=(Fitness &r);
		bool operator==(Fitness &r);
		//setter, getter �Լ�
		void setNum(int num);			//num ��� �ʱ�ȭ �Լ�
		int getNum();					//num ����� ���� �ϴ� �Լ�
		void setName(char *name);		//name ����� �ʱ�ȭ �Լ�
		char* getName();				//name ����� ���� �ϴ� �Լ�
		void setWeight(double weight);	//weight ��� �ʱ�ȭ �Լ�
		double getWeight();				//weight ����� ���� �ϴ� �Լ�
		void setHeight(double height);	//height ��� �ʱ�ȭ �Լ�
		double getHeight();				//height ����� ���� �ϴ� �Լ�
		//��Ÿ����Լ�
		double bmi();					//�ش�ȸ���� bmi�� ����Ͽ� �����ϴ� �Լ�
};