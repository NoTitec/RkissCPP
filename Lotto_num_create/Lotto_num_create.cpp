// Lotto_num_create.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//1. swap �Լ� �����
 void Swap(int &a, int &b)
{
    int temp = b;
    b = a;
    a = temp;
}
//2. �����Լ� �����
 void Sort(int numbers[], int count)
 {
     
     for (int i = 0; i < count; i++) {
         
         for (int j = i + 1; j < count; j++) {
             if (numbers[i] > numbers[j]) {
                 int temp = numbers[i];
                 numbers[i] = numbers[j];
                 numbers[j] = temp;
             }
         }
     }
 }
 //3. �ζ� ��ȣ ������
 void ChooseLotto(int numbers[]) {
     srand(time(0));
     int mycount = 0;// 6�� ���������� �ݺ�
     while (mycount != 6) {
         int rvalue = 1 + (rand() % 45);

         bool found = false;
         for (int i = 0; i < mycount; i++) {
             if (numbers[i] == rvalue) {
                 found = true;
                 break;
             }
         }

         if (found == false)
         {
             numbers[mycount] = rvalue;
             mycount++;
         }
     }
     
     Sort(numbers, 6);// �Լ��� ���ڷ� ���� �迭�� �迭 ũ�� sizeof���Ұ�
     // ���� ���ڷ� �迭 ũ�� �ִ��� �迭���� �迭 �� �˸��� ���ִ��� �ؼ� �˻��ʿ�
 }
int main()
{
    int a = 1;
    int b = 2;
    Swap(a, b);//����Ÿ������ ����� ���ڷ� ab�� �ּҸ� �ѱ�
    cout << a << b<<endl;

    int numbers[6] = { 1,42,3,15,5,6 };
    int size = sizeof(numbers) / sizeof(int);

    Sort(numbers, size);
    for (int i = 0; i < size; i++) {
        cout << numbers[i]<<",";
    }
    int numbers2[6] = {};

    ChooseLotto(numbers2);
    for (int i = 0; i < size; i++) {
        cout << numbers2[i] << ",";
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
