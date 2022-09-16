// Inheritance.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
//기사

struct StatInfo
{
public:
	int _hp;
	int _attack;
	int _defence;
};
//메모리
// [Player]
// [Kight]

//생성자(여러개정의가능)와 소멸자(오직 1개)
//Knight 생성시 둘다 호출되는데 생성자는 상속해도 물려주지 않는다
//정확히 말하면 Knight생성자가 먼저 호출되고 Knight생성자 코드를 실행하기전에 Player 생성자를 컴파일러가 호출하여 초기화후 Knight생성자의 코드를 그제서야 넘어가서 실행한다

//Gameobject
//-creature
// --player,monster
//-projectile
// --arrow,fireball
//-Env

//item
//-weapon
//-sword,bow
//-helmet,boots,armor
//-consumable
//--potion,scroll
class GameObject
{
public:
	int _objectid;
};
class Player: public GameObject
{
public:
	Player()
	{
		_hp = 0;
		_attack = 0;
		_defence = 0;
		cout << "Player() 기본 생성자" << endl;
	}
	Player(int hp) {
		_hp = hp;
		_attack = 0;
		_defence = 0;
		cout << "Player() hp 생성자" << endl;
	}
	~Player() {
		cout << "Player소멸자 호출" << endl;
	}
	void Move() {
		cout << "Move 호출" << endl;
	}
	void Attack() {
		cout << "Attack 호출" << endl;
	}
	void Die() {
		cout << "Die 호출" << endl;
	}
public:
	int _hp;
	int _attack;
	int _defence;
};
class Knight : public Player
{
public:
	Knight()
	{
		/*
		선처리 영역은 기본 생성자만 호출
		*/
		_stamina = 100;
		cout << "Kight() 기본 생성자" << endl;
	}
	Knight(int stamina) :Player(100)//  int 인자인 생성자 호출시 부모생성자 int 값받는것 호출
	{
		/*
		선처리 영역 에서 호출되는 부모생성자 지정가능
		*/
		_stamina = stamina;
		cout << "Kight() stamina 생성자" << endl;
	}
	~Knight() 
	{
		//main함수의 스택영역에 있는동안 사용되다 main함수 종료될때 호출되며 Knight 소멸자끝난뒤 자동으로 Player 소멸자도 호출한다
		cout << "Kight소멸자 호출" << endl;
	}
	/*
	 후처리 영역
	 Player의 소멸자 호출 
	 */


	//재정의 가능 하지만 실질적으로 이게 사용될 일이 없음
	void Move() { cout << "Knight Move" << endl; }
public:
	int _stamina;
};

//마법사
class Mage : public Player
{
public:
	int _mp;
};
//상속사용 이유
//기본구조 똑같은 비슷한 클래스 여러개 만들어야 할 경우
int main()
{
	Knight k(100);
	//k._hp = 100;
	//k._attack = 10;
	//k._defence=15;
	//k._stamina = 50;
	//k.Move();
	//k.Player::Move();//재정의 햇지만 부모 함수를 사용하고 싶으면 이렇게
	//k.Attack();
	return 0;
}

