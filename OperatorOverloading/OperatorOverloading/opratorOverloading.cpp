#include <iostream>
using namespace std;

//������ �����ε� ���ؼ��� ������ �Լ� ���Ǹ� �ؾ���

//1. �ɹ��Լ� 2. �����Լ�

//��쿡 ���� ���� �ϳ��� �����ϴ� ��찡 �ֱ� ������ �Ѵ� �˰� �־�� �Ѵ�
//��ǥ������ ������ = �����ڴ� �������� ����� ����

class Position
{

public:
	Position operator+(const Position& arg) //1. �ɹ� ������ �Լ� , ���� �������� ����ǰ� ������ Ŭ�������� ����
		//������ Ŭ������ �ƴϸ� ����� �Ұ����ϴ�
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

//2. ���� ������ �Լ�
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