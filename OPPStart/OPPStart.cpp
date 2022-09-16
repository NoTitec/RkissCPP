
//shift 누른상태로 선택시 여러개 선택 ,파일삭제시 제거말고 삭제를 눌러야 완전히 삭제됨

#include <iostream>
using namespace std;

//객체지향 프로그래밍
//절차지향(procedural)=함수 프로그래밍

//프로그래밍은 어떤 데이터에 로직을 가하는것
//모든게 함수면 작은 프로그래밍은 상관없지만 규모가 큰  프로그램의 경우 실행 순서가 다를 수 있다

//c++자체는 객체지향 언어라하기에는 애매함 사용자에게 달림
//게임분야는 객체지향 프로그래밍을 많이 이용함

//1.객체지향의 시작

//데이터+가공(로직,동작)

//객체지향에서는 객체가 중요!!!!!
// 함수들이 어떤 객체들에 소속되어 있음
//객체는 게임상의 모든 오브젝트 하나하나를 의미한다고 생각하면된다
//눈에 보이는것도 포함되고 게임방처럼 보이지 않는 것도 포함된다

//Knight를 설계해보자
// 속성(데이터) 
// hp,attack,y,x
// 
// 기능(동작)
// Move,Attack,Die

class Knight //class는 설계도이다 struct 와 유사(C++은 struct와 class는 거의 동일함)
{
public:

    //2.생성자와 소멸자( 반환 타입이 없음)
    //클래스에 소속된 함수중 시작과 끝을 알리는 함수들
    //클래스는 라이프사이클이 시작-> ...-> 끝 인데 이를 생성자와 소멸자로 관리
    //1) 기본 생성자 (인자없음)
    Knight()
    {
        cout << "Knight()기본생성자 호출" << endl;
        //객체생성시 무조건 실행되어야하는부분
    }

    
    //2) 복사 생성자 (생성자이긴한데 자기자신 참조타입을 인자로 받음)
    // 어떤 객체가 만들어져있는데 그것과 똑같은 다른 객체가 필요한 경우 사용
    //기본 복사생성자도 컴파일러가 만들어줌
    //나중에 동적할당에서 기본 복사생성자말고 다른게 필요

    Knight(const Knight& knight)//복사에만 사용하므로 const가 거의 무조건 붙음
    {
        _hp = knight._hp;
        _attack = knight._attack;
        _posY = knight._posY;
        _posX = knight._posX;
    }
    //3) 기타 생성자

    //나는 이생성자는 명시적으로만 사용할 것 이다
    explicit Knight(int hp)//인자 1개인 생성자는 특별히 타입변환 생성자라고 한다
    {
        _hp = hp;
        cout << "Knight hp 인자로 받음" << endl;

    }
    Knight(int hp,int attack,int y,int x)
    {
        _hp = hp;
        _attack = attack;
        _posY = y;
        _posX = x;
        

    }
    ~Knight()// 소멸자( 소멸자는 오직 1개만 존재가능
    {
        cout << "Knight() 소멸자 호출" << endl;
        //객체 없애기전 정리할 부분
    }

    //맴버 함수 (변수로 만들어도 함수는 메모리에 올라가진 않는다
    //게임업계는 일반적으로 함수는 대문자로 시작!!!!!!!!!!!
    void Move(int y, int x);
    void Attack();
    void Die()
    {
        this;//객체 자기자신을 나타내는 포인터
        //this->_hp=1;
        _hp = 0;// class내의 inline 함수정의시는 맴버변수 사용 가능하다
        cout << "Die" << endl;
    }
public:
    //맴버 변수
    int _hp;//mHp , m_hp 정도의 맴버변수 스타일이 있다!!!!!!!!!!!!!!!!!!!!
    int _attack;
    int _posY;
    int _posX;

};

void Move(Knight* knight, int y, int x)// 객체지향아닌 경우 어떤 Knight인지 포인터로 받아야함
{
    knight->_posY = y;
    knight->_posX = x;
    cout << "Move" << endl;
}

void Knight::Move(int y, int x) {
    _posY = y;
    _posX = x;
    cout << "Move" << endl;

}

void Knight::Attack()
{
    cout << "Attack" << _attack << endl;
}

Knight k1;//전역변수

//instantiate 객체만든다

void HelloNight(Knight k) {// 타입변환 생성자의 암시적 문제 확인용 함수
    cout << "Hellonight" << endl;
}

int main()
{
    Knight k2;//지역변수 //객체 생성 순간에 생성자 호출
    //Knight의 기본생성자 정의 안되어있으면 컴파일러가 자동으로 암시적으로 만든 생성자를
    //호출해준다
    //그러나 1개라도 명시적 생성자가 있을경우 기본생성자는 더이상 자동생성이 안된다

    k2._hp = 80;
    k2._attack = 5;
    k2._posY = 1;
    k2._posX = 1;

    //Move(&k1, 2, 2);//일반함수

    Knight kd(k1);//복사생성자
    Knight k3 = k1;// 이것도 생성을 복사생성자로 만듬

    Knight k4;
    k4 = k1;// k4는 기본생성자 생성되고 k1이 복사됨

    k1.Move(2, 2);//k1 자기자신의 주소를 간접적으로 move함수에 넘겨준다
    k1.Attack();
    k1.Die();

    //암시적 형변환-> 컴파일러가 알아서 바꿈
    int num = 1;
    float f = num;// 굳이 표현 안해도 알아서 바꿔줌

    double d = num;//암시적 변환

    //편하지만 많은 버그를 일으키는 경우도 있음

    Knight k5;
    k5 = (Knight)1;// 명시적 타입변환 생성자 호출
    HelloNight((Knight)1);

    //k5 = 1;// 인자 1개 들어오는경우 타입변환을 일으키며 생성함

    //HelloNight(5);// Knight가 아닌데 실행이 됨-> 문제
}

