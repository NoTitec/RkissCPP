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

class Player
{
public:
    void Move() { cout << "Move Player!" << endl; }
    //void Move(int a) { cout << "Mover Player int" << endl; }
    virtual void VMove() { cout << "Move Player!" << endl; }//부모에서 virtual지정하는순간 그 하위 모든 클래스에서도 virtual이다
public:
    int _hp;
};

class Knight :public Player
{
public:
    void Move() { cout << "Move Knight!" << endl; }
    virtual void VMove() { cout << "Move Knight!" << endl; }
public:
    int _stamina;

};
class Mage : public Player
{

};

void MovePlayer(Player* player) {// 정적 바인딩시 이함수 하나라 자식 클래스도 이거로 호출
    player->VMove();
}

int main()
{
    Player p;
    //p.Move();
    
    Knight k;
    //k.Move();
    MovePlayer(&p);
    //MovePlayer(&k);// 플레이어는 기사다는 거짓이라 오류뜸
    //MoveKnight(&k);
    MovePlayer(&k);// 부모 클래스의 함수를 호출함
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
