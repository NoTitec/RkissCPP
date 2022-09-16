// Pointer_Practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct StatInfo
{
    int hp;
    int attack;
    int defence;
};

//로비 입장하는 함수
void EnterLobby();
//플레이어를 만들어 반환하는 함수
StatInfo CreatePlayer();
//이미 만들어진 몬스터 틀에 접근하여 정보를 변경하는 함수
void CreateMonster(StatInfo* info);
//전투를 시작하는 함수
bool StartBattle(StatInfo* player, StatInfo* monster);

int main()
{
    EnterLobby();
}
void EnterLobby()
{
    cout << "로비에 입장했습니다" << endl;

    StatInfo player;
    player.hp = 0xbbbbbbbb;
    player.attack = 0xbbbbbbbb;
    player.defence = 0xbbbbbbbb;
    player=CreatePlayer();// 유저 생성 복사가 여러번 일어난다
    //매개변수,RET,지역변수 temp,player | 매개변수 &temp RET, 지역변수 ret
    /*
    player=CreatePlayer(); 컴파일러는 이 한문장을 실제로는 아래 두문장처럼
    처리한다

    StatInfo temp = CreatePlayer();
    player = temp;
    */
    StatInfo monster;
    monster.hp = 0xaaaaaaaa;
    monster.attack = 0xaaaaaaaa;
    monster.defence = 0xaaaaaaaa;
    //매개변수,RET,지역변수 monster | 매개변수 &monster RET, 지역변수 
    CreateMonster(&monster);//몬스터 생성
    
    //번외
    //구조체끼리 복사할때 어떤일?
    //player = monster;//어셈블러 언어는 구조체 변수 하나하나를 복사한다

   bool victory= StartBattle(&player,&monster);

   if (victory)
       cout << "victory" << endl;
   else {
       cout << "loose" << endl;
   }
}

StatInfo CreatePlayer()//함수 내에서 만들어 바깥에 리턴
{
    StatInfo ret;
    cout << "create player" << endl;

    ret.hp = 100;
    ret.attack = 10;
    ret.defence = 2;

    return ret;
}
void CreateMonster(StatInfo* info)//바깥에서 주소로 접근해 직접 수정
{
    (*info).hp = 40;
    info->attack = 8;
    info->defence = 1;
}

bool StartBattle(StatInfo* player, StatInfo* monster)
{
    while (true) {
        //유저의 공격
        int damage = player->attack - monster->defence;
        if (damage < 0)
            damage = 0;

        monster->hp -= damage;
        if (monster->hp < 0)
            monster->hp = 0;

        cout << "monster hp" << monster->hp << endl;

        if (monster->hp == 0) {
            return true;
        }
        //몬스터의 공격
        damage = monster->attack - player->defence;
        if (damage < 0)
            damage = 0;
        player->hp -= damage;
        if (player->hp < 0)
            player->hp = 0;

        cout << "player hp" << player->hp << endl;
        if (player->hp == 0) {
            return false;
        }
    }
    
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
