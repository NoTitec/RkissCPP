// StringPractice2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//strlen , strcpy, strcat , strcmp
#include <iostream>
using namespace std;

char* StrCat(char* dest, char* src);
int Strcmp(char* dest, char* src);
void Strreverse(char* src);
int main()
{
    const int BUF = 100;

    char a[BUF] = "Hello";
    char b[BUF] = "Hella";

    //StrCat(a, b);
    //cout << Strcmp(a, b);
    Strreverse(a);
    cout << a;
}

char* StrCat(char* dest, char* src)
{
    char* ret = dest;
    while (*dest)
    {
        dest++;
    }
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
    return ret;
}
int Strcmp(char* dest, char* src)
{
    
    while (((*dest)!='\0')||((*src)!='\0')) {
       
            if (*dest > *src) {
                return 1;
            }
            if(*dest<*src) {
                return -1;
            }
            dest++;
            src++;
        
    }
    return 0;
}
void Strreverse(char* src)//ÄÚÅ×¿¡¼­µµ ÀÚÁÖ³ª¿È

{
    int len = strlen(src);
    for (int i = 0; i < len / 2; i++) {//int ³ª´°¼ÀÀÇ ¼Ò¼ö°ªÀº ¹ö·ÁÁü
        int temp = src[i];
        src[i] = src[len - i - 1];
        src[len - i - 1] = temp;
    }
}