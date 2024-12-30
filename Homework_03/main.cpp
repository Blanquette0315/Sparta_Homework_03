#include "pch.h"
#include "SimpleVector.h"

class Animal
{
public:
	Animal()
	{

	}

	~Animal()
	{

	}
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// SimpleVector ����
	SimpleVector<int> Sim_vec;
	
	// �⺻ �����ڿ��� ũ�Ⱑ 10��ŭ �Ҵ� �Ǿ����� Ȯ��
	cout << "first capacity : " << Sim_vec.capacity() << endl << endl;
	
	// ���� �߰�
	// size�� capacity�� ��� ���ϴ��� ���
	for (int i = 0; i < 12; ++i)
	{
		Sim_vec.push_back(i);
		cout << "size : " << Sim_vec.size() << endl;
		cout << "capacity : " << Sim_vec.capacity() << endl;
	}
	
	// �迭�� ���� ����غ���
	for (int i = 0; i < Sim_vec.size(); ++i)
	{
		cout << Sim_vec[i] << ' ';
	}
	
	cout << endl;
	
	// ������ ���� �����ϰ� ����غ���
	Sim_vec.pop_back();
	for (int i = 0; i < Sim_vec.size(); ++i)
	{
		cout << Sim_vec[i] << ' ';
	}

	cout << endl;

	// resize �Լ� Ȯ���ϱ�
	Sim_vec.resize(2);
	cout << "resize(2)�� ���" << endl;
	cout << "size : " << Sim_vec.size() << endl;
	cout << "capacity : " << Sim_vec.capacity() << endl;

	Sim_vec.resize(20);
	cout << "resize(20)�� ���" << endl;
	cout << "size : " << Sim_vec.size() << endl;
	cout << "capacity : " << Sim_vec.capacity() << endl;
	for (int i = 0; i < Sim_vec.size(); ++i)
	{
		cout << Sim_vec[i] << ' ';
	}
	cout << endl;

	// �����غ���
	Sim_vec.sortData();
	cout << "�������� ������ ���" << endl;
	for (int i = 0; i < Sim_vec.size(); ++i)
	{
		cout << Sim_vec[i] << ' ';
	}
	cout << endl;

	// ��������� Ȯ��
	SimpleVector<int> Sim_vec2(Sim_vec);
	Sim_vec.pop_back();
	Sim_vec.pop_back();
	Sim_vec.pop_back();
	cout << "Sim_vec ���� ������ Sim_vec2 ���" << endl;
	cout << "size : " << Sim_vec2.size() << endl;
	cout << "capacity : " << Sim_vec2.capacity() << endl;
	for (int i = 0; i < Sim_vec2.size(); ++i)
	{
		cout << Sim_vec2[i] << ' ';
	}
	cout << endl;


	// �����͸� ���� SimpleVector ����
	SimpleVector<Animal*> Sim_vec3;
	Sim_vec3.push_back(new Animal);
	Sim_vec3.push_back(new Animal);
	Sim_vec3.push_back(new Animal);
	Sim_vec3.push_back(new Animal);

	cout << "Animal �ּҸ� �����ϴ� Sim_vec3�� 4���� ���Ҹ� �߰��� ���" << endl;
	cout << "size : " << Sim_vec3.size() << endl;
	cout << "capacity : " << Sim_vec3.capacity() << endl;

	Sim_vec3.pop_back();
	cout << "pop_back()�� ���" << endl;
	cout << "size : " << Sim_vec3.size() << endl;
	cout << "capacity : " << Sim_vec3.capacity() << endl;

	return 0;
}