/*!
    \file 
    \brief Файл реализации кубического конгруэнтого метода с побитовым XOR-ом
*/


#include "CongMethodCube.h"

using namespace std;

CongMethodCube::CongMethodCube() {
        this->M = 2147483647;
        this->k_1 = 1220703125;
        this->k_2 = 54323;
        this->k_3 = 11;
        this->b = 7;
}

int CongMethodCube::genRandom(int r) {
    long long r_tmp = (this->k_3 * r * r * r + this->k_2 * r * r + this->k_1 * r + this->b) % this->M; 
    return abs(r_tmp ^ r) % M;
}