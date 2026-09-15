#include <iostream>

using namespace std;

#include "biblioteca/funciones.h"

int main() {

    int recursoSeguridad[10][3] = {
        {1, 50, 120},
        {2, 40, 110},
        {3, 80, 140},
        {4, 70, 130},
        {5, 85, 160},
        {6, 140, 250},
        {7, 55, 100},
        {8, 130, 240},
        {9, 30, 90},
        {10, 150, 300}
    };

    int recursoNecesarioPrevio[10][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
        {1, 0, 0},
        {1, 0, 0},
        {1, 2, 0},
        {0, 2, 0},
        {1, 0, 3},
        {0, 0, 0},
        {1, 2, 3}
    };

    solucion(recursoSeguridad,recursoNecesarioPrevio,2,10);

    return 0;
}

