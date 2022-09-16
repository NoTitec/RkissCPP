// PointerCaculation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//주소 연산자
//산술 연산자
//간접 연산자
//간접 멥버 연산자

struct Player
{
    int hp; //주소 +0
    int damage; //주소+4

};
//어셈블리에서 ptr [주소] 는 주소의 값을 꺼내오라는 의미
int main()
{
    int number = 1;

    int* pointer = &number;

    
    //& 는 해당 변수 타입에따라 type*반환!!!!!!!!

    //산술 연산자
    //배열에서 사용
    number += 1;//값을 증가시킴
    //int *
    //*는 포인터라는것
    //int 는 주소따라가면 4바이트 크기 바구니가 있다
    pointer += 1;// 4가 증가한다 int *이므로 int크기인 4바이트 증가
    //한번에 type크기만큼을 이동하라는 뜻

    //간접 연산자
    *pointer = 3;// 포인터바구니의 주소로 이동하여 3을 넣어라
    
    //간접 멥버 연산자
    Player player;
    player.hp = 100;
    player.damage = 10;

    Player* playerPtr = &player;//player의 주소를 Player* 반환하고 그걸 playerPtr에 저장
    (*playerPtr).hp = 200;
    (*playerPtr).damage = 100;
    
    playerPtr->hp = 300;
    playerPtr->damage = 400;
}

