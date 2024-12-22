#pragma once
#include <iostream>
using namespace std;

class MyString 
{
    char* str;
    size_t length;
    static int count;
    void copyConstructor(char* dest, const char* src) const;
public:
    MyString();
    MyString(int size);
    MyString(const char* inputStr);
    ~MyString();
    void Input();
    void Output() const;
    void MyStrcpy(MyString& obj);
    bool MyStrStr(const char* substring);
    int MyChr(char c);
    int MyStrLen();
    void MyStrCat(MyString& b);
    void MyDelChr(char c);
    int MyStrCmp(MyString& b);
    static int GetCount();
};
