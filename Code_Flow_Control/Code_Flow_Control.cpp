// Code_Flow_Control.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#pragma region ���ǹ�
//if else �� {}���� �� ���� ���̾ ���� 1�ٸ� ������
//���� ������ �˻��ؾ��ϴ°�� if else if ....���� �̿��Ѵ�
  //���������� ���� ������ if������ �ذ��ؾ��Ҷ�
//���� ���ǹ��� �ݺ��Ǵ� ��찡 �ִµ� Ÿ��ġ�� �Ǽ��ϸ� �۵��� ����� �� �� �� �ִ�

//switch-case
// break�Ȱɸ� ���� ���嵵 ��� �����ع��� �����ؾ���.
//�ƹ� ���ǵ� �Ȱɸ��� default�� �����Ѵ�

#pragma endregion 

#pragma region �ݺ���
//while
//
#pragma endregion
int main()
{
	int input = 0;
	std::cout << "Hello World!\n";

	switch (input)//���� �迭�� ���� �� �־ if�� �Ϻ� ��ü�� �Ұ��� �ϴ�.
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
	//�ݺ���

	int count = 0;
	while (count < 5)
	{
		cout << "Hello World" << endl;
		count++;
	}

	//1���� �ݵ�� ����
	do
	{
		cout << "do while" << endl;
		count++;
	} while (count < 10);

	for (int i = 0; i < 5; i++) {
		cout << "for" << endl;
		//break �ݺ��� �ƿ� ��������(���� ���� �ݺ��� 1���� ��������)
		//continue ���� ���� �����ϰ� ���� �ݺ��� ���� �Ѿ
	}

	for (int count = 1; count <= 10; count++) {
		bool isEven = ((count % 2) == 0);
			if (isEven)
			continue;
		
			cout << count << endl;
	}

	//����� ��������
	//������ ���� �Է½� �ش� n*n �� �������� ������

	int userinput;
	cin >> userinput;
	for (int i = 0; i < userinput; i++) {
		for (int j = 0; j < userinput; j++) {
			cout << "*";
		}
		cout << endl;
		
	}

	//1~ �ٸ��� 1�پ� ����
	cin >> userinput;
	for (int i = 0; i < userinput; i++) {
		for (int j = 0; j < i+1; j++) {
			cout << "*";
		}
		cout << endl;
	}
	//�� �Ƕ�̵��� ���
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

