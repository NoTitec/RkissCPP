// FunctionBasic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//함수
/*
입력으로 무엇받고 ,출력 무엇 받을지 정해준다

반환타입 함수이름(인자타입 매개변수)
{
    함수 내용
    return ----
}
*/

void PrintHelloWorld() {
    cout << "Hello World" << endl;
    return;//함수는 return 만날시 함수 밖으로 빠져나감
}
void PrintNumber(int inputnumber) {
    cout << "inputnumber is" << inputnumber << endl;
}
int MulNumber(int inputnumber) {
    return 2 * inputnumber;
}
int MultwoNumber(int one, int two) {
    return one * two;
}
//디버깅
//F5 디버깅 실행하여 브레이크포인트까지 실행 후 정지
// 
//F10
// 함수단위로 실행한다 함수가 있는 줄을 만나면 함수에 들어가지않고 결과만 확인하고 다음줄로 넘어간다
// 
//  
//F11
// 함수 내부로 들어간다 함수 만나면 함수 내부로 들어가 진행한다
//
//스택 프레임
// 메모리에 코드영역- 전역,정적변수영역- 힙영역 -스택영역이 있다
// 스택은 높은주소에서 낮은주소로 생김 스택은 운영체제가 할당해줌
// 함수에서의 스택은 매개변수 ,반환 주소값 ,지역변수를 가진다
// 매개변수는 input을 반환 주소값은 함수호출종료후 돌아갈 주소를 가진다
//


int main()
{
    int a = 3;
    int b = 5;
    int multworesult = MultwoNumber(b,a);
    PrintNumber(multworesult);
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
