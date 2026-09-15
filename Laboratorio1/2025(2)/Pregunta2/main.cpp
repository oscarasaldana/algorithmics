#include <iostream>

using namespace std;

#include "biblioteca/recursion.h"

int main() {

    int mina[fila][columna] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    //Piedras
    mina[5][5] = -1;
    mina[4][5] = -1;
    mina[3][5] = -1;

    mostrarMina(mina);
    recursion(mina,5,0,1);
    cout << endl;
    mostrarCaminos(mina);

}
