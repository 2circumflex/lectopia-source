class Time
{
	private:
		int hour;
		int min;
	public:
		Time();	//����Ʈ ������
		Time(int, int);	//�ð�, ������ �ʱ�ȭ�ϴ� ������
		Time(double);	//�ð��� �Ǽ������� �ʱ�ȭ�ϴ� ������
		Time(const Time &tr);	//���� ������
		Time plus(const Time &tr);	//�� ��ü�� �ð��� ���ؼ� �����Ѵ�.
		void setHour(int);	//hour����� ���� �������ڷ� �����ϴ� �Լ�
		int getHour();	//hour����� ���� �����ϴ� �Լ�
		void setMin(int);	//min����� ���� �������ڷ� �����ϴ� �Լ�
		int getMin();	//min����� ���� �����Ѵ� �Լ�
};