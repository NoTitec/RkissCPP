// Pointer_and_Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    char msg[] = { 'H','\0' };

    //���ڿ� =���� �迭 const char msg[]�̴�

    
    const char* test1 = "Hello World";//test1 �� ���ڿ��� �����ּҸ� ����
    //hello world �� data���� ��򰡿� ����

    char test2[] = "Hello World";// ���ڿ��� ��ǻ�� ���� ������ŭ 
    //�������� �����ѵ� test2�� ������ �� ���ڿ��� 12 ����Ʈ�̹Ƿ�
    //4����Ʈ�� �����Ͽ� �ٿ��ֱ� ����

    //�����ʹ� �ּҸ� ��� �ٱ���!!1
    //�迭�� ���� �� ��ü , ���� �����ͳ��� �پ��ִ� �ٱ��� ���� ��������ü�� test2�� ����!!!!!
    // 
    //�迭�̸��� �����ּ��̴�!!!!
    //�迭�� �Լ��� ���ڷ� �ѱ�� �Ǹ�?

    //�⺻�ڷ����� ���ڷ� �ѱ�� �Լ��� �����ؼ� ����ϹǷ� �Լ� �ܺ� ������ ���� ����ħ
    //�迭�� ���ڷ� �ѱ��� �迭�� �����ּҸ� �ѱ��!!!!!!!!!!!
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
