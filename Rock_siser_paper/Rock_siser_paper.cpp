// Rock_siser_paper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    srand(time(0)); //�õ尪 ���� �ð��� �����Ƿ� ��� ���ڰ� �޶���
    int mynumber;
    const int s = 1;
    const int r = 2;
    const int p = 3;
    //�·����
    int win = 0;
    int total = 0;
    while (true) {
        std::cout << "����(1) ����(2) ��(3) ����ּ���!\n";
        if (total == 0) {
            cout << "���� �·�����" << endl;
        }
        else {
            cout << win * 100 / total  << endl;
        }
        cin >> mynumber;

        //��ǻ�ʹ� ���� �������� ���� �� �� ����
        //rand() 0~32767

        int value = (rand() % 3) + 1; //1,2,3 �� �ϳ��� ����

        

        if (mynumber == s) {// � �������� �ϵ��ڵ����� const ��� �̿��ϴ°��� ������
            switch (value)
            {
            case s:
                cout << "���" << endl;
                
                break;
            case r:
                cout << "�����ϴ�" << endl;
                total++;
                break;
            case p:
                cout << "�̰���ϴ�" << endl;
                win++;
                total++;
                break;
            default:
                cout << "rand err" << endl;
                break;
            }

        }else
            if (mynumber ==2) {
                switch (value)
                {
                case 1:
                    cout << "�̰���ϴ�" << endl;
                    break;
                case 2:
                    cout << "���" << endl;
                    break;
                case 3:
                    cout << "�����ϴ�" << endl;
                    break;
                default:
                    cout << "rand err" << endl;
                    break;
                }
            }
          else
             if (mynumber == 3) {
                switch (value)
                    {
                case 1:
                        cout << "�����ϴ�" << endl;
                        break;
                case 2:
                        cout << "�̰���ϴ�" << endl;
                        break;
                case 3:
                        cout << "���" << endl;
                        break;
                default:
                        cout << "rand err" << endl;
                        break;
                    }
                }
             else {
                 break;
             }
    }

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
