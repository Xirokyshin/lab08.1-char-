#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int Count(char* s) // s = вказівник на початок рядка
{
    int k = 0;
    int pos = 0; // pos = позиція початку пошуку
    char* t;

    while ((t = strchr(s + pos, 'n'))) // t = вказівник на 'n'
    {
        pos = t - s + 1; // pos = наступний символ після 'n'
        if (s[pos + 1] == 'o')
            k++;
    }
    return k;
}

char* Change(char* s) // s = вказівник на початок рядка
{
    char* t = new char[2 * 101]; // Збільшуємо пам'ять для нового рядка
    char* p;
    int pos1 = 0; // pos1 = позиція початку пошуку
    int pos2 = 0;
    t[0] = '\0'; // Ініціалізуємо новий рядок

    while ((p = strchr(s + pos1, 'n'))) // p = вказівник на 'n'
    {
        if (s[p - s + 2] == 'o')
        {
            pos2 = p - s + 3; // pos2 = позиція наступного символа після 'o'
            strncat(t, s + pos1, pos2 - pos1 - 3); // Копіюємо до 'n'
            strcat(t, "**"); // Додаємо '**'
            pos1 = pos2; // Оновлюємо позицію
        }
        else
        {
            pos2 = p - s + 1; // pos2 = позиція наступного символа після 'n'
            strncat(t, s + pos1, pos2 - pos1); // Копіюємо до 'n'
            pos1 = pos2; // Оновлюємо позицію
        }
    }
    strcat(t, s + pos1); // Додаємо залишок рядка
    strcpy(s, t); // Копіюємо назад у вихідний рядок
    return t; // Повертаємо новий рядок
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str) << " groups of 'n?o'" << endl;

    char* dest = Change(str); // Виклик функції зміни рядка
    cout << "Modified string (result): " << dest << endl;

    delete[] dest; // Звільнення пам'яті
    return 0;
}
