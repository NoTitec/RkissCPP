// MultiPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void SetNumber(int* a)
{
    *a = 1;
}
void SetMessage(const char* a) {//a�� msg�ּ���
    a = "bye";//a�� �ּҸ� .read ��� ������ Bye�� �ּҷ� ������ ������ Hello�� �ٲ���� �ƴ�

    //*a = 'b';
    //*(a + 1) = 'y';// a[1];
}

void SetMessage(const char** a) {//a�� �ּҸ� �ް� �� a�� ���� �ٽ� �ּҹٱ��������� �װ� �ٽ� ���󰡸� const char�� �ִ�

    *a = "bye";
}

void SetMessage2(const char*& a) {//���������� �Լ��� �����̸������� �ش纯���� �ּҸ� �ѱ�
    a = "bye";
}
int main()
{
    int a = 0;
    SetNumber(&a);

    const char* msg = "Hello";//�����δ� char �迭�� "Hello�ּҸ� msg�� ������
    SetMessage(msg);//msg �ּҸ� �ѱ�
    //cout << msg << endl;

    const char** pp=&msg;// pp�� �ּҴ�� �ٱ��� �ּ�Ÿ���� �� �ּҴ�� �ٱ��� ����
    //�̰� �ٽ� Ÿ�� ���� const char�� ����
    //msg[Hello�ּ�]
    //pp[&msg]
    //�Ű�����/����/�������� msg(Hello�ּ�) �Ű�����a(&msg msg�� �ּ� ret ��������)
    SetMessage(pp);
    *pp = "bye";//pp�� msg�� �ּҸ� ���� *pp�� �ϸ� msg�� ����Ű�� ������ ��Ÿ��
    cout << msg << endl;

    SetMessage2(msg);

}//2���������̻��� ���� �ڵ� �߸�¥���� ���ɼ� ����

//���ı��� ��� const char **��� �̳༮�� const char *�����ڷḦ ����ϴ� ��



