// CharandString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//char 도 정수지만 ,문자라는 의미를 나타내기 위해 사용한다

// char 은 문자,숫자
// wchar_t : 유니코드 문자

//아스키코드이용
// char은 그냥 숫자를 넣거나 'a'를 이용해 a에 해당하는 아스키 코드값을 저장한다

char ch3 = 'a' + 1;

//전세계 문자를 표현하기위해선 2바이트 짜리 유니코드를 이용해야 한다
//유니코드는 표기 방식이 여러가지 있는데 UTF-8 과 UTF-16을 이용한다
//8 은 알파벳이나 숫자는 1바이트, 유럽지역 문자는 2바이트, 한글이나 한자는 3바이트를 이용한다
//16은 거의 대부분 2바이트를 이용하고 아주 예외적인 고대 문자만 4바이트를 이용한다

wchar_t wch = L'안';// utf-16 이다 0x0000
wchar_t special = L'\'';
//그러나 cout은 char전용 이므로 wcout을 이용해야하고
//거기에 한국어라면 wcout에게 문자가 한국어임을

//Escape Sequence
//표기 애매한 문자 표현
//\t = tab
//\n = 한줄 건너뛰기
//\r = 커서
//\'

//문자열
//문자배열인데 마지막은 항상 \00이 있어서 이부분은 마지막이라고 판단한다
//끝은 NULL이다

int main()
{
    cout << "Hello World!\n";
    char str[] = { 'h','e' ,'\0'};//\0 명시 필요
    char str2[] = "He";//자동으로 마지막에 \0이 들어감

    wcout.imbue(locale("kor"));
    wcout << wch << "\n";
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
