#pragma once

// ���ø��� �������� ������, �Ѱ��� Ÿ�Կ� �����ϴ� SimpleVector�� ���� �� �ִ�.
// �̷� ��� ����ڰ� ���ϴ� Ÿ���� �������� ���ο� Ŭ������ �������־�� �Ѵ�.
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
	void resize(int newCapacity); // �迭�� ���� á�� ��� ������ �÷� ���Ҵ��ϴ� �Լ�
	void push_back(const T& value); // ���ڷ� ���� ���Ҹ� �迭 �� �ڿ� �߰��Ѵ�. �迭�� ���� á�� ���, resize() �Լ��� �̿��� ũ�⸦ 5��ŭ �÷� �߰����ش�.
	void pop_back(); // �迭�� ������ ���Ҹ� �����Ѵ�. ���� ������ ���Ұ� ���ٸ� �ƹ� ���۵� ���� �ʴ´�.
	int size() const; // ���� ������ ������ ��ȯ�Ѵ�.
	int capacity(); // ���� ���� �迭�� ũ��(��뷮)�� ��ȯ�Ѵ�.
	void sortData(); // ���� �����͸� �������ִ� �Լ��̴�.

	T GetData(int idx);

	//������ �����ε�
public:
	T& operator[](int Idx) const;

public:

	SimpleVector(int capacity = 10)
		: data(nullptr)
		, currentSize(0)
		, currentCapacity(capacity)
	{
		// �����ڿ� capacity�� �Է������� �ʴ´ٸ�, �⺻ �μ��� �־�� 10��ŭ �迭 ������ �Ҵ� ����
		data = new T[currentCapacity];
	}

	// ���������
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
		// T Ÿ���� �������� ���
		if constexpr (is_pointer<T>::value)
		{
			// �迭 ���� �ִ� �����Ҵ�� ��ü �ּҸ� ��� ��ȯ���ش�.
			for (int i = 0; i < currentSize; ++i)
			{
				delete data[i];
			}
		}
		
		// data �迭 ����
		delete data;
	}
};

template<typename T>
inline void SimpleVector<T>::resize(int newCapacity)
{
	// ���� ��뷮���� �� ���� ������ ����� ������ ��� �Լ� ����
	if (newCapacity <= currentCapacity)
		return;

	currentCapacity = newCapacity;
	T* tempData = new T[currentCapacity];

	// ���� ���Ҹ� �ٽ� ���Ҵ�� �迭�� ����ش�.
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
	// �迭�� ���� ���� ���Ҹ� �߰��� �� ���� ���, �迭 ��뷮�� 5�÷� ���Ҵ��� ���Ҹ� �߰����ش�.
	if (currentCapacity <= currentSize)
	{
		resize(currentCapacity + 5);
	}
	data[currentSize++] = value;
}

template <typename T>
inline void SimpleVector<T>::pop_back()
{
	// ���Ұ� ���ٸ�, �ƹ� ������ ���� �ʰ� �Լ��� �����
	if (currentSize == 0)
		return;

	// T�� ���������� �ƴ����� ���� �ٸ��� ó��
	if constexpr (is_pointer<T>::value)
	{
		// ���� ������ ���Ҹ� �����ϰ�, ���� �迭�� ���� ������ 1 ����
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
	// �ùٸ� �ε��� ������ �����ϱ� ���� ����ó��
	if (idx < 0 || idx >= currentSize)
	{
		throw out_of_range("Index out of range");
	}
	return data[idx];
}

template<typename T>
inline int SimpleVector<T>::size() const
{
	// ���� ������ ���� ��ȯ
	return currentSize;
}

template<typename T>
inline int SimpleVector<T>::capacity()
{
	// ���� ���� �迭�� ũ�� ��ȯ
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
	// �ùٸ� �ε��� ������ �����ϱ� ���� ����ó��
	if (Idx < 0 || Idx >= currentSize)
	{
		throw out_of_range("Index out of range");
	}
	return data[Idx];
}