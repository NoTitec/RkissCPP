
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
    //yype �̸� ����;

    StatInfo monsters[10];//�迭�� ��������� ũ�� �����ؾ���

    const int monsterCount = 10;//const ������ ���� ��
    StatInfo monsters2[monsterCount];

    //�迭 �̸��� �����̸����� �ٸ���

    auto who = monsters;//R value �߷��ؼ� l value ����

    //�迭�� �̸��� �迭�� ���� �������̴� type * �迭�̸�
    StatInfo* monster_0 = monsters;
    monster_0->hp=100;
    monster_0->attack = 10;
    monster_0->defence = 1;

    StatInfo* monster_1=monsters + 1; // ���� monster�� �̵�

    //������ ������ �������� ��ȯ ����

    StatInfo& monster_2 = *(monsters + 2);//monsters+2 �����ͷ� ���� ���� StatInfo�����Ϳ� monster_2 ��� �̸��� ����
    monster_2.hp = 300;

    //���� �̰� ���� �ٸ� �ǹ�
    StatInfo temp = *(monsters + 2); //temp��  monsters+2 ��������ġ ���� ����
    temp.hp = 300;

    // ��� ���� ����
    for (int i = 0; i < 10; i++) {
        StatInfo& monster = *(monsters + i);
        monster.hp = 100;
        monster.attack = 10;
        monster.defence = 1;
    }
    monsters[0].hp = 100;
    //�ٵ� *(monsters+i) ������
    //�׷��� �ε������� *(monsters+i)=monsters[i]

    //�迭 �ʱ�ȭ ����
    int numbers[5];
    int numbers2[5] = {};//0���� �ʱ�ȭ
    int numbers3[10] = {1,2,3,4,5};//�����Ȱ͸� ����

    int numbers4[] = { 1,2,3,4,5,6,7,8,9 };//������ ������ŭ ������

}

