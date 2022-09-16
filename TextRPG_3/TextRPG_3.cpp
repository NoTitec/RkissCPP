
#include <iostream>
using namespace std;

//주제: TextRPG2

//main
//-EnterLobby
//--CreatePlayer
//--EnterGame
//---CreateMonsters
//---EnterBattle

enum PlayerType
{
    PT_Night = 1,
    PT_Arher = 2,
    PT_Mage=3,
};

enum MonsterType
{
    MT_SLime=1,
    MT_Orc=2,
    MT_Skeleton=3,
};

struct StatInfo
{
    int hp = 0;
    int attack = 0;
    int defence = 0;
};

void EnterLobby();
void PrintMessage(const char* msg);
void CreatePlayer(StatInfo * a);//포인터가 인자
void PrintStatInfo(const char* name, const StatInfo& info);//포인터와 참조타입인자
void EnterGame(StatInfo* p);
void CreateMonsters(StatInfo monsterinfo[], int c);
bool EnterBattle(StatInfo* player, StatInfo* monster);
int main()
{
    srand((unsigned)time(nullptr));
    EnterLobby();
}

//로비 진입
void EnterLobby()
{
    while (true)
    {
        PrintMessage("로비 입장");

        //Player
        StatInfo playerInfo;//이변수 주소를 이함수 밖에 꺼내는건 하면 안됨
        CreatePlayer(&playerInfo);
        PrintStatInfo("PlayerStat",playerInfo);
        EnterGame(&playerInfo);
    }
}

void PrintMessage(const char* msg)//인자주는 문자열 출력
{
    cout << "***************" << endl;
    cout << msg << endl;
    cout << "***********" << endl;
}

void CreatePlayer(StatInfo* a)
{
    bool ready = false;
    while (ready==false)
    {
        PrintMessage("캐릭생성");
        PrintMessage("1.기사 2. 궁수 3.법사");
        
        int input;
        cin >> input;
        switch (input)
        {
        case PT_Night:
            a->hp = 100;
            (*a).attack = 10;
            a->defence = 5;
            ready = true;
            break;
            //return;
        case PT_Arher:
            a->hp = 80;
            (*a).attack = 15;
            a->defence = 3;
            ready = true;
            break;
        case PT_Mage:
            a->hp = 50;
            (*a).attack = 25;
            a->defence = 2;
            ready = true;
            break;
        }

    }
}

void PrintStatInfo(const char* name, const StatInfo& info)
{
    cout << "******" << endl;
    cout << name << "HP:" << info.hp << "ATK:" << info.attack << "DEF:" << info.defence << endl;
}

void CreateMonsters(StatInfo monsterinfo[], int c)
{
    for (int i = 0; i < c; i++) {
        int m = 1+rand()%3;
        switch (m) {
        case MT_SLime:
            monsterinfo[i].hp = 30;
            monsterinfo[i].attack = 5;
            monsterinfo[i].defence = 1;
            break;
        case MT_Orc:
            monsterinfo[i].hp = 40;
            monsterinfo[i].attack = 8;
            monsterinfo[i].defence = 2;
            break;
        case MT_Skeleton:
            monsterinfo[i].hp = 50;
            monsterinfo[i].attack = 15;
            monsterinfo[i].defence = 3;
            break;
        }
    }

}

void EnterGame(StatInfo* p)//포인트인자는 쓸때 *로 타고일단한번 ㄱ , 참조는 받을때도 그냥이름 쓸때도 그냥 이름
{
    const int MONSTER_COUNT = 2;
    PrintMessage("게임 시작");
    while (true)
    {
        StatInfo monsters[MONSTER_COUNT];
        
        CreateMonsters( monsters, MONSTER_COUNT);
        
        for (int i = 0; i < MONSTER_COUNT; i++) {
            PrintStatInfo("Monster", monsters[i]);

        }
        PrintStatInfo("Player", *p);

        PrintMessage("1.battle 1 2.battle 2 3.runaway");

        int input;
        cin >> input;

        if (input == 1 || input == 2)
        {
            int index = input - 1;
            bool Result=EnterBattle(p,&monsters[index]);
            if (Result == false) {
                break;
            }
        }
    }
}

bool EnterBattle(StatInfo* player, StatInfo* monster)
{
    while (true)
    {
        int damage = player->attack = monster->defence;
        if (damage < 0) {
            damage = 0;
        }

        monster->hp -= damage;
        if (monster->hp < 0) {
            monster->hp = 0;
        }

        PrintStatInfo("Monster", *monster);

        if (monster->hp == 0) {
            PrintMessage("몬스터 처치함");
            return true;

        }

        damage = monster->attack - player->defence;
        if (damage < 0) {
            damage = 0;

        }

        player->hp -= damage;
        if (player->hp < 0) {
            player->hp = 0;
        }

        PrintStatInfo("Player", *player);
        if (player->hp == 0)
        {
            PrintMessage("you die");
            return false;
        }
    }
}
