template <typename T>
class MyArray
{
private:
	T *ary;
	int size;
public:
	MyArray()	{ ary=0; size=0; } //디폴트 생성자
	MyArray(int s);	//오버로디드 생성자
	MyArray(const MyArray &br);	//복사 생성자
	~MyArray() { delete [] ary; }	//소멸자
	MyArray &operator=(const MyArray &br);	//대엽연산자
	void put(int index, T val);	//val의 값을 index방에 저장
	T get(int index);	//배열요소 중 index방의 값을 리턴
	T getSize();	//배열요소의 개수 확인
	T* getAry(void);	//배열요소의 내용 확인
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
		cout << "존재하지 않습니다" << endl;
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
		cout << "존재하지 않습니다" << endl;
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