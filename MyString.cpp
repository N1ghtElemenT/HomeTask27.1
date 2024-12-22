#include <iostream>
#include "MyString.h"
using namespace std;

int MyString::count = 0;

void MyString::copyConstructor(char* dest, const char* src) const 
{
    while (*src) 
    {
        *dest++ = *src++;
    }
    *dest = '\0';
}

MyString::MyString() : length(80) 
{
    str = new char[length + 1];
    str[0] = '\0';
    count++;
}

MyString::MyString(int size) : length(size) 
{
    str = new char[length + 1];
    str[0] = '\0';
    count++;
}

MyString::MyString(const char* inputStr) 
{
    length = strlen(inputStr);
    str = new char[length + 1];
    copyConstructor(str, inputStr);
    count++;
}

MyString::~MyString() 
{
    delete[] str;
    count--;
}

void MyString::Input() 
{
    char temp[1000];
    cout << "Enter a string: ";
    cin.getline(temp, 1000);
    length = strlen(temp);
    delete[] str;
    str = new char[length + 1];
    copyConstructor(str, temp);
}

void MyString::Output() const 
{
    cout << "String: " << (str ? str : "(empty string)") << endl;
}

void MyString::MyStrcpy(MyString& obj) 
{
    obj.length = length;
    delete[] obj.str;
    obj.str = new char[length + 1];
    copyConstructor(obj.str, str);
}

bool MyString::MyStrStr(const char* substring) 
{
    return strstr(str, substring) != nullptr;
}

int MyString::MyChr(char c) 
{
    for (int i = 0; i < length; ++i) 
    {
        if (str[i] == c) 
        {
            return i;
        }
    }
    return -1;
}

int MyString::MyStrLen() 
{
    return static_cast<int>(length);
}

void MyString::MyStrCat(MyString& b) 
{
    size_t newLength = length + b.length;
    char* newStr = new char[newLength + 1];
    copyConstructor(newStr, str);
    strncat_s(newStr, newLength + 1, b.str, b.length);
    delete[] str;
    str = newStr;
    length = newLength;
}

void MyString::MyDelChr(char c) 
{
    if (!str)
    {
        return;
    }

    int newLength = 0;
    for (int i = 0; i < length; ++i) 
    {
        if (str[i] != c) 
        {
            str[newLength++] = str[i];
        }
    }
    str[newLength] = '\0';
    length = newLength;
}

int MyString::MyStrCmp(MyString& b) {
    int result = strcmp(str, b.str);
    if (result < 0)
    {
        return -1;
    }
    else if (result > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int MyString::GetCount() {
    return count;
}