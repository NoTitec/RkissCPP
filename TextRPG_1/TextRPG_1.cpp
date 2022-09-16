// TextRPG_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

enum PlayerType
{
    Knight=1,
    Archer=2,
    Mage=3
};
enum MonsterType
{
    Slime = 1,
    Orc = 2,
    Skeleton = 3
};
//각 전역변수대신 구조체 이용
//구조체는 안에 데이터가만약 크기가 제각각인경우 패딩이 생김
//작은데이터는 큰데이터에맞춰 빈 공간 할당됨 컴퓨터에따라 다를 수 있음
struct ObjectInfo
{
    int Type;
    int hp;
    int attack;
    int defence;

};
ObjectInfo playerInfo;
ObjectInfo monsterInfo;

//int monsterType;
//int monsterHp;
//int monsterAttack;
//int monsterDefence;

void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();
void EnterBattle();
int main()
{
    srand(time(0));
    EnterLobby();
}   

void EnterLobby() {
    while (true) {
        cout << "------------------" << endl;
        cout << "로비입장" << endl;
        cout << "--------------------" << endl;

        SelectPlayer();

        cout << "1.필드입장 2.게임종료" << endl;
        int input;
        cin >> input;

        if (input == 1) {
            EnterField();
        }
        else {
            return;
        }

    }
}
void SelectPlayer() {
    while (true) {
        cout << "------------------" << endl;
        cout << "직업 선택" << endl;
        cout << "1.기사 2.궁수 3.법사" << endl;
        cout << "--------------------" << endl;
        cin >> playerInfo.Type;
        if (playerInfo.Type == Knight) {
            cout << "기사 생성" << endl;
            playerInfo.hp = 150;
            playerInfo.attack = 10;
            playerInfo.defence = 5;
            break;
        }
        else if (playerInfo.Type == Archer) {
            cout << "궁수 생성" << endl;
            playerInfo.hp = 100;
            playerInfo.attack = 15;
            playerInfo.defence = 3;
            break;
        }
        else if (playerInfo.Type == Mage) {
            cout << "마법사 생성" << endl;
            playerInfo.hp = 80;
            playerInfo.attack = 25;
            playerInfo.defence = 0;
            break;
        }
    }
}
void EnterField() {
    while (true)
    {
        cout << "------------------" << endl;
        cout << "필드입장" << endl;
        cout << "--------------------" << endl;

        cout <<"Your status: " << playerInfo.hp << " " << playerInfo.attack << " " << playerInfo.defence << endl;
        CreateRandomMonster();
        cout << "1.전투 2.도주" << endl;
        int input;
        cin >> input;

        if (input == 1) {
            EnterBattle();
            if (playerInfo.hp == 0) {
                return;
            }
        }
        else {
            return;
        }
    }
}
void CreateRandomMonster() {
    //1~3 random
    
    monsterInfo.Type=1 + (rand() % 3);

    switch (monsterInfo.Type) {
    case Slime:
        cout << "create Slime" << endl;
        monsterInfo.hp = 15;
        monsterInfo.attack = 5;
        monsterInfo.defence = 0;
        break;
    case Orc:
        cout << "create Orc" << endl;
        monsterInfo.hp = 40;
        monsterInfo.attack = 10;
        monsterInfo.defence = 3;
        break;
    case Skeleton:
        cout << "create Skeleton" << endl;
        monsterInfo.hp = 80;
        monsterInfo.attack = 15;
        monsterInfo.defence = 5;
        break;
    }
}
void EnterBattle() {
    while (true)
    {
        int damage = playerInfo.attack - monsterInfo.defence;
        if (damage < 0)
            damage = 0;

        monsterInfo.hp -= damage;
        if (monsterInfo.hp < 0)
            monsterInfo.hp = 0;

        cout << "몬스터 남은 체력:" << monsterInfo.hp << endl;
        if (monsterInfo.hp == 0) {
            cout << "몬스터 처치" << endl;
            return;
        }

        damage = monsterInfo.attack - playerInfo.defence;
        if (damage < 0)
            damage = 0;
        playerInfo.hp -= damage;
        if (playerInfo.hp < 0)
            playerInfo.hp = 0;

        cout << "플레이어 남은 체력:" << playerInfo.hp << endl;
        if (playerInfo.hp == 0) {
            cout << "You Died" << endl;
            return;
        }
    }
}
