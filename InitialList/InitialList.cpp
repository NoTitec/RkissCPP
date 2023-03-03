// InitialList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//버그예방이나 포인터 주소값이 연관되어 있는 경우

//초기화 방법
//1.생성자 내부에서 2. 초기화 리스트 3.C++11 문법(선언부에 초기값 지정)
//상속 고나계에서 원하는 부모 생성자 호출시 필요하다
//일반 변수는 1이나 2 나 별 차이없지만
//변수가 클래스인 경우 차이가 난다
//참조타입이나 const처럼 정의와 초기화가 동시에 필요한 경우 반드시 초기화 리스트방식 초기화 해야한다
class Inventory
{
public:
    Inventory() { cout << "기본인벤토리호출" << endl; }
    Inventory(int size) {
        cout << "인벤 사이즈버전 호출" << endl;
        _size = size;
    }
    ~Inventory() { cout << "소멸자 호출" << endl; }
public:
    int _size = 10;// 3번 방법
};

class Player
{
public:
    Player(){}
    Player(int id){}
};
//Is-a (Knight is a player)-> 상속관계
//has-a (Knight has a inventory?)->포함관계 일경우 변수는 리스트방식으로 초기화 해야함
class Knight : public Player
{
public:
    //부모 생성자 여러 버전있는경우 자식생성자에 지정 아무것도안하면 부모의 기본생성자 호출
    //이외는 직접 어떤 버전 부모생성자 호출 할 건지 지정
    Knight() :Player(1),_hp(100),_inventory(10),_hpref(_hp),_hpconst(100)//핵심!
        /*
        선처리 영역*/
        //클래스변수는 생성자에서 초기화 지정해도 기본 생성자가 한번 호출되고나서 지정생성자를 호출하면서 객체가 2개가 생성되고 불필요한 복사 붙여넣기가 실행됨
    {
        _hp = 100;
        //_inventory = Inventory(10); 문제!
    }
public:
    int _hp;
    Inventory _inventory;//Knight 만들어질때 인벤토리가 선처리영역에서 같이 생김 기본적으로는 기본생성자가 호출됨

    int& _hpref; // 이미 존재하는 어떤 것에 별칭 붙이는 것이므로 참조대상이 되는것이 존재해야한다
    const int _hpconst;
};
int main()
{
    Knight k;

    cout << k._hp << endl;


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
