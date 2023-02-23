
template <typename T>
class SmartArray : public MyArray<T>
{
private:
	T max;	//�ְ� ����
public:
	SmartArray() {}	//����Ʈ ������
	SmartArray(int s) : MyArray<T>(s), max(0)	//�����ε�� ������
	{}
	void put(int index, T val);	//put�Լ��� ������
	T getMax();	//max�� ����
	bool operator>(const SmartArray<T> &br);	//�񱳿�����
};

template <typename T>
void SmartArray<T>::put(int index, T val)
{
	if(max<val)
	{
		max = val;
	}
	
	MyArray<T>::put(index, val);
}

template <typename T>
T SmartArray<T>::getMax()
{
	return this->max;
}

template <typename T>
bool SmartArray<T>::operator>(const SmartArray<T> &br)
{
	if(this->max > br.max)
	{
		return true;
	}
	else
	{
		return false;
	}
}