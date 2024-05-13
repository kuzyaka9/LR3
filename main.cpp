/*!
    \file
    \brief Тело программы для ГПСЧ
*/


#include <bits/stdc++.h>
#include "CongMethod.h"
#include "CongMethodCube.h"

using namespace std;

vector<vector<int>> samplesCongCube (20, vector<int> (0));
vector<vector<int>> samplesCong (20, vector<int> (0));




/*!
    \brief Генерация выборок с для сравнения времени генерации
*/
void generatesamples() {
    vector<int> sizes = {1000, 10000, 50000, 100000, 500000, 1000000};
    CongMethod rndCong;
    CongMethodCube rndCongCube;
    ofstream fout("../timestamps.txt");
    for (int i = 0; i < sizes.size(); i++) {
        vector<int> congXor;
        vector<int> congCube;
        vector<int> stdRand;
        
        fout << sizes[i] << " ";

        chrono::steady_clock::time_point time_start; 
        chrono::steady_clock::time_point time_end;
        time_start = chrono::steady_clock::now();

        int r = 7;
        for (int j = 0; j < sizes[i]; j++) {
            congXor.push_back(r);
            r = rndCong.genRandom(r);
        }
        time_end = chrono::steady_clock::now();
        fout <<chrono::duration_cast<chrono::nanoseconds>(time_end - time_start).count() << " ";

        time_start = chrono::steady_clock::now();
        r = 7;
        for (int j = 0; j < sizes.size(); j++) {
            congCube.push_back(r);
            r = rndCongCube.genRandom(r);
        }
        time_end = chrono::steady_clock::now();
        fout <<chrono::duration_cast<chrono::nanoseconds>(time_end - time_start).count() << " ";

        time_start = chrono::steady_clock::now();
        for (int j = 0; j < sizes.size(); j++) {
            long long num = rand() % 2147483647;
            stdRand.push_back(num);
        }
        time_end = chrono::steady_clock::now();
        fout <<chrono::duration_cast<chrono::nanoseconds>(time_end - time_start).count() << " ";
        fout << endl;
    }

    fout.close();
}

/*!
    \brief Генерация выборок с использованием кубического конгруэнтного метода с побитовым XOR-ом
*/
void generateSamplesCongCube(){
    CongMethodCube rnd;

    int r = 7;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 100; j++) {
            samplesCongCube[i].push_back(r);
            r = rnd.genRandom(r);
        }
    }
}

/*!
    \brief Генерация выборок с использованием конгруэнтного метода с побитовым XOR-ом
*/
void generateSamplesCong(){
    CongMethod rnd;

    int r = 7;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 100; j++) {
            samplesCong[i].push_back(r);
            r = rnd.genRandom(r);
        }
    }
}

/*!
    \brief Запись в файл выборок с использованием кубического конгруэнтного метода с побитовым XOR-ом
*/
void writeSampleCubeToFile(){
    ofstream fout("../samplesCongCube.txt");

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 100; j++) {
            fout << samplesCongCube[i][j] << ' ';
        }
        fout << endl;
    }

    fout.close();
}


/*!
    \brief Запись в файл выборок с использованием конгруэнтного метода с побитовым XOR-ом
*/
void writeSampleCongToFile(){
    ofstream fout("../sampleCong.txt");

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 100; j++) {
            fout << samplesCong[i][j] << ' ';
        }
        fout << endl;
    }

    fout.close();
}

int main(){
    generateSamplesCongCube();
    generateSamplesCong();
    writeSampleCubeToFile();
    writeSampleCongToFile();
    //generatesamples();
}