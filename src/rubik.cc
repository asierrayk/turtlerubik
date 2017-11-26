#include "rubik.h"
#include <stdio.h>
#include <iostream>

Rubik::Rubik()
{
    for (int k = 0; k < kSize; ++k) {
        for (int j = 0; j < kSize; ++j) {
            for (int i = 0; i < kSize; ++i) {
                std::string id_str = std::to_string(k) + std::to_string(j) + std::to_string(i);
                id[i][j][k] = std::stoi(id_str,nullptr,3);
                orientation[i][j][k] = 0;
            }
        }
    }
}

Rubik::~Rubik()
{

}

void Rubik::ShowState(){
    std::cout << "IDS" << std::endl;
    for (int k = 0; k < kSize; ++k) {
        for (int j = 0; j < kSize; ++j) {
            for (int i = 0; i < kSize; ++i) {
                std::cout << id[i][j][k] << " "; 
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << "ORIENTATIONS" << std::endl;
    for (int k = 0; k < kSize; ++k) {
        for (int j = 0; j < kSize; ++j) {
            for (int i = 0; i < kSize; ++i) {
                std::cout << orientation[i][j][k] << " "; 
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void Rubik::cycle(short int &c1, short int &c2, short int &c3, short int &c4){
    short int tmp = c1;
    c1 = c4;
    c4 = c3;
    c3 = c2;
    c2 = tmp;
}

void Rubik::cycleCornerOrientation(short int &c1, short int &c2, short int &c3, short int &c4){
    short int tmp = (c1 + 1) % 3;
    c1 = (c4 - 1) % 3;
    c4 = (c3 + 1) % 3;
    c3 = (c2 - 1) % 3;
    c2 = tmp;
}

void Rubik::cycleEdgeOrientation(short int &c1, short int &c2, short int &c3, short int &c4){
    short int tmp = (c1 + 1) % 2;
    c1 = (c4 + 1) % 2;
    c4 = (c3 + 1) % 2;
    c3 = (c2 + 1) % 2;
    c2 = tmp;
}

void Rubik::B(){
    int z = 0;
    cycle(id[0][0][z], id[0][2][z], id[2][2][z], id[2][0][z]);
    cycleCornerOrientation(orientation[0][0][z], orientation[0][2][z], orientation[2][2][z], orientation[2][0][z]);

    cycle(id[1][0][z], id[0][1][z], id[1][2][z], id[2][1][z]);
    cycleEdgeOrientation(orientation[1][0][z], orientation[0][1][z], orientation[1][2][z], orientation[2][1][z]);
}

void Rubik::B3(){
    int z = 0;
    cycle(id[0][0][z], id[2][0][z], id[2][2][z], id[0][2][z]);
    cycleCornerOrientation(orientation[0][0][z], orientation[2][0][z], orientation[2][2][z], orientation[0][2][z]);

    cycle(id[1][0][z], id[2][1][z], id[1][2][z], id[0][1][z]);
    cycleEdgeOrientation(orientation[1][0][z], orientation[2][1][z], orientation[1][2][z], orientation[0][1][z]);
}

/* void Rubik::B2(){ */
/*     int z = 0; */
/*     std::swap(id[0][0][z], id[2][2][z]); */
/*     std::swap(id[0][2][z], id[2][0][z]); */

/*     std::swap(id[1][0][z], id[1][2][z]); */
/*     std::swap(id[0][1][z], id[2][1][z]); */
/* } */

void Rubik::D(){
    int y = 2;
    cycle(id[0][y][0], id[0][y][2], id[2][y][2], id[2][y][0]);
    cycle(orientation[0][y][0], orientation[0][y][2], orientation[2][y][2], orientation[2][y][0]);

    cycle(id[0][y][1], id[1][y][2], id[2][y][1], id[1][y][0]);
    cycle(orientation[0][y][1], orientation[1][y][2], orientation[2][y][1], orientation[1][y][0]);
}

void Rubik::D3(){
    int y = 2;
    cycle(id[0][y][0], id[2][y][0], id[2][y][2], id[0][y][2]);
    cycle(orientation[0][y][0], orientation[2][y][0], orientation[2][y][2], orientation[0][y][2]);

    cycle(id[0][y][1], id[1][y][0], id[2][y][1], id[1][y][2]);
    cycle(orientation[0][y][1], orientation[1][y][0], orientation[2][y][1], orientation[1][y][2]);
}

/* void Rubik::D2(){ */
/*     int y = 2; */
/*     cycle(id[0][y][0], id[2][y][0], id[2][y][2], id[0][y][2]); */
/*     cycle(orientation[0][y][0], orientation[2][y][0], orientation[2][y][2], orientation[0][y][2]); */

/*     cycle(id[0][y][1], id[1][y][0], id[2][y][1], id[1][y][2]); */
/*     cycle(orientation[0][y][1], orientation[1][y][0], orientation[2][y][1], orientation[1][y][2]); */
/* } */

void Rubik::F(){
    int z = 2;
    cycle(id[0][0][z], id[2][0][z], id[2][2][z], id[0][2][z]);
    cycleCornerOrientation(orientation[0][0][z], orientation[2][0][z], orientation[2][2][z], orientation[0][2][z]);

    cycle(id[1][0][z], id[2][1][z], id[1][2][z], id[0][1][z]);
    cycleEdgeOrientation(orientation[1][0][z], orientation[2][1][z], orientation[1][2][z], orientation[0][1][z]);
}

void Rubik::F3(){
    int z = 2;
    cycle(id[0][0][z], id[0][2][z], id[2][2][z], id[2][0][z]);
    cycleCornerOrientation(orientation[0][0][z], orientation[0][2][z], orientation[2][2][z], orientation[2][0][z]);

    cycle(id[1][0][z], id[0][1][z], id[1][2][z], id[2][1][z]);
    cycleEdgeOrientation(orientation[1][0][z], orientation[0][1][z], orientation[1][2][z], orientation[2][1][z]);
}

/* void Rubik::F2(){ */
/*     int z = 2; */
/*     cycle(id[0][0][z], id[2][0][z], id[2][2][z], id[0][2][z]); */
/*     cycleCornerOrientation(orientation[0][0][z], orientation[2][0][z], orientation[2][2][z], orientation[0][2][z]); */

/*     cycle(id[1][0][z], id[2][1][z], id[1][2][z], id[0][1][z]); */
/*     cycleEdgeOrientation(orientation[1][0][z], orientation[2][1][z], orientation[1][2][z], orientation[0][1][z]); */
/* } */

void Rubik::L(){
    int x = 0;
    cycle(id[x][0][0], id[x][0][2], id[x][2][2], id[x][2][0]);
    cycleCornerOrientation(orientation[x][0][0], orientation[x][0][2], orientation[x][2][2], orientation[x][2][0]);

    cycle(id[x][0][1], id[x][1][2], id[x][2][1], id[x][1][0]);
    cycleEdgeOrientation(orientation[x][0][1], orientation[x][1][2], orientation[x][2][1], orientation[x][1][0]);
}

void Rubik::L3(){
    int x = 0;
    cycle(id[x][0][0], id[x][2][0], id[x][2][2], id[x][0][2]);
    cycleCornerOrientation(orientation[x][0][0], orientation[x][2][0], orientation[x][2][2], orientation[x][0][2]);

    cycle(id[x][0][1], id[x][1][0], id[x][2][1], id[x][1][2]);
    cycleEdgeOrientation(orientation[x][0][1], orientation[x][1][0], orientation[x][2][1], orientation[x][1][2]);
}

/* void Rubik::L2(){ */
/*     int x = 0; */
/*     cycle(id[x][0][0], id[x][0][2], id[x][2][2], id[x][2][0]); */
/*     cycleCornerOrientation(orientation[x][0][0], orientation[x][0][2], orientation[x][2][2], orientation[x][2][0]); */

/*     cycle(id[x][0][1], id[x][1][2], id[x][2][1], id[x][1][0]); */
/*     cycleEdgeOrientation(orientation[x][0][1], orientation[x][1][2], orientation[x][2][1], orientation[x][1][0]); */
/* } */

void Rubik::R(){
    int x = 2;
    cycle(id[x][0][0], id[x][2][0], id[x][2][2], id[x][0][2]);
    cycleCornerOrientation(orientation[x][0][0], orientation[x][2][0], orientation[x][2][2], orientation[x][0][2]);

    cycle(id[x][0][1], id[x][1][0], id[x][2][1], id[x][1][2]);
    cycleEdgeOrientation(orientation[x][0][1], orientation[x][1][0], orientation[x][2][1], orientation[x][1][2]);
}

void Rubik::R3(){
    int x = 2;
    cycle(id[x][0][0], id[x][0][2], id[x][2][2], id[x][2][0]);
    cycleCornerOrientation(orientation[x][0][0], orientation[x][0][2], orientation[x][2][2], orientation[x][2][0]);

    cycle(id[x][0][1], id[x][1][2], id[x][2][1], id[x][1][0]);
    cycleEdgeOrientation(orientation[x][0][1], orientation[x][1][2], orientation[x][2][1], orientation[x][1][0]);
}

/* void Rubik::R2(){ */
/*     int x = 2; */
/*     cycle(id[x][0][0], id[x][0][2], id[x][2][2], id[x][2][0]); */
/*     cycleCornerOrientation(orientation[x][0][0], orientation[x][0][2], orientation[x][2][2], orientation[x][2][0]); */

/*     cycle(id[x][0][1], id[x][1][2], id[x][2][1], id[x][1][0]); */
/*     cycleEdgeOrientation(orientation[x][0][1], orientation[x][1][2], orientation[x][2][1], orientation[x][1][0]); */
/* } */

void Rubik::U3(){
    int y = 0;
    cycle(id[0][y][0], id[0][y][2], id[2][y][2], id[2][y][0]);
    cycle(orientation[0][y][0], orientation[0][y][2], orientation[2][y][2], orientation[2][y][0]);

    cycle(id[0][y][1], id[1][y][2], id[2][y][1], id[1][y][0]);
    cycle(orientation[0][y][1], orientation[1][y][2], orientation[2][y][1], orientation[1][y][0]);
}

void Rubik::U(){
    int y = 0;
    cycle(id[0][y][0], id[2][y][0], id[2][y][2], id[0][y][2]);
    cycle(orientation[0][y][0], orientation[2][y][0], orientation[2][y][2], orientation[0][y][2]);

    cycle(id[0][y][1], id[1][y][0], id[2][y][1], id[1][y][2]);
    cycle(orientation[0][y][1], orientation[1][y][0], orientation[2][y][1], orientation[1][y][2]);
}

/* void Rubik::U2(){ */
/*     int y = 0; */
/*     cycle(id[0][y][0], id[2][y][0], id[2][y][2], id[0][y][2]); */
/*     cycle(orientation[0][y][0], orientation[2][y][0], orientation[2][y][2], orientation[0][y][2]); */

/*     cycle(id[0][y][1], id[1][y][0], id[2][y][1], id[1][y][2]); */
/*     cycle(orientation[0][y][1], orientation[1][y][0], orientation[2][y][1], orientation[1][y][2]); */
/* } */
