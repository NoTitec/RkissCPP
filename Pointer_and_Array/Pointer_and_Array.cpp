// Pointer_and_Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    char msg[] = { 'H','\0' };

    //문자열 =문자 배열 const char msg[]이다

    
    const char* test1 = "Hello World";//test1 은 문자열의 시작주소를 가짐
    //hello world 는 data영역 어딘가에 있음

    char test2[] = "Hello World";// 문자열을 컴퓨터 워드 단위만큼 
    //레지스터 복사한뒤 test2에 복사함 위 문자열은 12 바이트이므로
    //4바이트씩 복사하여 붙여넣기 해줌

    //포인터는 주소를 담는 바구니!!1
    //배열은 닭장 그 자체 , 같은 데이터끼리 붙어있는 바구니 모음 데이터자체가 test2에 있음!!!!!
    // 
    //배열이름은 시작주소이다!!!!
    //배열을 함수의 인자로 넘기게 되면?

    //기본자료형을 인자로 넘기면 함수에 복사해서 사용하므로 함수 외부 원본에 영향 못미침
    //배열을 인자로 넘길경우 배열의 시작주소만 넘긴다!!!!!!!!!!!
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
