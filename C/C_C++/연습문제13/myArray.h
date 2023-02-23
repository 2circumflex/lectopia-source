template <typename T>
class MyArray
{
private:
	T *ary;
	int size;
public:
	MyArray()	{ ary=0; size=0; } //����Ʈ ������
	MyArray(int s);	//�����ε�� ������
	MyArray(const MyArray &br);	//���� ������
	~MyArray() { delete [] ary; }	//�Ҹ���
	MyArray &operator=(const MyArray &br);	//�뿱������
	void put(int index, T val);	//val�� ���� index�濡 ����
	T get(int index);	//�迭��� �� index���� ���� ����
	T getSize();	//�迭����� ���� Ȯ��
	T* getAry(void);	//�迭����� ���� Ȯ��
};

template <typename T>
MyArray<T>::MyArray(int s) : size(s)
{
	this->ary = new T[s];
}

template <typename T>
MyArray<T>::MyArray(const MyArray<T> &br)
{
	T i;

	this->ary = new T[br.size];
	this->size = br.size;
	
	for(i=0; i<br.size; i++)
	{
		this->ary[i] = br.ary[i];
	}
}

template <typename T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T> &br)
{
	T i;
	if(this==&br) return *this;
	this->size = br.size;
	delete[] ary;

	ary = new T[this->size];
	
	for(i=0; i<this->size; i++)
	{
		ary[i] = br.ary[i];
	}

	return *this;
}

template <typename T>
void MyArray<T>::put(int index, T val)
{
	if(index > this->size || index < 0)
	{
		cout << "�������� �ʽ��ϴ�" << endl;
	}
	else
	{
		this->ary[index] = val;
	}
}

template <typename T>
T MyArray<T>::get(int index)
{
	if(index > this->size || index < 0)
	{
		cout << "�������� �ʽ��ϴ�" << endl;
		return 0;
	}
	else
	{
		return this->ary[index];
	}	
}

template <typename T>
T MyArray<T>::getSize()
{
	return this->size;
}

template <typename T>
T* MyArray<T>::getAry(void)
{
	return this->ary;
}