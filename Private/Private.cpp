// Private.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//DataHiding=Encapsulation

// public protected private

//상속 접근 지정자 : 다음 세대에 부모 유산 어떻게 물려줌?
//부모에게 물려받은 유산 나의 자손에게 똑같이 물려줘야 하지는 않음
// public: protected: private: 
// 실전에서는 public:만 거의 쓴다고 보면됨
//public: 부모 설계 그대로 물려받음
//protected: 부모의 public 영역을 protected로 바꿔 준다
// 이것 지정없이 그냥 상속하면 private 가 앞에 붙어서 상속됨
//private: 모든 영역을 private로 바꿔줌
class Car
{
public: // 맴버 접근 지정자
    //핸들
    void Movehandle(){}
    //페달
    void Pushpedal() {}
    //문
    void OpenDoor(){}
    
    void TurnKey() {
        RunEngine();
    }
protected:
    //상속구조에서 연관성 있음
    //자신의 자손들만 접근 가능 그외 외부 접근 못함
    //차 분해
    void DisassembleCar() {}
    //각종 전기선
    void ConnectCircuit() {}
    //엔진
    void RunEngine() {}

private: //외부에서 접근 불가
    



};

class SuperCar : private Car // 상속접근 지정자
{
public :
    void PushRemoteController() {
        RunEngine();
    }
};

class TSuperCar : SuperCar // private 상속자동으로됨
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
    // 체력 50 이하이면 버서커 모드
    void SetBerserkerMode() {
        cout << "매우 강해짐" << endl;
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
