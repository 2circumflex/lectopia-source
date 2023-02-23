
template <typename T>
class SmartArray : public MyArray<T>
{
private:
	T max;	//최고값 저장
public:
	SmartArray() {}	//디폴트 생성자
	SmartArray(int s) : MyArray<T>(s), max(0)	//오버로디드 생성자
	{}
	void put(int index, T val);	//put함수의 재정의
	T getMax();	//max값 리턴
	bool operator>(const SmartArray<T> &br);	//비교연산자
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