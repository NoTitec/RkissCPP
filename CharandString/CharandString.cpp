// CharandString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//char �� �������� ,���ڶ�� �ǹ̸� ��Ÿ���� ���� ����Ѵ�

// char �� ����,����
// wchar_t : �����ڵ� ����

//�ƽ�Ű�ڵ��̿�
// char�� �׳� ���ڸ� �ְų� 'a'�� �̿��� a�� �ش��ϴ� �ƽ�Ű �ڵ尪�� �����Ѵ�

char ch3 = 'a' + 1;

//������ ���ڸ� ǥ���ϱ����ؼ� 2����Ʈ ¥�� �����ڵ带 �̿��ؾ� �Ѵ�
//�����ڵ�� ǥ�� ����� �������� �ִµ� UTF-8 �� UTF-16�� �̿��Ѵ�
//8 �� ���ĺ��̳� ���ڴ� 1����Ʈ, �������� ���ڴ� 2����Ʈ, �ѱ��̳� ���ڴ� 3����Ʈ�� �̿��Ѵ�
//16�� ���� ��κ� 2����Ʈ�� �̿��ϰ� ���� �������� ��� ���ڸ� 4����Ʈ�� �̿��Ѵ�

wchar_t wch = L'��';// utf-16 �̴� 0x0000
wchar_t special = L'\'';
//�׷��� cout�� char���� �̹Ƿ� wcout�� �̿��ؾ��ϰ�
//�ű⿡ �ѱ����� wcout���� ���ڰ� �ѱ�������

//Escape Sequence
//ǥ�� �ָ��� ���� ǥ��
//\t = tab
//\n = ���� �ǳʶٱ�
//\r = Ŀ��
//\'

//���ڿ�
//���ڹ迭�ε� �������� �׻� \00�� �־ �̺κ��� �������̶�� �Ǵ��Ѵ�
//���� NULL�̴�

int main()
{
    cout << "Hello World!\n";
    char str[] = { 'h','e' ,'\0'};//\0 ��� �ʿ�
    char str2[] = "He";//�ڵ����� �������� \0�� ��

    wcout.imbue(locale("kor"));
    wcout << wch << "\n";
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
