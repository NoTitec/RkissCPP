// FunctionCallStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//�Լ� ����
void fun1();
void fun2(int , int );// ���� �̸��� ����ÿ��� �Ƚᵵ �������� ������ �̸��� ���� �ǹ̰��־ ���� ��쵵 ���� �̸��� �޶� �ȴ�
void fun3();
//�Լ� ȣ�� ����
//�����Ͻ� ���������� �ϳ��� �м���
//���� fun1 ���� fun2�� �θ����Ҷ� fun2�� �������� �ʴ� ����
//C++�� �Լ� �̸��� �ֻ�ܿ� ��� �����ؾ���(�Լ� ����)

void fun1() {
    //push 2
    //push 1
    //call fun2

    fun2(1,2);
    fun3();
}
void fun2(int a,int b) {
    fun3();
}
void fun3() {

}
int main()
{
    std::cout << "Hello World!\n";
    fun1();
}
//������� �Լ��� ��� ȣ���ϸ� ��𼭺��� �Դ��� ������ �����
// ��κ��� ����Ŵ� call stack�� ������ ������������ �����ּҸ� �׷��ִ°�
// 
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
