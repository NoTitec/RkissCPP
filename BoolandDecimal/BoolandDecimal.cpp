// BoolandDecimal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//bool �� ��/������ ������ �ִ�
bool isHighLevel = true;
bool isPlayer = true;
bool isMale = false;

//true,false �� ��������� ��� 1����Ʈ �����̴�
//��������� bool�� ����
// bool �ڷ����� ���� ��/������ �ϳ����� �˼��ִ� �������� �����Ѵ�
// bool �� 1��Ʈ�� �ƴ� 1����Ʈ�� ����ϴ� ���� ��ǻ�� �������Ϳ��� �ּ� ������ 1����Ʈ�̱⶧���̴�
//�Ǽ�(�ε��Ҽ���)

float attackSpeed = 0.639f;
double attackSpeed2 = 123.4123;
//float �� 4����Ʈ double �� 8����Ʈ
//�Ǽ� ǥ������ �ε��Ҽ����� ����Ѵ� 
// . �� ���������� �������� ǥ���ϴ� ���
//����ȭ �̿� ������ 0.xxxxxxxx
//(��ȿ����)*(����)
//float ��ȣ1 ���� 8 ��ȿ���� 23 =32 ��Ʈ
//double ��ȣ1 ���� 11 ��ȿ���� 52 = 64��Ʈ

//ex) -3.375
// 3+0.375 = 0b11+0b0.011
//����ȭ : 0b1.xxxx�� ����ȭ ���� ���� ��ȣ 1 , ���� 2*1�̹Ƿ� 1, ��ȿ���� 1011(�տ������� ä��� ������ �����ʼ����� 0���� ���´�)
//�� ������ unsighned �����ϰ� +127 �������

//�� �ε��Ҽ����� �ٻ簪���� ����ؾ� �Ѵ�
// �Ǽ� 2�� ==�񱳴� ����

int main()
{
    std::cout << "Hello World!\n";
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
