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

//�κ� �����ϴ� �Լ�
void EnterLobby();
//�÷��̾ ����� ��ȯ�ϴ� �Լ�
StatInfo CreatePlayer();
//�̹� ������� ���� Ʋ�� �����Ͽ� ������ �����ϴ� �Լ�
void CreateMonster(StatInfo* info);
//������ �����ϴ� �Լ�
bool StartBattle(StatInfo* player, StatInfo* monster);

int main()
{
    EnterLobby();
}
void EnterLobby()
{
    cout << "�κ� �����߽��ϴ�" << endl;

    StatInfo player;
    player.hp = 0xbbbbbbbb;
    player.attack = 0xbbbbbbbb;
    player.defence = 0xbbbbbbbb;
    player=CreatePlayer();// ���� ���� ���簡 ������ �Ͼ��
    //�Ű�����,RET,�������� temp,player | �Ű����� &temp RET, �������� ret
    /*
    player=CreatePlayer(); �����Ϸ��� �� �ѹ����� �����δ� �Ʒ� �ι���ó��
    ó���Ѵ�

    StatInfo temp = CreatePlayer();
    player = temp;
    */
    StatInfo monster;
    monster.hp = 0xaaaaaaaa;
    monster.attack = 0xaaaaaaaa;
    monster.defence = 0xaaaaaaaa;
    //�Ű�����,RET,�������� monster | �Ű����� &monster RET, �������� 
    CreateMonster(&monster);//���� ����
    
    //����
    //����ü���� �����Ҷ� ���?
    //player = monster;//����� ���� ����ü ���� �ϳ��ϳ��� �����Ѵ�

   bool victory= StartBattle(&player,&monster);

   if (victory)
       cout << "victory" << endl;
   else {
       cout << "loose" << endl;
   }
}

StatInfo CreatePlayer()//�Լ� ������ ����� �ٱ��� ����
{
    StatInfo ret;
    cout << "create player" << endl;

    ret.hp = 100;
    ret.attack = 10;
    ret.defence = 2;

    return ret;
}
void CreateMonster(StatInfo* info)//�ٱ����� �ּҷ� ������ ���� ����
{
    (*info).hp = 40;
    info->attack = 8;
    info->defence = 1;
}

bool StartBattle(StatInfo* player, StatInfo* monster)
{
    while (true) {
        //������ ����
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
        //������ ����
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
