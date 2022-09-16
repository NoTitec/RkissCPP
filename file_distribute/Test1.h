#pragma once
//다른곳 include여러번 호출될시 한번만 허용
//헤더파일에 구조체등의 자료가 중복 정의되면 충돌이 발생함
//만약 main의 cpp가 여러 cpp파일을 include할때 2개이상 cpp가 하나의 inlcude공유시 문제발생가능
//pragma once말고 #ifndef 이름
//define 이름 //endif 
//동작방식은 약간 다르지만 결과는 똑같음
//pragma once가 더 최적화가 좋음
//그러나 컴파일러 오류로 문제생기는경우 ifndef버전사용


//!!!! 헤더파일은 최대한 간단하게 유지하는것이 중요함
//! 선언하는데만 사용할것 헤더파일에 include나 usingnamespace사용금지
//! 
void Test_1();
void Test_2();

void Test_3();