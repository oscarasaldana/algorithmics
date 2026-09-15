#include <iostream>

using namespace std;

#include "recursion.h"

void mostrarMina(int (*mina)[columna]) {

    for (int i = 0; i < fila; i++) {
        for (int a = 0; a < columna; a++) {
            if (mina[i][a] == 0) cout << " . ";
            else cout << " * ";
        }
        cout << endl;
    }

}


bool recursion(int (*mina)[columna], int posFila, int posColumna, int numCamino) {

    if (posFila >= fila or posFila < 0 or mina[posFila][posColumna] != 0) return false;

    mina[posFila][posColumna] = numCamino;
    if (posColumna == columna - 1) {
        numCamino++;
        recursion(mina,posFila - 1,0,numCamino);
        return true;
    }

    if (recursion(mina,posFila + 1,posColumna,numCamino)) return true;
    if (recursion(mina,posFila,posColumna + 1,numCamino)) return true;
    if (recursion(mina,posFila - 1,posColumna,numCamino)) return true;

    mina[posFila][posColumna] = 0;
    return false;

}

void mostrarCaminos(int (*mina)[columna]) {

    for (int i = 0; i < fila; i++) {
        for (int a = 0; a < columna; a++) {
            if (mina[i][a] == 0) cout << " . ";
            else if (mina[i][a] == -1) cout << " * ";
            else cout << " " << mina[i][a] << " ";
        }
        cout << endl;
    }

}
