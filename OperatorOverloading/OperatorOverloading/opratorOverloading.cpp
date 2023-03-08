#include <iostream>
using namespace std;

//연산자 오버로딩 위해서는 연산자 함수 정의를 해야함

//1. 맴버함수 2. 전역함수

//경우에 따라 둘중 하나만 지원하는 경우가 있기 때문에 둘다 알고 있어야 한다
//대표적으로 대입인 = 연산자는 전역으로 만들수 없다

class Position
{

public:
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

	int c = a + 3.0f;

	Position pos;
	pos._x = 0;
	pos._y = 0;

	Position pos2;
	pos2._x = 1;
	pos2._y = 1;

	Position pos3 = pos + pos2;
	pos3 = pos.operator+(pos2);

	Position pos4 = 1 + pos3;

	bool issame = (pos3 == pos4);

	cout << issame;
	return 0;

}