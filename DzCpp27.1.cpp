#include <iostream>
#include "MyString.h"
using namespace std;

int main() {
    MyString str1;
    str1.Input();
    str1.Output();

    MyString str2;
    str2.Input();
    str2.Output();

    int len;
    cout << "Enter the length for the string: ";
    cin >> len;
    cin.ignore();
    MyString str3(len);
    str3.Input();
    str3.Output();

    int choice;
    do 
    {
        cout << "\nEnter your choice" << endl;
        cout << "1: Copy a string (str1 -> str3)" << endl;
        cout << "2: Find a substring in any string" << endl;
        cout << "3: Find a character in any string" << endl;
        cout << "4: Concatenate a string with any string" << endl;
        cout << "5: Delete a character from any string" << endl;
        cout << "6: Compare two strings" << endl;
        cout << "7: Display object count" << endl;
        cout << "8: Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore();

        MyString* selectedStr = nullptr;

        cout << "Select a string (1 for str1, 2 for str2, 3 for str3): ";
        int stringChoice;
        cin >> stringChoice;
        cin.ignore();
        switch (stringChoice) 
        {
        case 1:
            selectedStr = &str1;
            break;
        case 2:
            selectedStr = &str2;
            break;
        case 3:
            selectedStr = &str3;
            break;
        default:
            cout << "Invalid string choice!" << endl;
            continue;
        }

        switch (choice) 
        {
        case 1: 
        {
            MyString str4 = *selectedStr;
            cout << "After copying, str4: ";
            str4.Output();
            break;
        }
        case 2: 
        {
            cout << "Enter the substring to search: ";
            char substring[100];
            cin.getline(substring, 100);
            bool found = selectedStr->MyStrStr(substring);
            cout << "Substring found: " << (found ? "Yes" : "No") << endl;
            break;
        }
        case 3: 
        {
            cout << "Enter the character to search: ";
            char c;
            cin >> c;
            int index = selectedStr->MyChr(c);
            cout << "Character found at index: " << index << endl;
            break;
        }
        case 4: 
        {
            cout << "Enter the string to concatenate: ";
            char concatStr[100];
            cin.getline(concatStr, 100);
            MyString temp(concatStr);
            selectedStr->MyStrCat(temp);
            cout << "After concatenation, the string: ";
            selectedStr->Output();
            break;
        }
        case 5: 
        {
            cout << "Enter the character to delete: ";
            char c;
            cin >> c;
            selectedStr->MyDelChr(c);
            cout << "After deletion, the string: ";
            selectedStr->Output();
            break;
        }
        case 6: 
        {
            cout << "Enter the string to compare with: ";
            char compareStr[100];
            cin.getline(compareStr, 100);
            MyString temp(compareStr);
            int cmpResult = selectedStr->MyStrCmp(temp);
            cout << "Comparison result: " << cmpResult << endl;
            break;
        }
        case 7: 
        {
            cout << "Number of objects: " << MyString::GetCount() << endl;
            break;
        }
        case 8:
            cout << "Exiting the program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}