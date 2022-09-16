// Reference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct StatInfo
{
    int hp;
    int attack;
    int defence;
    //���� ������ ������ ũ�⸸ŭ �Ҵ��
};

//����: ������� ���� ���� ���� ����
//�Ű�����,ret,��������(info)-> CreateMonsterȣ��� �Ű������� &info ret ��������
void CreateMonster(StatInfo* info)
{
    info->hp = 100;
    info->attack = 8;
    info->defence = 5;

}
//: �����͹�ĺ��� �������� ������������ ������ ���� ����
//�Ű�����,ret,��������(info)-> CreateMonsterȣ��� �Ű������� info���纻 ret ��������
StatInfo CreateMonster(StatInfo info)//*�� �Ⱥ����� ������ ���� ����ȴٴ� ��
{
    StatInfo temp;
    temp.hp=info.hp ;
    temp.attack=info.attack ;
    temp.defence=info.defence ;
    return temp;
}

//1) �� ���� ����� ������ ���纻�� �����ϴ� ���
//2) �ּ� ���� ����� ���� ��ü�� �����ϴ� ���

//�Ű��������Ǵ� ����ü�� �۴ٸ� ����̵� �� ������ ������ 
//���� �̰� ũ�ٸ� �����ϴµ� �ð��� �����ɸ��� �ȴ�

//3) ��������
//C++���� ������

//Ư�� ���� �����ϴ� ���� ã�� �Լ�
StatInfo* FindMonster() { //�� �Լ��� �ּҸ� ��ȯ�Ѵ� �� �ּ� ���󰡸� StatInfo�����Ͱ� �ִ�
    //Heap���� ���� ã�ƺ�
    //ã���� �� �ּ�
    //������ return nullptr;
    return nullptr;
}
StatInfo globalInfo;

