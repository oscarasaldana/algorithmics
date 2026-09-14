#include <iostream>

using namespace std;

#include "biblioteca/funciones.h"

int main() {

    int informacionControladores[F][C] = {
        {1, 35000, 80, 1},
        {2, 24000, 60, 3},
        {3, 30000, 70, 2},
        {4, 27000, 48, 1},
        {5, 10000, 20, 1},
        {6,  7000, 35, 2},
        {7,  6000, 10, 1},
        {8, 40000, 40, 3}
    };

    int base = 2;
    int numComponentes = 8;

    solucion(informacionControladores,base,numComponentes);

    return 0;
}
