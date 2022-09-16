// Code_Flow_Control.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#pragma region 조건문
//if else 문 {}없을 시 조건 참이어도 다음 1줄만 실행함
//여러 조건을 검사해야하는경우 if else if ....문을 이용한다
  //가위바위보 같은 문제를 if문으로 해결해야할때
//같은 조건문이 반복되는 경우가 있는데 타자치다 실수하면 작동이 제대로 안 될 수 있다

//switch-case
// break안걸면 이후 문장도 계속 실행해버림 주의해야함.
//아무 조건도 안걸리면 default를 실행한다

#pragma endregion 

#pragma region 반복문
//while
//
#pragma endregion
int main()
{
	int input = 0;
	std::cout << "Hello World!\n";

	switch (input)//정수 계열만 넣을 수 있어서 if문 완벽 대체는 불가능 하다.
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	default:

		break;
	}
	//반복문

	int count = 0;
	while (count < 5)
	{
		cout << "Hello World" << endl;
		count++;
	}

	//1번은 반드시 실행
	do
	{
		cout << "do while" << endl;
		count++;
	} while (count < 10);

	for (int i = 0; i < 5; i++) {
		cout << "for" << endl;
		//break 반복문 아예 빠져나감(현재 범위 반복문 1개만 빠져나감)
		//continue 현재 동작 중지하고 다음 반복문 으로 넘어감
	}

	for (int count = 1; count <= 10; count++) {
		bool isEven = ((count % 2) == 0);
			if (isEven)
			continue;
		
			cout << count << endl;
	}

	//별찍기 연습문제
	//유저가 정수 입력시 해당 n*n 별 나왔으면 좋겠음

	int userinput;
	cin >> userinput;
	for (int i = 0; i < userinput; i++) {
		for (int j = 0; j < userinput; j++) {
			cout << "*";
		}
		cout << endl;
		
	}

	//1~ 줄마다 1줄씩 증가
	cin >> userinput;
	for (int i = 0; i < userinput; i++) {
		for (int j = 0; j < i+1; j++) {
			cout << "*";
		}
		cout << endl;
	}
	//역 피라미드형 찍기
	cin >> userinput;
	for (int i = 0; i < userinput; i++) {
		for (int j = userinput - i; j > 0; j--) {
			cout << "*";
		}
		cout << endl;
	}

	for (int i = 2; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			cout << i << "*" << j << "=" << i * j<<endl;
		}
	}
}

