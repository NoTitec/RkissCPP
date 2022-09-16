// BoolandDecimal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//bool 은 참/거짓만 가지고 있다
bool isHighLevel = true;
bool isPlayer = true;
bool isMale = false;

//true,false 로 사용하지만 사실 1바이트 정수이다
//어셈블리에서 bool은 없다
// bool 자료형만 봐도 참/거짓중 하나임을 알수있는 가독성을 제공한다
// bool 을 1비트가 아닌 1바이트를 사용하는 것은 컴퓨터 레지스터에서 최소 단위가 1바이트이기때문이다
//실수(부동소수점)

float attackSpeed = 0.639f;
double attackSpeed2 = 123.4123;
//float 는 4바이트 double 은 8바이트
//실수 표현에는 부동소수점을 사용한다 
// . 을 유동적으로 움직여서 표현하는 방법
//정규화 이용 기준은 0.xxxxxxxx
//(유효숫자)*(지수)
//float 부호1 지수 8 유효숫자 23 =32 비트
//double 부호1 지수 11 유효숫자 52 = 64비트

//ex) -3.375
// 3+0.375 = 0b11+0b0.011
//정규화 : 0b1.xxxx가 정규화 형태 따라서 부호 1 , 지수 2*1이므로 1, 유효숫자 1011(앞에서부터 채우고 나머지 오른쪽수들은 0으로 놓는다)
//단 지수는 unsighned 가정하고 +127 만들어줌

//단 부동소수점은 근사값임을 기억해야 한다
// 실수 2개 ==비교는 지양

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
