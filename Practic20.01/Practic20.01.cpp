#include <iostream>

using namespace std;

/*
Дана строка символов. Заменить в ней все пробелы на символ табуляции
*/
void f1() {
    char* str = new char[255];
    gets_s(str, 255);
    int l = strlen(str);

    char* res_str = nullptr;
    char* word = new char[125];
    char* p = nullptr;
    while (p = strchr(str, ' ')) {
        strncpy_s(word, 125, str, strlen(str) - strlen(p));
        if (res_str) 
            strcat_s(res_str, strlen(res_str) + strlen(word) + 1, word);
        else {
            res_str = new char[strlen(str)];
            strcpy_s(res_str, strlen(word) + 1, word);
        }
        strcat_s(res_str, strlen(res_str) + sizeof(char) + 1, "\t");
        str += strlen(word) + 1;
    }
    if (res_str) strcat_s(res_str, strlen(res_str) + strlen(str)+1, str);
    puts(res_str);
    puts(str - l-1);
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
    char* rev_str = new char[strlen(str)+1];
    char* str2 = nullptr;
    
    strcpy_s(rev_str, 126, str);
    char* rev_str2 = rev_str;

    while (rev_str2 = strchr(rev_str2, ' ')) {
        if (str2) strcat_s(str2, strlen(str2) + strlen(rev_str2)+1,
            rev_str);
        else {
            str2 = new char[strlen(str) + 1];
            strncpy_s(str2, strlen(rev_str) + strlen(rev_str2) + 1,
                rev_str, strlen(rev_str) - strlen(rev_str2));
        }
        rev_str2++;
    }
    
    _strrev(str);
    cout << str << " " << rev_str << endl;
    if (_stricmp(str, rev_str) == 0) cout << "Yes";
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
