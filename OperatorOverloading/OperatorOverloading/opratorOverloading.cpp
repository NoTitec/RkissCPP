#include <iostream>
using namespace std;

//연산자 오버로딩 위해서는 연산자 함수 정의를 해야함

//1. 맴버함수 2. 전역함수

//경우에 따라 둘중 하나만 지원하는 경우가 있기 때문에 둘다 알고 있어야 한다
//대표적으로 대입인 = 연산자는 전역으로 만들수 없다

//복사 대입 연산자
//대입 연산자중 자기 자신의 참조타입을 인자로 받는것
//:: . .* 이런건 연산자 오버로딩 불가
//모든 연산자가 2개 항이 있는 건 아님 ++,-- 가 대표적
//전위형은 operator++()
//후위형은 operator++(int) 후위형에 int 쓰는건 컴파일러에서 정해진 규칙이다 따로 이유는 없다 그냥 외워야한다
class Position
{

public:
	Position()
	{
		_x = 0;
		_y = 0;
	}
	Position(const Position& arg)//복사 생성자
	{
		_x = arg._x;
		_y = arg._y;
	}

	Position operator+(const Position& arg) //1. 맴버 연산자 함수 , 왼쪽 기준으로 실행되고 왼쪽이 클래스여야 가능
		//왼쪽이 클래스가 아니면 사용이 불가능하다
	{
		Position pos;
		pos._x = _x + arg._x;
		pos._y = _y + arg._y;
		return pos;
	}
	Position operator+(int arg)
	{
		Position pos;
		pos._x = _x + arg;
		pos._y = _y + arg;
		return pos;
	}

	bool operator==(const Position& arg)
	{
		return _x == arg._x && _y == arg._y;
	}
	Position& operator=(int arg)// 자기자신 주소에 별명을 붙여 반환
	{
		_x = arg;
		_y = arg;
		
		//this 는 자기자신의 포인터이다 여기서는 Position* 가된다
		return *this;
	}
	
	//복사 생성자, 복사 대입 연산자는 해당 객체가 복사되길 원하는 특징이 있다
	//복사대입 연산자는 작성안되어있으면 컴파일러가 자동 생성한다(내부에서)
	Position& operator=(const Position& arg)// 자기자신 주소에 별명을 붙여 반환
	{
		_x = arg._x;
		_y = arg._y;

		//this 는 자기자신의 포인터이다 여기서는 Position* 가된다
		return *this;
	}
	Position& operator++()
	{
		_x++;
		_y++;
		return *this;
	}
	Position operator++(int)
	{
		Position ret = *this;
		_x++;
		_y++;
		return ret;
	}
public:
	int _x;
	int _y;
};

//2. 전역 연산자 함수
Position operator+(int a, const Position& b)
{
	Position ret;
	ret._x = b._x + a;
	ret._y = b._y + a;
	return ret;
}
int main()
{
	int a = 1;
	int b=2;

	int c = (a=3);

	Position pos;
	pos._x = 0;
	pos._y = 0;

	Position pos2;
	pos2._x = 1;
	pos2._y = 1;

	Position pos3 = pos + pos2;
	pos3 = pos.operator+(pos2);
	cout << pos3._x;
	Position pos4 = 1 + pos3;
	cout << pos4._x;
	bool issame = (pos3 == pos4);

	Position pos5;
	pos3 = (pos5 = 5);
	cout << issame;

	//=연산자는 pos&를 원하는데 ++연산자는 return 에서 임시객체 pos 를 반환한다, 이를 해결하려면 타입은 다르지만
	//내가받은 임시객체 내용을 수정하지 않겠다는 const를 붙여줘야 통과된다
	//참조값 인자받는 함수는 이렇게 걸리는 경우가 있으므로 가능하면 const를 붙이는편이 좋다
	pos5=pos3++;
	++(++pos3);
	return 0;

}