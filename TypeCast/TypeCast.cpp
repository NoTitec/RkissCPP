﻿// TypeCast.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class Knight
{
public:
    int _hp = 10;
};

class Dog
{
public:
    //타입 변환 생성자
    Dog(const Knight& knight)
    {
        _age = knight._hp;
    }
public:
    int _age = 1;
    int _cuteness = 2;
};
int main()
{
    //값 타입 변환
    //cast시 의미를 유지하기 위해 원본 비트열과 다른 비트열로 재구성
    {
        int a = 123456789;//2의보수
        float b = (float)a;//부동소수점(지수+유효숫자)
        cout << b << endl;
    }
    //참조 타입변환
    //cast시 원본 비트열을 유지하면서 해석방법만 바꿈
    //거의 쓸일 없지만, 포인터 타입변환도 참조타입변환과 동일
    {
        int a = 123456789;
        float b = (float&)a;
        cout << b << endl;
    }
    
    //안전한 변환

    //1 안전변환
    // 의미가 항상 일치하는 경우
    // 같은 타입이면서 크기만 더 큰 바구니 이동(업캐스팅)
    // ex) char->short->int->__int64

    //2 불안전변환
    //의미가 항상 일치한다고 보장할 수 없는 경우
    //타입 다르거나 더 작은 바구니 이동(다운캐스팅)
    //ex) int->short, int->float->short


    //프로그래머 의도로 분류
    //1 암시적
    //알려진 타입 변환 규칙으로 컴파일러 자동 변환
    {
        int a = 123456789;
        float b = a;
    }

    //2 명시적
    {
        int a = 123456789;
        int* b = (int*)a; //명시적
    }

    //아무런 관계없는 클래스간 변환

    //1 연관없는 클래스간 값타입 변환
    {
        //일반적으로 안됨(타입 변환 생성자,연산자 필요)
        Knight knight;
        Dog dog = (Dog)knight;
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
