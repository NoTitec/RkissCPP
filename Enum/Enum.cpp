// Enum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//��� ��뿡 const�� ����ϱ⵵ ������ �ʹ� ���� ���� �� �����ִ�
//���� ��� ������ ��������� ���ȭ�ϰ����ϸ� �°����� ���°� �����Ѵ�
//�̷� ��Ȳ�� ����ϱ� ���� enum �������� ����Ѵ�
// �������� const�� �޸� ���� �ݵ�� �ʱ�ȭ�� ���� �ʾƵ� �ȴ�, const�� �ʱ�ȭ ���ҽ�
//������ �߻��Ѵ� enum �� �⺻������ ���� ���� �� 0���� �����ȴ�
// ���� ������ ���� ���� +1 ���� ������

//const �� �޸𸮿� ������ ������ �Ǿ��������� �ܼ��� ���� �̸��� ���Ⱥκ��� ����������
//�ٲ�ġ���ϴ� �͵� �ִ� ���ð����� �����ϰų� auto�������� �ּҰ� ���� �� ���� �ֱ⵵ �ϴ�

//�������� 100% �ٲ�ġ���ϴ� ����̴�(�޸𸮸� �ƿ� ���� �ʴ´�)
enum ENUM_SRP
{
    ENUM_SISSORS=1,
    ENUM_ROCK,
    ENUM_PAPER
};

#define DEFINE_SISSORS 1 //�ִ��� ����
//# �� ������ ��ó�� ���ù��̴� 
//�������� ��ó��->������-> ��ũ�����̴�
//#include <iostream> ������ ������ iostream ����ã�� �ش系�� ��°�� ����
//define sissors�� ������ ���� ������ �ٲ�ġ��ȴ�
// �������� �޸� �������ƴ� �ٸ� �͵鵵 �����ϴ�
//�׷��� ���� �ٲ�ġ���̱⶧���� ���� 1+2�̰� �̸� �����ϸ� *2�ҽ� 6�̾ƴ� 5�����´�
//��ó�� �ܰ迡�� ���ǰ� ����� ������ �Ұ��ϹǷ� ����� �ܰ趧 ����� �� �ִ�

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
