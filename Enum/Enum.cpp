// Enum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//상수 사용에 const를 사용하기도 하지만 너무 각자 따로 놀 수가있다
//예를 들어 게임의 버프목록을 상수화하고자하면 온갖가지 상태가 존재한다
//이런 상황에 사용하기 위해 enum 열거형을 사용한다
// 열거형은 const와 달리 선언때 반드시 초기화를 하지 않아도 된다, const는 초기화 안할시
//에러가 발생한다 enum 은 기본적으로 지정 안할 시 0으로 지정된다
// 다음 값들은 이전 값의 +1 값을 가진다

//const 는 메모리에 실제로 저장이 되어있을수도 단순히 같은 이름이 사용된부분을 설정값으로
//바꿔치기하는 것도 있다 스택공간에 선언하거나 auto문법으로 주소가 들어가게 할 수가 있기도 하다

//열거형은 100% 바꿔치기하는 방식이다(메모리를 아예 잡지 않는다)
enum ENUM_SRP
{
    ENUM_SISSORS=1,
    ENUM_ROCK,
    ENUM_PAPER
};

#define DEFINE_SISSORS 1 //최대한 지양
//# 이 붙은건 전처리 지시문이다 
//컴파일은 전처리->컴파일-> 링크과정이다
//#include <iostream> 컴파일 가기전 iostream 파일찾아 해당내용 통째로 복붙
//define sissors를 만나면 설정 값으로 바꿔치기된다
// 열거형과 달리 정수가아닌 다른 것들도 가능하다
//그러나 완전 바꿔치기이기때문에 만약 1+2이고 이를 연산하면 *2할시 6이아닌 5가나온다
//전처리 단계에서 사용되고 사라져 추적이 불가하므로 디버깅 단계때 어려울 수 있다

int main()
{
    std::cout << "Hello World!\n";
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
