// FunctionBasic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//�Լ�
/*
�Է����� �����ް� ,��� ���� ������ �����ش�

��ȯŸ�� �Լ��̸�(����Ÿ�� �Ű�����)
{
    �Լ� ����
    return ----
}
*/

void PrintHelloWorld() {
    cout << "Hello World" << endl;
    return;//�Լ��� return ������ �Լ� ������ ��������
}
void PrintNumber(int inputnumber) {
    cout << "inputnumber is" << inputnumber << endl;
}
int MulNumber(int inputnumber) {
    return 2 * inputnumber;
}
int MultwoNumber(int one, int two) {
    return one * two;
}
//�����
//F5 ����� �����Ͽ� �극��ũ����Ʈ���� ���� �� ����
// 
//F10
// �Լ������� �����Ѵ� �Լ��� �ִ� ���� ������ �Լ��� �����ʰ� ����� Ȯ���ϰ� �����ٷ� �Ѿ��
// 
//  
//F11
// �Լ� ���η� ���� �Լ� ������ �Լ� ���η� �� �����Ѵ�
//
//���� ������
// �޸𸮿� �ڵ念��- ����,������������- ������ -���ÿ����� �ִ�
// ������ �����ּҿ��� �����ּҷ� ���� ������ �ü���� �Ҵ�����
// �Լ������� ������ �Ű����� ,��ȯ �ּҰ� ,���������� ������
// �Ű������� input�� ��ȯ �ּҰ��� �Լ�ȣ�������� ���ư� �ּҸ� ������
//


int main()
{
    int a = 3;
    int b = 5;
    int multworesult = MultwoNumber(b,a);
    PrintNumber(multworesult);
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
