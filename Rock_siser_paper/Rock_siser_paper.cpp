// Rock_siser_paper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    srand(time(0)); //시드값 설정 시간을 넣으므로 계속 인자가 달라짐
    int mynumber;
    const int s = 1;
    const int r = 2;
    const int p = 3;
    //승률계산
    int win = 0;
    int total = 0;
    while (true) {
        std::cout << "가위(1) 바위(2) 보(3) 골라주세요!\n";
        if (total == 0) {
            cout << "현재 승률없음" << endl;
        }
        else {
            cout << win * 100 / total  << endl;
        }
        cin >> mynumber;

        //컴퓨터는 실제 랜덤값은 가질 수 가 없다
        //rand() 0~32767

        int value = (rand() % 3) + 1; //1,2,3 중 하나가 나옴

        

        if (mynumber == s) {// 어떤 고정수는 하드코딩보다 const 상수 이용하는것이 용이함
            switch (value)
            {
            case s:
                cout << "비김" << endl;
                
                break;
            case r:
                cout << "졌습니다" << endl;
                total++;
                break;
            case p:
                cout << "이겼습니다" << endl;
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
                    cout << "이겼습니다" << endl;
                    break;
                case 2:
                    cout << "비김" << endl;
                    break;
                case 3:
                    cout << "졌습니다" << endl;
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
                        cout << "졌습니다" << endl;
                        break;
                case 2:
                        cout << "이겼습니다" << endl;
                        break;
                case 3:
                        cout << "비김" << endl;
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
