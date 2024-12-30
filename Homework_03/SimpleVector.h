#pragma once

// 템플릿을 적용하지 않으면, 한가지 타입에 대응하는 SimpleVector만 만들 수 있다.
// 이럴 경우 사용자가 원하는 타입의 갯수마다 새로운 클래스를 정의해주어야 한다.
//
// 

template<typename T>
class SimpleVector
{
private:
	T* data;
	int currentSize;
	int currentCapacity;

public:
	void resize(int newCapacity); // 배열이 가득 찼을 경우 공간을 늘려 재할당하는 함수
	void push_back(const T& value); // 인자로 받은 원소를 배열 맨 뒤에 추가한다. 배열이 가득 찼을 경우, resize() 함수를 이용해 크기를 5만큼 늘려 추가해준다.
	void pop_back(); // 배열의 마지막 원소를 제거한다. 만약 제거할 원소가 없다면 아무 동작도 하지 않는다.
	int size() const; // 현재 원소의 개수를 반환한다.
	int capacity(); // 현재 내부 배열의 크기(허용량)를 반환한다.
	void sortData(); // 내부 데이터를 정렬해주는 함수이다.

	T GetData(int idx);

	//연산자 오버로드
public:
	T& operator[](int Idx) const;

public:

	SimpleVector(int capacity = 10)
		: data(nullptr)
		, currentSize(0)
		, currentCapacity(capacity)
	{
		// 생성자에 capacity를 입력해주지 않는다면, 기본 인수로 넣어둔 10만큼 배열 공간을 할당 받음
		data = new T[currentCapacity];
	}

	// 복사생성자
	SimpleVector(const SimpleVector& OtherVector)
		: data(nullptr)
		, currentSize(OtherVector.currentSize)
		, currentCapacity(OtherVector.currentCapacity)
	{
		data = new T[currentCapacity];

		for (int i = 0; i < OtherVector.size(); ++i)
		{
			data[i] = OtherVector[i];
		}
	}

	~SimpleVector()
	{
		// T 타입이 포인터일 경우
		if constexpr (is_pointer<T>::value)
		{
			// 배열 내에 있는 동적할당된 객체 주소를 모두 반환해준다.
			for (int i = 0; i < currentSize; ++i)
			{
				delete data[i];
			}
		}
		
		// data 배열 삭제
		delete data;
	}
};

template<typename T>
inline void SimpleVector<T>::resize(int newCapacity)
{
	// 현재 허용량보다 더 작은 양으로 사이즈를 변경할 경우 함수 종료
	if (newCapacity <= currentCapacity)
		return;

	currentCapacity = newCapacity;
	T* tempData = new T[currentCapacity];

	// 기존 원소를 다시 재할당된 배열에 담아준다.
	for (int i = 0; i < currentSize; ++i)
	{
		tempData[i] = data[i];
	}
	delete data;
	data = tempData;
}

template<typename T>
inline void SimpleVector<T>::push_back(const T& value)
{
	// 배열이 가득 차서 원소를 추가할 수 없을 경우, 배열 허용량을 5늘려 재할당해 원소를 추가해준다.
	if (currentCapacity <= currentSize)
	{
		resize(currentCapacity + 5);
	}
	data[currentSize++] = value;
}

template <typename T>
inline void SimpleVector<T>::pop_back()
{
	// 원소가 없다면, 아무 동작을 하지 않고 함수가 종료됨
	if (currentSize == 0)
		return;

	// T가 포인터인지 아닌지에 따라 다르게 처리
	if constexpr (is_pointer<T>::value)
	{
		// 가장 마지막 원소를 삭제하고, 현재 배열의 원소 개수를 1 차감
		delete data[--currentSize];
	}
	else
	{
		currentSize--;
	}
}

template<typename T>
inline T SimpleVector<T>::GetData(int idx)
{
	// 올바른 인덱스 접근을 보장하기 위해 예외처리
	if (idx < 0 || idx >= currentSize)
	{
		throw out_of_range("Index out of range");
	}
	return data[idx];
}

template<typename T>
inline int SimpleVector<T>::size() const
{
	// 현재 원소의 개수 반환
	return currentSize;
}

template<typename T>
inline int SimpleVector<T>::capacity()
{
	// 현재 내부 배열의 크기 반환
	return currentCapacity;
}

template<typename T>
inline void SimpleVector<T>::sortData()
{
	sort(data, data + currentSize, greater<>());
}

template<typename T>
inline T& SimpleVector<T>::operator[](int Idx) const
{
	// 올바른 인덱스 접근을 보장하기 위해 예외처리
	if (Idx < 0 || Idx >= currentSize)
	{
		throw out_of_range("Index out of range");
	}
	return data[Idx];
}