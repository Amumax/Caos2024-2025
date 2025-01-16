#include <iostream>
using namespace std;

int main() {
    int *ptr = nullptr; // Указатель, инициализированный нулевым значением

    *ptr = 42; // Попытка записи значения по адресу, на который указывает ptr, вызывает ошибку сегментации

    return 0;
}