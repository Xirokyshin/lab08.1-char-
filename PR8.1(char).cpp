#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int Count(char* s) // s = �������� �� ������� �����
{
    int k = 0;
    int pos = 0; // pos = ������� ������� ������
    char* t;

    while ((t = strchr(s + pos, 'n'))) // t = �������� �� 'n'
    {
        pos = t - s + 1; // pos = ��������� ������ ���� 'n'
        if (s[pos + 1] == 'o')
            k++;
    }
    return k;
}

char* Change(char* s) // s = �������� �� ������� �����
{
    char* t = new char[2 * 101]; // �������� ���'��� ��� ������ �����
    char* p;
    int pos1 = 0; // pos1 = ������� ������� ������
    int pos2 = 0;
    t[0] = '\0'; // ���������� ����� �����

    while ((p = strchr(s + pos1, 'n'))) // p = �������� �� 'n'
    {
        if (s[p - s + 2] == 'o')
        {
            pos2 = p - s + 3; // pos2 = ������� ���������� ������� ���� 'o'
            strncat(t, s + pos1, pos2 - pos1 - 3); // ������� �� 'n'
            strcat(t, "**"); // ������ '**'
            pos1 = pos2; // ��������� �������
        }
        else
        {
            pos2 = p - s + 1; // pos2 = ������� ���������� ������� ���� 'n'
            strncat(t, s + pos1, pos2 - pos1); // ������� �� 'n'
            pos1 = pos2; // ��������� �������
        }
    }
    strcat(t, s + pos1); // ������ ������� �����
    strcpy(s, t); // ������� ����� � �������� �����
    return t; // ��������� ����� �����
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str) << " groups of 'n?o'" << endl;

    char* dest = Change(str); // ������ ������� ���� �����
    cout << "Modified string (result): " << dest << endl;

    delete[] dest; // ��������� ���'��
    return 0;
}