void PrintInfoByPtr_allconst(const StatInfo*const info) {
    if (info == nullptr)// ���ڷ� ���� �ּҵ����� �ٷ� �ߴ��ϰ�����
        return;
    //todo
    
}
void PrintInfoByPtr_dataconst(const StatInfo* info) {//info�� �ּҵ��󰡸��ִ� ���� ���� �Ұ�
    cout << "HP" << info->hp << endl;

    info = &globalInfo;
}
void PrintInfoByPtr_pointerconst(StatInfo*const info) {//info �ּҰ��� const�Ǿ� �ּҺ��� �Ұ�
    cout << "HP" << info->hp << endl;

    info->hp = 10000;
}
void PrintInfoByRef_ref_dataconst(const StatInfo& info) {//�б⸸ ���� �ϰ� ����, �ǵ�ġ���� �������� ���� !!!!! ���� �ʼ�
    cout << info.hp << endl;
}
#define OUT //�𸮾󿡼� ���� ��� �ܼ��� ��Ʈ �ִ� �ǹ� �ּ�������
void ChangeInfo( OUT StatInfo& info) {//���۷����� ���� ������ �ٲ� ���ִٴ� ��Ʈ
    info.hp = 1000;
}
int main()
{
    int number = 1;// 4����Ʈ ���� �ٱ��� �� number�̸��ٿ� ����ϰڴ�
    //�� �ּҿ� 1�� �־��

    //�ּҴ�� �ٱ����ְ� �� �ٱ��ϴ� int �����Ͱ� �ִ�
    //pointer �ٱ��� �ּҷ� �̵��ؼ� �ű⿡ 2�� �־��
    int* pointer = &number;
    *pointer = 2;

    //����!!!!!!!!!!!!!!!!!!!!
    //����� �Ϲ�ó�� �۵������ int*�� ������ �Ȱ���(����� �ڵ� ����)
    int& reference = number;
    reference = 3;
    //number�� reference��� �ٸ� �̸��ϳ� �߰��Ѱ�
    //���⿡ �� ������ number���� ��������
    // ������ ����ϴ� ����?
    // �⺻ �����Ϳ��� �ɹ� ������ ->�����µ� �ſ� ���� �׷��� .�� ������
    //����ϱ� ���� ����


    StatInfo info;//�� StatInfo ����ü

    //������vs ����
    // ������ ������ ������(����� �ڵ� �Ȱ���)
    // ���Ǽ��� ������ �� ����

    //�׷��� �̰��� �� ������ ���� ���� �ƴ�
    //�����ʹ� �ּҸ� �ѱ�� Ȯ���ϰ� ������ �ѱ�ٴ� ��Ʈ�� ����
    //������ �������� �𸣰� ����ĥ���ɼ��� ����
    //�𸣰� ������ ��ġ�°� ���� �� ����
    //const�� ���� ����
    //�����͵� const����
    // * ���̳� �ڿ��Ŀ����� �ǹ̰� �޶���
    
    //2) �ʱ�ȭ
    // ����Ÿ���� �ٱ����� 2��° �̸��� �����ϴ°��̶� 
    // ����� �����ϴ� ����� �ݵ�� �ʱ�ȭ �Ǿ���Ѵ�
    // �����ʹ� �� �ּҹٱ��ϼ���� ���߿� ��Ⱑ ����������
    // ����Ÿ���� �Ұ����ϴ�
    // 
    // 
    // �����Ϳ��� ���ٴ� �ǹ�
    StatInfo* nullpointer = nullptr;//��� �ּҵ� ����Ű�� �ʴ� ����
    //nullptr�� 0�̴� ���� �״� ���� 80���δ� nullptr����
    // ����Ÿ���� nullptr�� ���� ������ ���� �����Ѿ� �ϱ� ����!!
    PrintInfoByPtr_allconst(nullpointer);// nullptr���ý� ����ó�� �����Ƿ� �׳� �ǳʶ�

    //�ڵ� �̸� ����� �̸� ���õ� ctrl+R+R

    CreateMonster(&info);

    StatInfo* Statpointer;
    Statpointer = &info;
    PrintInfoByPtr_pointerconst(Statpointer);
    //�� 3������ �Ʒ� �ѹ���� ����
    PrintInfoByPtr_pointerconst(&info);

    StatInfo& Statreference = info;
    PrintInfoByRef_ref_dataconst(Statreference);
    //info�� �ּ� �� ���� ���� �Ѻ���� ���簰���� �Լ� ������ �ٸ�
    PrintInfoByRef_ref_dataconst(info); //������ �Դ� info.hp=1000; ������ ������ const�� ���� ���Ⱑ��

    //���
    // Team By Team ������ ���� ����
    //���� ���¼ҽ��� ���� ������ ������ ���
    //�𸮾� �������� reference�� �ֿ�

    //nullptr�� ���� ���ִ� ��Ȳ���� ������, Ȯ���ϰ� �ִ� �ּҶ�� reference���
    //���� �ȵǰ� �б⸸ �����ϰ� ����ҽ� const ref&
    //�Ϲ������� ����� ȣ��� OUT����
    //�� ���������� ó�� ����������� �̾ ���������Ѵ�
    //��� ���� �ʴ´�

    ChangeInfo(OUT info);

    //�����ͷξ����� ������ �ѱ����?
    // �����ʹ� �ּҰ��� �ٱ����̴� info�� �ּҸ� ����
    // info�� �ٸ� �̸� �ٿ� �ѱ���
    //������ ���������Ϳ� ��Ī ���̴� ���̹Ƿ� *data�� ������ �����Լ��� ���ڷ� �ָ�ȴ�
    PrintInfoByRef_ref_dataconst(*Statpointer);//�����޴��Լ��� ���� ����
    //�ݴ��?
    //������ �޴� �Լ��� �ּ� �޾ƾ��ϱ⶧���� ����Ÿ�Կ� &�ٿ� �ּ� �ѱ�� ��
    PrintInfoByPtr_allconst(&Statreference);

    //* ,& �� �ΰ��� �ǹ���
    //&�� �������̸� �ּҲ����޶� Ÿ�Եڸ� ������ �������̴� ��� �ǹ�
    //*�� �������̸� �����ּҷ� ���󰡶� Ÿ�Եڸ� �ش� ������ �������̴ٶ�� �ǹ�
}

