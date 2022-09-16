// PointerBasic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//일반변수는 메모리에 특정 주소에 원하는 값을 넣은것
//전역변수아닌 지역변수는 외부에서 수정작업이 불가함
//이를 접근하기위해 포인터 도입

void SetHp(int* hp) {
	*hp = 100;
}
int number=1;
int main()
{
	int hp=1;
	SetHp(&hp);
	//type* name;
	//type

	//*

	//포인터는 주소를 저장하는 바구니

	int* ptr=&number;//ptr주소를 참조해라 참조하면 int값이 있을 것이다.
	//type 를 붙여주는 이유!!!!!!!!!!!!
	// 포인터의 추가정보를 줌 주소에 가면 뭐가있는지!!
	// 주소를 타고가서 어떤식으로 안에든걸 해석할지 알려주는 역할
	//포인터 변수는 동작 단위로 고정 32비트 시스템이면 4바이트 고정이다

	//추가문법: 주소저장 바구니가르키는 주소에서 뭘 해라!
	//*변수이름=값;

	int value1 = *ptr;
	*ptr = 2;

	__int64* ptr2 = (__int64*)&number;//형변환으로 그냥 저장
	//이렇게 안만들면 되지만 네트워크 통신같은경우 어쩔수없이 이런식으로 사용할 경우가 생김
	*ptr2 = 0x0000AABBCCDDEEFF;
	//이러면 ptr2엔 64비트 수가 있다고 믿고 int수보다 긴값을 number메모리위치에서 그냥 
	//저장해버리는데 이러면 진짜 int인 number 4바이트의 영역을 넘어 다른 메모리를 침범하여 
	//저장해버린다
	//만약 이 침범된 위치에 중요한 정보가 저장되어있었다면 프로그램에 치명적 오류를 발생시킨다

}


