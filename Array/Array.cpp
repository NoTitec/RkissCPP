
#include <iostream>
using namespace std;

struct StatInfo
{
    int hp=0xAAAAAAAA;
    int attack=0xAAAAAAAA;
    int defence=0xAAAAAAAA;
};
int main()
{
    StatInfo monster;
    //yype 이름 개수;

    StatInfo monsters[10];//배열은 상수값으로 크기 지정해야함

    const int monsterCount = 10;//const 빠지면 에러 남
    StatInfo monsters2[monsterCount];

    //배열 이름은 변수이름과는 다른다

    auto who = monsters;//R value 추론해서 l value 만듬

    //배열의 이름은 배열의 시작 포인터이다 type * 배열이름
    StatInfo* monster_0 = monsters;
    monster_0->hp=100;
    monster_0->attack = 10;
    monster_0->defence = 1;

    StatInfo* monster_1=monsters + 1; // 다음 monster로 이동

    //포인터 참조는 자유자재 변환 가능

    StatInfo& monster_2 = *(monsters + 2);//monsters+2 포인터로 가서 실제 StatInfo데이터에 monster_2 라는 이름을 붙임
    monster_2.hp = 300;

    //주의 이건 완전 다른 의미
    StatInfo temp = *(monsters + 2); //temp에  monsters+2 포인터위치 내용 복사
    temp.hp = 300;

    // 모든 몬스터 세팅
    for (int i = 0; i < 10; i++) {
        StatInfo& monster = *(monsters + i);
        monster.hp = 100;
        monster.attack = 10;
        monster.defence = 1;
    }
    monsters[0].hp = 100;
    //근데 *(monsters+i) 불편함
    //그래서 인덱스있음 *(monsters+i)=monsters[i]

    //배열 초기화 문법
    int numbers[5];
    int numbers2[5] = {};//0으로 초기화
    int numbers3[10] = {1,2,3,4,5};//지정된것만 만듬

    int numbers4[] = { 1,2,3,4,5,6,7,8,9 };//데이터 개수만큼 만들음

}

