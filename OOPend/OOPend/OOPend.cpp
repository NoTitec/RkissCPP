// OOPend.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

//1) struct 와 class 
// C++에선 한끗차이
//struct 는 기본접근자 public class 는 private
//struct 는 데이터 묶음용도로 쓸때 class 는 객체 지향 용도

/*
* 2) static 변수와 함수
* 
*/
struct TestStruct
{
public:
    int a;
    int b;

};

class TestClass {
private:

    int _1;
    int _b;
};

class Marine //설계도
{
public:
    int hp;
    static int attack;// 모든 Marine 타입이 공유하는 변수

    void TakeDamage(int damage)
    {
        hp -= damage;
    }
    static void Setattack()
    {
        //특정객체와 연관된건 호출 불가 ex) m1,m2 가있을때 뭘 건드려야하는지 모르기 때문

        attack = 100;
    }
};

int Marine::attack = 0; //전역변수 접근후 초기화

class Player
{
public:
    int _id;
};

//정적 전역 객체
static int s_global = 1;
int GenerateId()
{   //생명주기: 프로그램 시작/종료
    //가시범위: 선언된 지역 내부
    //정적 지역 객체
    static int s_id = 1;
    return s_id++;
}
//static 변수도 data영역에 있다
int main()
{
    TestStruct ts;

    ts.a = 1;
    TestClass tc;
    
    Marine::attack = 6;
    Marine m1;
    m1.hp = 35;
    //m1.attack = 6;
    Marine m2;
    m2.hp = 14;
    //m2.attack = 6;

    //마린 공격력 업
    Marine::attack = 7;
    Marine::Setattack();

    //static 변수는 함수 내에서 만들어도 함수 스택공간이 아닌 데이터 영역 어딘가에 잡힌다
    static int id = 10;
    int a = id;
    for (int i = 0; i < 5; i++) {
        cout << GenerateId() << endl;
    }
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
