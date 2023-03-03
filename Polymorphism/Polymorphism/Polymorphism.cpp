// Polymorphism.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

//overloading 함수 중복 정의
//overriding 자식클래스에서 부모클래스 함수 재정의

//바인딩(Binding) :컴파일 시점에 결정
//정적 바인딩 :컴파일 시점에 결정 
//동적 바인딩: 실행 시점에 결정(면접 단골 질문)
//일반함수는 정적 바인딩이 기본사용이다.

//동적 바인딩을 원하면 가상함수를 사용해야 한다.!!!!

//virtual table 생성 정적보다 아주약간 느려짐(virtual table로 이동을 한번 해야하기 때문)

// 순수 가상 함수: 구현없이 인터페이스만 전달
class Player
{
public:
    Player()
    {
        _hp = 100;
    }
public:
    void Move() { cout << "Move Player!" << endl; }
    //void Move(int a) { cout << "Mover Player int" << endl; }
    virtual void VMove() { cout << "Move Player!" << endl; }//부모에서 virtual지정하는순간 그 하위 모든 클래스에서도 virtual이다
    virtual void VDie() { cout << "VDie Player" << endl; }


    //순수 가상 함수(하위 클래스는 무조건 이 함수 재정의해서 써야함
    //이함수가 하나라도 있으면 해당 클래스는 추상클래스가됨
    //추상클래스는 객체화 불가능
    virtual void VAttack() = 0;

public:
    int _hp;
};

class Knight :public Player
{
public:
    Knight()
    {
        _stamina = 100;
    }
public:
    void Move() { cout << "Move Knight!" << endl; }
    virtual void VMove() { cout << "Move Knight!" << endl; }
    virtual void VDie() { cout << "VDie Knight" << endl; }
    virtual void VAttack() { cout << " Attack" << endl; }
public:
    int _stamina;

};
class Mage : public Player
{


public:
    int _mp;
};

// is a 관계에서 부모 포인터를 받아야하는위치에 자식 포인터넣어도 틀린말은 아님
void MovePlayer(Player* player) {// 정적 바인딩시 이함수 하나라 자식 클래스도 이거로 호출
    //player 포인터 타고가면 시작주소는 virtual table 주소
    //이를 타고가서 어떤 virtual 함수 호출해야할지 알아냄
    // 어떤 객체인지 virtual 주소 알아내는가?-> 생성자 선처리 영역에서 지정함
    player->VMove();
    player->VDie();
}

int main()
{
    //Player p;
    //p.Move();
    
    Knight k;// night 클래스를 생성시 player 생성자-> night생성자 순으로 호출된다
    //night 포인터를 쫓아가면 player포인터도 들고있다
    //k.Move();
    //MovePlayer(&p);
    //MovePlayer(&k);// 플레이어는 기사다는 거짓이라 오류뜸
    //MoveKnight(&k);
    MovePlayer(&k);// 부모 클래스의 함수를 호출함
}


