/*!
    \file 
    \brief Заголовочный файл с описанием класса генератора конгруэнтого метода с  побитовым XOR-ом
*/


#ifndef CONGMETHOD_H
#define CONGMETHOD_H

#include <bits/stdc++.h>

/*!
    \brief Класс генератор
    \param M Модуль
    \param k Множитель перед первой степенью
    \param b Приращение
*/
class CongMethod {
private:
    long long M;
    long long k;
    int b;

public:

/*!
    \brief Конструктор
*/
    CongMethod();

/*!
    \brief Метод генерация псевдослучайного числа
    \param r Начальное значение
*/
    int genRandom(int r);
};

#endif