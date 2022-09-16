// MultiPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void SetNumber(int* a)
{
    *a = 1;
}
void SetMessage(const char* a) {//a는 msg주소임
    a = "bye";//a의 주소를 .read 어딘가 생성된 Bye의 주소로 수정함 원본인 Hello가 바뀐것이 아님

    //*a = 'b';
    //*(a + 1) = 'y';// a[1];
}

void SetMessage(const char** a) {//a는 주소를 받고 그 a로 가면 다시 주소바구니있으며 그걸 다시 따라가면 const char이 있다

    *a = "bye";
}

void SetMessage2(const char*& a) {//참조인자인 함수에 변수이름넣으면 해당변수의 주소를 넘김
    a = "bye";
}
int main()
{
    int a = 0;
    SetNumber(&a);

    const char* msg = "Hello";//실제로는 char 배열임 "Hello주소를 msg가 저장함
    SetMessage(msg);//msg 주소를 넘김
    //cout << msg << endl;

    const char** pp=&msg;// pp는 주소담는 바구니 주소타고가면 또 주소담는 바구니 있음
    //이걸 다시 타고 가면 const char이 있음
    //msg[Hello주소]
    //pp[&msg]
    //매개변수/리턴/지역변수 msg(Hello주소) 매개변수a(&msg msg의 주소 ret 지역변수)
    SetMessage(pp);
    *pp = "bye";//pp는 msg의 주소를 가짐 *pp를 하면 msg가 가르키는 원본을 나타냄
    cout << msg << endl;

    SetMessage2(msg);

}//2차포인터이상은 뭔가 코드 잘못짜놨을 가능성 높음

//양파까기와 비슷 const char **라면 이녀석은 const char *원본자료를 취급하는 것



