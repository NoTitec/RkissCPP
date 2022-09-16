// Reference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct StatInfo
{
    int hp;
    int attack;
    int defence;
    //각각 정보가 데이터 크기만큼 할당됨
};

//장점: 복사없이 원본 직접 수정 가능
//매개변수,ret,지역변수(info)-> CreateMonster호출시 매개변수에 &info ret 지역변수
void CreateMonster(StatInfo* info)
{
    info->hp = 100;
    info->attack = 8;
    info->defence = 5;

}
//: 포인터방식보다 느리지만 원본수정없이 데이터 접근 가능
//매개변수,ret,지역변수(info)-> CreateMonster호출시 매개변수에 info복사본 ret 지역변수
StatInfo CreateMonster(StatInfo info)//*가 안붙은건 무조건 뭔가 복사된다는 뜻
{
    StatInfo temp;
    temp.hp=info.hp ;
    temp.attack=info.attack ;
    temp.defence=info.defence ;
    return temp;
}

//1) 값 전달 방식은 원본의 복사본은 전달하는 방식
//2) 주소 전달 방식은 원본 자체를 전달하는 방식

//매개변수가되는 구조체가 작다면 어떤것이든 별 문제가 없지만 
//만약 이게 크다면 복사하는데 시간이 오래걸리게 된다

//3) 참조전달
//C++에만 존재함

//특정 조건 만족하는 몬스터 찾는 함수
StatInfo* FindMonster() { //이 함수는 주소를 반환한다 그 주소 따라가면 StatInfo데이터가 있다
    //Heap에서 무언가 찾아봄
    //찾으면 그 주소
    //없으면 return nullptr;
    return nullptr;
}
StatInfo globalInfo;

void PrintInfoByPtr_allconst(const StatInfo*const info) {
    if (info == nullptr)// 인자로 없는 주소들어오면 바로 중단하게해줌
        return;
    //todo
    
}
void PrintInfoByPtr_dataconst(const StatInfo* info) {//info에 주소따라가면있는 원본 수정 불가
    cout << "HP" << info->hp << endl;

    info = &globalInfo;
}
void PrintInfoByPtr_pointerconst(StatInfo*const info) {//info 주소값이 const되어 주소변경 불가
    cout << "HP" << info->hp << endl;

    info->hp = 10000;
}
void PrintInfoByRef_ref_dataconst(const StatInfo& info) {//읽기만 가능 하게 막음, 의도치않은 원본수정 막기 !!!!! 거의 필수
    cout << info.hp << endl;
}
#define OUT //언리얼에서 자주 사용 단순히 힌트 주는 의미 주석같은것
void ChangeInfo( OUT StatInfo& info) {//레퍼런스라 사용시 원본이 바뀔 수있다는 힌트
    info.hp = 1000;
}
int main()
{
    int number = 1;// 4바이트 정수 바구니 를 number이름붙여 사용하겠다
    //그 주소에 1을 넣어라

    //주소담는 바구니있고 그 바구니는 int 데이터가 있다
    //pointer 바구니 주소로 이동해서 거기에 2를 넣어라
    int* pointer = &number;
    *pointer = 2;

    //참조!!!!!!!!!!!!!!!!!!!!
    //사용은 일반처럼 작동방식은 int*와 완전히 똑같다(어셈블리 코드 동일)
    int& reference = number;
    reference = 3;
    //number에 reference라는 다른 이름하나 추가한것
    //여기에 뭘 넣으면 number에다 적용해줘
    // 참조를 사용하는 이유?
    // 기본 포인터에서 맴버 참조시 ->를쓰는데 매우 불편 그래서 .을 간단히
    //사용하기 위해 도입


    StatInfo info;//빈 StatInfo 구조체

    //포인터vs 참조
    // 성능은 완전히 동일함(어셈블리 코드 똑같음)
    // 편의성은 참조가 더 좋음

    //그러나 이것이 꼭 장점만 가진 것은 아님
    //포인터는 주소를 넘기니 확실하게 원본을 넘긴다는 힌트가 있음
    //참조는 원본인지 모르고 지나칠가능성이 있음
    //모르고 원본을 고치는걸 막을 수 있음
    //const로 막기 가능
    //포인터도 const가능
    // * 앞이냐 뒤에냐에따라 의미가 달라짐
    
    //2) 초기화
    // 참조타입은 바구니의 2번째 이름을 지정하는것이라 
    // 선언시 참조하는 대상이 반드시 초기화 되어야한다
    // 포인터는 빈 주소바구니선언뒤 나중에 담기가 가능하지만
    // 참조타입은 불가능하다
    // 
    // 
    // 포인터에서 없다는 의미
    StatInfo* nullpointer = nullptr;//어떠한 주소도 가르키지 않는 상태
    //nullptr은 0이다 게임 죽는 원인 80프로는 nullptr문제
    // 참조타입은 nullptr이 없다 무조건 무언가 가르켜야 하기 때문!!
    PrintInfoByPtr_allconst(nullpointer);// nullptr들어올시 예외처리 있으므로 그냥 건너뜀

    //코드 이름 변경법 이름 선택뒤 ctrl+R+R

    CreateMonster(&info);

    StatInfo* Statpointer;
    Statpointer = &info;
    PrintInfoByPtr_pointerconst(Statpointer);
    //위 3문장은 아래 한문장과 동일
    PrintInfoByPtr_pointerconst(&info);

    StatInfo& Statreference = info;
    PrintInfoByRef_ref_dataconst(Statreference);
    //info의 주소 즉 원본 받음 겉보기는 복사같지만 함수 원형이 다름
    PrintInfoByRef_ref_dataconst(info); //신입이 왔다 info.hp=1000; 원본이 수정됨 const시 수정 막기가능

    //결론
    // Team By Team 정해진 답이 없다
    //구글 오픈소스는 거의 무조건 포인터 사용
    //언리얼 엔진에선 reference도 애용

    //nullptr이 있을 수있는 상황에선 포인터, 확실하게 있는 주소라면 reference사용
    //수정 안되고 읽기만 가능하게 사용할시 const ref&
    //일반적으로 명시적 호출시 OUT붙임
    //단 유지보수시 처음 만들어진것을 이어서 유지보수한다
    //섞어서 쓰지 않는다

    ChangeInfo(OUT info);

    //포인터로쓰던걸 참조로 넘기려면?
    // 포인터는 주소가진 바구니이다 info의 주소를 가짐
    // info에 다른 이름 붙여 넘기면됨
    //참조는 원본데이터에 별칭 붙이는 것이므로 *data로 원본을 참조함수에 인자로 주면된다
    PrintInfoByRef_ref_dataconst(*Statpointer);//참조받는함수에 원본 전달
    //반대는?
    //포인터 받는 함수는 주소 받아야하기때문에 참조타입에 &붙여 주소 넘기면 됨
    PrintInfoByPtr_allconst(&Statreference);

    //* ,& 는 두가지 의미임
    //&는 변수앞이면 주소꺼내달라 타입뒤면 변수가 참조값이다 라는 의미
    //*는 변수앞이면 변수주소로 따라가라 타입뒤면 해당 변수가 포인터이다라는 의미
}

