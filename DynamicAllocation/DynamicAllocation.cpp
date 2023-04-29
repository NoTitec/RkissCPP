// DynamicAllocation.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

//동적할당: 매우 중요!!1

//메모리 구조
//코드영역, 데이터 영역, 스택 영역, 힙 영역

//전역,정적 변수는 데이터 영역, 지역 변수, 매개 변수는 스택 영역

//동적 할당-> 힙 영역
//예시
// 게임에 동시접속자가 1~5만명으로 차이가 큼, 몬스터 1마리~500만마리

//스택 영역
// 함수가 끝나면 같이 소멸됨
//메모리 영역
// 프로그램이 실행되는 도중에는 무조건 사용되는 메모리

//희망사항
//필요시에만 사용하고 필요없으면 반납
// 생성/소멸시점을 관리할 수 있는 메모리
// 그것이 힙메모리임
// 동적할당과 관련된 함수/연산자: malloc,free,new,delete,new[],delete[]

//malloc
//원하는 메모리 크기 넘기면 메모리 할당후 시작 주소 가르키는 포인터를 반환한다( 메모리가 부족하면 null 을 반환한다)
//free
//malloc 또는 calloc,realloc등으로 할당 영역을 해제
// 힙 관리자가 할당/미할당 여부 구분해서 관리
//C++에서는 이게 더 중요
// new / delete
// malloc/free는 함수
// new / delete는 연산자
//new가 malloc에 비해 좋긴 한데 배열처럼 여러개 만들려면 new[] delete[] 필요
//가장 큰 차이
// new/delete 는 클래스 생성시 생성자/소멸자를 자동호출 해준다!!!!!!!!

class Monster
{
public:
    int _hp;
    int _x;
    int _y;
};

int main()
{
    //Monster monster[100 * 10000];// 스택이 초과된다 스택은 함수들끼리 인자전달받는 용도로 쓰기때문에 이렇게 큰 공간할당은 안된다
    //전역변수로 하면 되긴 하지만 메모리 낭비가 너무 심해진다

    //유저영역 (애플리케이션 실행)
    // 유저영역의 각 애플리케이션의 메모리는 커널이 관리함
    //커널영역( os 핵심코드 실행)

    //유저영역에서 운영체제가 제공하는 api 함수를 호출하여 메모리 할당을 요청해서 건내줌
    // 넘겨줄 메모리를 크게 만들어놓고 요청이 올때 이걸 나누어서 분배하는 방식을 사용함
    // C++은 CRT(C RunTime Library) 의 힙 관리자로 힙 영역 사용
    // 단 , 정말 원하몉ㄴ 직접 api로 힙 생성하고 관리할 수있음(고급 기술)

//#ifdef _WIN64 // 64 비트 실행환경인지 아닌지에따라 갈림
//    typedef unsigned __int64 size_t;
//    typedef __int64          ptrdiff_t;
//    typedef __int64          intptr_t;
//#else
//    typedef unsigned int     size_t;
//    typedef int              ptrdiff_t;
//    typedef int              intptr_t;
//#endif
//
//    typedef int ossize;// int 타입 변수를 ossize라는 이름으로도 사용 할 수 있도록 정의하는 문법
    
    //void 형 포인터
    // 주소를 타고가면 뭐가 있는지 모르므로 적당히 변환해서 사용하라
    void* pointer = malloc(sizeof(Monster));// 정확히 sizeof 아닌 그 이전에 메모리크기에대한 헤더정보도 저장하고있어 free호출시 해당 해더 크기만큼의 메모리를 해제시킨다
    //heap overflow : 만약 변환 자료형보다 작은 메모리 범위에 초과해서 힙을 쓰려고하면 프로그램이 죽는다

    Monster* m1 = (Monster*)pointer;
    m1->_hp = 100;
    m1->_x = 1;
    m1->_y = 2;
    free(pointer);
    pointer = nullptr;
    m1 = nullptr;
    //free 를 하지않을시 메모리가 계속 누수된다-> 지속시 한계에 도달해 죽는다
    //free 를 2번이상 실행하려 할시 free시킬 크기가 저장된 공간도 밀려있기때문에 오류가 발생한다
    //use-after-free C++언어에서 가장 심각한 문제
    //- 프로그래머 입장: 심각한 문제, 해커입장: 프로그램 제어 권한 탈취
    //m1->_hp = 100;
    //m1->_x = 1;
    //m1->_y = 2;
    //위의 문장이 이미 pointer 를 free했지만 건드리는것이 허용됨 즉시 문제가 일어나지 않으면 메모리가 오염되다가 나중에 터질 수 있음

    Monster* m2 = new Monster;
    m2->_hp = 100;
    m2->_x = 1;
    m2->_y = 2;

    delete m2;

    Monster* m3 = new Monster[5];
    m3->_hp = 200;
    m3->_x = 2;
    m3->_y = 3;

    Monster* m4 = (m3 + 1);
    delete[] m3;
}