// FunctionCallStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//함수 선언
void fun1();
void fun2(int , int );// 변수 이름은 선언시에는 안써도 컴파일은 되지만 이름이 보통 의미가있어서 쓰는 경우도 많다 이름이 달라도 된다
void fun3();
//함수 호출 스택
//컴파일시 순차적으로 하나식 분석함
//따라서 fun1 에서 fun2을 부르려할때 fun2는 존재하지 않는 상태
//C++은 함수 이름을 최상단에 모두 선언해야함(함수 선언)

void fun1() {
    //push 2
    //push 1
    //call fun2

    fun2(1,2);
    fun3();
}
void fun2(int a,int b) {
    fun3();
}
void fun3() {

}
int main()
{
    std::cout << "Hello World!\n";
    fun1();
}
//험수에서 함수를 계속 호출하면 어디서부터 왔는지 추적이 어려움
// 대부분의 디버거는 call stack을 제공함 스택프레임의 리턴주소를 그려주는것
// 
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
