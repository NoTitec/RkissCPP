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
//�� ����������� ����ü �̿�
//����ü�� �ȿ� �����Ͱ����� ũ�Ⱑ �������ΰ�� �е��� ����
//���������ʹ� ū�����Ϳ����� �� ���� �Ҵ�� ��ǻ�Ϳ����� �ٸ� �� ����
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
        cout << "�κ�����" << endl;
        cout << "--------------------" << endl;

        SelectPlayer();

        cout << "1.�ʵ����� 2.��������" << endl;
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
        cout << "���� ����" << endl;
        cout << "1.��� 2.�ü� 3.����" << endl;
        cout << "--------------------" << endl;
        cin >> playerInfo.Type;
        if (playerInfo.Type == Knight) {
            cout << "��� ����" << endl;
            playerInfo.hp = 150;
            playerInfo.attack = 10;
            playerInfo.defence = 5;
            break;
        }
        else if (playerInfo.Type == Archer) {
            cout << "�ü� ����" << endl;
            playerInfo.hp = 100;
            playerInfo.attack = 15;
            playerInfo.defence = 3;
            break;
        }
        else if (playerInfo.Type == Mage) {
            cout << "������ ����" << endl;
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
        cout << "�ʵ�����" << endl;
        cout << "--------------------" << endl;

        cout <<"Your status: " << playerInfo.hp << " " << playerInfo.attack << " " << playerInfo.defence << endl;
        CreateRandomMonster();
        cout << "1.���� 2.����" << endl;
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

        cout << "���� ���� ü��:" << monsterInfo.hp << endl;
        if (monsterInfo.hp == 0) {
            cout << "���� óġ" << endl;
            return;
        }

        damage = monsterInfo.attack - playerInfo.defence;
        if (damage < 0)
            damage = 0;
        playerInfo.hp -= damage;
        if (playerInfo.hp < 0)
            playerInfo.hp = 0;

        cout << "�÷��̾� ���� ü��:" << playerInfo.hp << endl;
        if (playerInfo.hp == 0) {
            cout << "You Died" << endl;
            return;
        }
    }
}
