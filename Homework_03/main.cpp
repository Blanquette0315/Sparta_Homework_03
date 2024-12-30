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

	// SimpleVector 생성
	SimpleVector<int> Sim_vec;
	
	// 기본 생성자에서 크기가 10만큼 할당 되었는지 확인
	cout << "first capacity : " << Sim_vec.capacity() << endl << endl;
	
	// 원소 추가
	// size와 capacity가 어떻게 변하는지 출력
	for (int i = 0; i < 12; ++i)
	{
		Sim_vec.push_back(i);
		cout << "size : " << Sim_vec.size() << endl;
		cout << "capacity : " << Sim_vec.capacity() << endl;
	}
	
	// 배열의 원소 출력해보기
	for (int i = 0; i < Sim_vec.size(); ++i)
	{
		cout << Sim_vec[i] << ' ';
	}
	
	cout << endl;
	
	// 마지막 원소 삭제하고 출력해보기
	Sim_vec.pop_back();
	for (int i = 0; i < Sim_vec.size(); ++i)
	{
		cout << Sim_vec[i] << ' ';
	}

	cout << endl;

	// resize 함수 확인하기
	Sim_vec.resize(2);
	cout << "resize(2)의 결과" << endl;
	cout << "size : " << Sim_vec.size() << endl;
	cout << "capacity : " << Sim_vec.capacity() << endl;

	Sim_vec.resize(20);
	cout << "resize(20)의 결과" << endl;
	cout << "size : " << Sim_vec.size() << endl;
	cout << "capacity : " << Sim_vec.capacity() << endl;
	for (int i = 0; i < Sim_vec.size(); ++i)
	{
		cout << Sim_vec[i] << ' ';
	}
	cout << endl;

	// 정렬해보기
	Sim_vec.sortData();
	cout << "내림차순 정렬의 결과" << endl;
	for (int i = 0; i < Sim_vec.size(); ++i)
	{
		cout << Sim_vec[i] << ' ';
	}
	cout << endl;

	// 복사생성자 확인
	SimpleVector<int> Sim_vec2(Sim_vec);
	Sim_vec.pop_back();
	Sim_vec.pop_back();
	Sim_vec.pop_back();
	cout << "Sim_vec 복사 생성한 Sim_vec2 결과" << endl;
	cout << "size : " << Sim_vec2.size() << endl;
	cout << "capacity : " << Sim_vec2.capacity() << endl;
	for (int i = 0; i < Sim_vec2.size(); ++i)
	{
		cout << Sim_vec2[i] << ' ';
	}
	cout << endl;


	// 포인터를 담을 SimpleVector 생성
	SimpleVector<Animal*> Sim_vec3;
	Sim_vec3.push_back(new Animal);
	Sim_vec3.push_back(new Animal);
	Sim_vec3.push_back(new Animal);
	Sim_vec3.push_back(new Animal);

	cout << "Animal 주소를 관리하는 Sim_vec3에 4개의 원소를 추가한 결과" << endl;
	cout << "size : " << Sim_vec3.size() << endl;
	cout << "capacity : " << Sim_vec3.capacity() << endl;

	Sim_vec3.pop_back();
	cout << "pop_back()의 결과" << endl;
	cout << "size : " << Sim_vec3.size() << endl;
	cout << "capacity : " << Sim_vec3.capacity() << endl;

	return 0;
}