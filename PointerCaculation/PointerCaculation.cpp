// PointerCaculation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//�ּ� ������
//��� ������
//���� ������
//���� ��� ������

struct Player
{
    int hp; //�ּ� +0
    int damage; //�ּ�+4

};
//��������� ptr [�ּ�] �� �ּ��� ���� ��������� �ǹ�
int main()
{
    int number = 1;

    int* pointer = &number;

    
    //& �� �ش� ���� Ÿ�Կ����� type*��ȯ!!!!!!!!

    //��� ������
    //�迭���� ���
    number += 1;//���� ������Ŵ
    //int *
    //*�� �����Ͷ�°�
    //int �� �ּҵ��󰡸� 4����Ʈ ũ�� �ٱ��ϰ� �ִ�
    pointer += 1;// 4�� �����Ѵ� int *�̹Ƿ� intũ���� 4����Ʈ ����
    //�ѹ��� typeũ�⸸ŭ�� �̵��϶�� ��

    //���� ������
    *pointer = 3;// �����͹ٱ����� �ּҷ� �̵��Ͽ� 3�� �־��
    
    //���� ��� ������
    Player player;
    player.hp = 100;
    player.damage = 10;

    Player* playerPtr = &player;//player�� �ּҸ� Player* ��ȯ�ϰ� �װ� playerPtr�� ����
    (*playerPtr).hp = 200;
    (*playerPtr).damage = 100;
    
    playerPtr->hp = 300;
    playerPtr->damage = 400;
}

