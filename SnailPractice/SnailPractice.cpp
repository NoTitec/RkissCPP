// SnailPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <iomanip>//inputoutput 조작
int inputnumber;//코딩테스트의경우 전역변수

const int MAX = 100;//input이 어느정도 숫자일지 모르므로 일단 충분히 선언
int board[MAX][MAX] = {};//배열은 고정크기만 선언가능

void PrintBoard()
{
    for (int i = 0; i < inputnumber; i++) {
        for (int x = 0; x < inputnumber; x++) {
            cout <<setfill('0')<<setw(2)<< board[i][x] << " ";
        }
        cout << endl;
    }
}

bool Cango(int y, int x) {
    if (y < 0 || y >= inputnumber)
        return false;
    if (x < 0 || x >= inputnumber)
        return false;
    if (board[y][x] != 0)
        return false;
    return true;
}
void SetBoard()
{
    enum flow {
        right,
        down,
        left,
        up
    };
    int dir = right;
    int x = 0;
    int y = 0;
    int cur = 1;
    int dy[] = {0,1,0,-1};
    int dx[] = { 1,0,-1,0 };
    board[y][x] = cur++;
    
    while (true) {
        


        if (cur > (inputnumber * inputnumber)) {
            break;
        }

        int nx=x+dx[dir];
        int ny= y + dy[dir];

        

        if (Cango(ny, nx)) {
            y = ny;
            x = nx;
            board[y][x] = cur++;
        }
        else {
            dir = (dir + 1) % 4;
           
        }
    }
}
int main()
{
    
    cin >> inputnumber;
    SetBoard();
    PrintBoard();
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
