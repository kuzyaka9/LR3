/*!
    \file 
    \brief Заголовочный файл с описанием класса генератора кубического конгруэнтого метода с побитовым XOR-ом
*/


#ifndef CONGMETHODCUBE_H
#define CONGMETHODCUBE_H

#include <bits/stdc++.h>


/*!
    \brief Класс генератор
    \param M Модуль
    \param k_1 Множитель перед первой степенью
    \param k_2 Множитель перед второй степенью
    \param k_3 Множитель перед третей степенью
    \param b Приращение
*/
class CongMethodCube {
private:
    long long M;
    long long k_1;
    long long k_2;
    long long k_3;
    int b;

public:
/*!
    \brief Конструктор
*/
    CongMethodCube();

/*!
    \brief Метод генерация псевдослучайного числа
    \param r Начальное значение
*/
    int genRandom(int r);
};

#endif