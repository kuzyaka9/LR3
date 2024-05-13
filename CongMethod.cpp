/*!
    \file 
    \brief Файл реализации конгруэнтого метода с  побитовым XOR-ом
*/

#include "CongMethod.h"

using namespace std;

CongMethod::CongMethod() {
        this->M = 2147483647;
        this->k = 1220703125;
        this->b = 7;
}

int CongMethod::genRandom(int r) {
    long long r_tmp = (this->k * r + this->b) % this->M; 
    return abs(r_tmp ^ r) % M;
}