// Function_end.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//함수 마무리
// 오버로딩 : 함수이름재사용
// 매개변수 개수가 다르거나 타입이 달라야 한다(순서만 다른것도 포함)

//기본 인자값
//여러 매개변수가 들어가는 함수에 만약 어떤 인자는 입력이 없다면 기본으로 넣어줌
//단 기본 인자값설정한 매개변수뒤에 일반인자는 올수 없다

//스택 오버플로우
//함수 호출시 스택프레임을 생성함 그런데 스택함수의 크기는 정해져 있음
//정리없이 계속 함수를 호출하면 터짐
int factorial(int n) {
    if (n <= 1) {
        return 1; 
    }
    return n * factorial(n - 1);
}
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
