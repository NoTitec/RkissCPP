// InitialList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//���׿����̳� ������ �ּҰ��� �����Ǿ� �ִ� ���

//�ʱ�ȭ ���
//1.������ ���ο��� 2. �ʱ�ȭ ����Ʈ 3.C++11 ����(����ο� �ʱⰪ ����)
//��� ���迡�� ���ϴ� �θ� ������ ȣ��� �ʿ��ϴ�
//�Ϲ� ������ 1�̳� 2 �� �� ���̾�����
//������ Ŭ������ ��� ���̰� ����
//����Ÿ���̳� constó�� ���ǿ� �ʱ�ȭ�� ���ÿ� �ʿ��� ��� �ݵ�� �ʱ�ȭ ����Ʈ��� �ʱ�ȭ �ؾ��Ѵ�
class Inventory
{
public:
    Inventory() { cout << "�⺻�κ��丮ȣ��" << endl; }
    Inventory(int size) {
        cout << "�κ� ��������� ȣ��" << endl;
        _size = size;
    }
    ~Inventory() { cout << "�Ҹ��� ȣ��" << endl; }
public:
    int _size = 10;// 3�� ���
};

class Player
{
public:
    Player(){}
    Player(int id){}
};
//Is-a (Knight is a player)-> ��Ӱ���
//has-a (Knight has a inventory?)->���԰��� �ϰ�� ������ ����Ʈ������� �ʱ�ȭ �ؾ���
class Knight : public Player
{
public:
    //�θ� ������ ���� �����ִ°�� �ڽĻ����ڿ� ���� �ƹ��͵����ϸ� �θ��� �⺻������ ȣ��
    //�ܴ̿� ���� � ���� �θ������ ȣ�� �� ���� ����
    Knight() :Player(1),_hp(100),_inventory(10),_hpref(_hp),_hpconst(100)//�ٽ�!
        /*
        ��ó�� ����*/
        //Ŭ���������� �����ڿ��� �ʱ�ȭ �����ص� �⺻ �����ڰ� �ѹ� ȣ��ǰ��� ���������ڸ� ȣ���ϸ鼭 ��ü�� 2���� �����ǰ� ���ʿ��� ���� �ٿ��ֱⰡ �����
    {
        _hp = 100;
        //_inventory = Inventory(10); ����!
    }
public:
    int _hp;
    Inventory _inventory;//Knight ��������� �κ��丮�� ��ó���������� ���� ���� �⺻�����δ� �⺻�����ڰ� ȣ���

    int& _hpref; // �̹� �����ϴ� � �Ϳ� ��Ī ���̴� ���̹Ƿ� ��������� �Ǵ°��� �����ؾ��Ѵ�
    const int _hpconst;
};
int main()
{
    Knight k;

    cout << k._hp << endl;


    return 0;
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
