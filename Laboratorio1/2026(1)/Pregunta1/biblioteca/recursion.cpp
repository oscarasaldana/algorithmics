#include <iostream>

using namespace std;

#include "recursion.h"

void recursion(int (*area)[columna], int posFila, int posColumna, int limite, int i, int &contador) {

    int filaEspejo;

    if (limite < 0) return;
  
    filaEspejo = posFila;
    if (area[posFila - i][posColumna - i] == 1) {
        contador++;
        area[posFila - i][posColumna - i] = 0;
    }
    if (area[posFila - i][posColumna + i] == 1) {
        contador++;
        area[posFila - i][posColumna + i] = 0;
    }
    if (area[filaEspejo + i][posColumna - i] == 1) {
        contador++;
        area[filaEspejo + i][posColumna - i] = 0;
    }
    if (area[filaEspejo + i][posColumna + i] == 1) {
        contador++;
        area[filaEspejo + i][posColumna + i] = 0;
    }
    if (i == limite) {
        i = -1;
        posFila--;
        filaEspejo++;
        limite--;
    }
    recursion(area,posFila,posColumna,limite,i + 1,contador);

}
