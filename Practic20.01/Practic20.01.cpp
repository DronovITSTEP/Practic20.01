#include <iostream>

using namespace std;

/*
Дана строка символов. Заменить в ней все пробелы на символ табуляции
*/
void f1() {
    char* str = new char[255];
    gets_s(str, 255);
    int l = strlen(str)+1;

    char* res_str = nullptr;
    char* word = new char[125];
    char* p = nullptr;
    while (p = strchr(str, ' ')) {
        strncpy_s(word, 125, str, strlen(str) - strlen(p));
        if (res_str) 
            strcat_s(res_str, l, word);
        else {
            res_str = new char[l];
            strcpy_s(res_str, l, word);
        }
        strcat_s(res_str, l, "\t");
        str += strlen(word) + 1;
    }
    if (res_str) strcat_s(res_str, l, str);
    puts(res_str);
    delete[]word;
    delete[]res_str;
}

/*
Подсчитать кол-во слов во введенном предложении
*/
void f2() {
    int count = 1;
    char* str = new char[255];
    gets_s(str, 256);

    /*for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') count++;
    }*/
    /*char* p = str;
    while (p = strchr(p, ' ')) {
        count++;
        p++;
    }*/

    for (char* p = str; p = strchr(p, ' '); p++) {
        count++;
    }

    cout << count;
}

/*
Дана строка символов. Определить количество
букв, цифр и остальных символов, присутствующих в
строке.
*/
void f3(){
    char* str = new char[255];
    gets_s(str, 255);
    int alpha = 0, digit = 0, other = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) alpha++;
        else if (isdigit(str[i])) digit++;
        else other++;
    }
    cout << alpha << endl << digit << endl << other;
}

/*
Дана строка символов. Необходимо проверить
является ли эта строка палиндромом.
*/
void f4(){
    char* str = new char[125] {"rtt t tr"};
    size_t count = 0;
    char* p = str;
    while (p = strchr(p, ' ')) {
        count++;
        p++;
    }

    size_t size = strlen(str) - count + 1;
    char* newstr = new char[size];
    p = str;

    char* temp = strchr(p, ' ');
    strncpy_s(newstr, size, p, strlen(p) - strlen(temp));
    p = temp + 1;

    while (temp = strchr(p, ' '))
    {
        strncat_s(newstr, size, p, strlen(p) - strlen(temp));
        p = temp + 1;
    }
    strcat_s(newstr, size, p);

    char* revstr = new char[size];
    strcpy_s(revstr, size, newstr);
    if (!_stricmp(newstr,_strrev(revstr))) cout << "Yes";
    else cout << "No";
}

int main()
{
    //setlocale(LC_ALL, "");
    //f1();
    //f2();
    //f3();
    f4();
}
