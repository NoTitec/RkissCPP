#include <iostream>
using namespace std;

//������ �����ε� ���ؼ��� ������ �Լ� ���Ǹ� �ؾ���

//1. �ɹ��Լ� 2. �����Լ�

//��쿡 ���� ���� �ϳ��� �����ϴ� ��찡 �ֱ� ������ �Ѵ� �˰� �־�� �Ѵ�
//��ǥ������ ������ = �����ڴ� �������� ����� ����

//���� ���� ������
//���� �������� �ڱ� �ڽ��� ����Ÿ���� ���ڷ� �޴°�
//:: . .* �̷��� ������ �����ε� �Ұ�
//��� �����ڰ� 2�� ���� �ִ� �� �ƴ� ++,-- �� ��ǥ��
//�������� operator++()
//�������� operator++(int) �������� int ���°� �����Ϸ����� ������ ��Ģ�̴� ���� ������ ���� �׳� �ܿ����Ѵ�
class Position
{

public:
	Position()
	{
		_x = 0;
		_y = 0;
	}
	Position(const Position& arg)//���� ������
	{
		_x = arg._x;
		_y = arg._y;
	}

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
	Position& operator=(int arg)// �ڱ��ڽ� �ּҿ� ������ �ٿ� ��ȯ
	{
		_x = arg;
		_y = arg;
		
		//this �� �ڱ��ڽ��� �������̴� ���⼭�� Position* ���ȴ�
		return *this;
	}
	
	//���� ������, ���� ���� �����ڴ� �ش� ��ü�� ����Ǳ� ���ϴ� Ư¡�� �ִ�
	//������� �����ڴ� �ۼ��ȵǾ������� �����Ϸ��� �ڵ� �����Ѵ�(���ο���)
	Position& operator=(const Position& arg)// �ڱ��ڽ� �ּҿ� ������ �ٿ� ��ȯ
	{
		_x = arg._x;
		_y = arg._y;

		//this �� �ڱ��ڽ��� �������̴� ���⼭�� Position* ���ȴ�
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

	//=�����ڴ� pos&�� ���ϴµ� ++�����ڴ� return ���� �ӽð�ü pos �� ��ȯ�Ѵ�, �̸� �ذ��Ϸ��� Ÿ���� �ٸ�����
	//�������� �ӽð�ü ������ �������� �ʰڴٴ� const�� �ٿ���� ����ȴ�
	//������ ���ڹ޴� �Լ��� �̷��� �ɸ��� ��찡 �����Ƿ� �����ϸ� const�� ���̴����� ����
	pos5=pos3++;
	++(++pos3);
	return 0;

}