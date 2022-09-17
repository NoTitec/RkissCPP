// Private.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//DataHiding=Encapsulation

// public protected private

//��� ���� ������ : ���� ���뿡 �θ� ���� ��� ������?
//�θ𿡰� �������� ���� ���� �ڼտ��� �Ȱ��� ������� ������ ����
// public: protected: private: 
// ���������� public:�� ���� ���ٰ� �����
//public: �θ� ���� �״�� ��������
//protected: �θ��� public ������ protected�� �ٲ� �ش�
// �̰� �������� �׳� ����ϸ� private �� �տ� �پ ��ӵ�
//private: ��� ������ private�� �ٲ���
class Car
{
public: // �ɹ� ���� ������
    //�ڵ�
    void Movehandle(){}
    //���
    void Pushpedal() {}
    //��
    void OpenDoor(){}
    
    void TurnKey() {
        RunEngine();
    }
protected:
    //��ӱ������� ������ ����
    //�ڽ��� �ڼյ鸸 ���� ���� �׿� �ܺ� ���� ����
    //�� ����
    void DisassembleCar() {}
    //���� ���⼱
    void ConnectCircuit() {}
    //����
    void RunEngine() {}

private: //�ܺο��� ���� �Ұ�
    



};

class SuperCar : private Car // ������� ������
{
public :
    void PushRemoteController() {
        RunEngine();
    }
};

class TSuperCar : SuperCar // private ����ڵ����ε�
{
public:
    //DisassembleCar();
};
class Berserker
{
public:
    int GetHp() { return _hp; }
    void SetHp(int hp)
    {
        _hp = hp;
        if (_hp < 50) {
            SetBerserkerMode();
        }
    }
private:
    // ü�� 50 �����̸� ����Ŀ ���
    void SetBerserkerMode() {
        cout << "�ſ� ������" << endl;
    }
private:
    int _hp = 100;
};
int main()
{
    Car car;
    SuperCar ucar;
    ucar.PushRemoteController();

    Berserker b;
    b.SetHp(20);
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
