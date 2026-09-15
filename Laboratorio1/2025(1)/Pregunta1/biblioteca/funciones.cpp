#include <iostream>
#include <cmath>

using namespace std;

#include "funciones.h"

void solucion(int *tablas, int *discos, int base, int cantTablas) {

    int numero[6] {}, espacioDiscos[3] {};
    int numDisco, espacioTabla, espacioMinimo, elegido, discoMenorMemoria,
        discoMenorMemoriaMayor, espacioMinimoMayor = 0
    ;
    int cantCombinaciones = pow(base, cantTablas) - 1;
    bool opcionValida;

    for (int i = 0; i < cantCombinaciones; i++) {
        generarNumero(numero,base,cantTablas,i);
        for (int a = 0; a < 3; a++) espacioDiscos[a] = discos[a];
        opcionValida = true;
        for (int a = 0; a < cantTablas; a++) {
            numDisco = numero[a];
            espacioTabla = tablas[a];
            espacioDiscos[numDisco] -= espacioTabla;
        }
        for (int a = 0; a < cantTablas; a++) {
            if (espacioDiscos[a] == discos[a] or espacioDiscos[a] < 0) {
                opcionValida = false;
                break;
            }
        }
        if (opcionValida== true) {
            espacioMinimo = encontrarEspacioMinimo(espacioDiscos,discoMenorMemoria);
            if (espacioMinimoMayor < espacioMinimo) {
                espacioMinimoMayor = espacioMinimo;
                discoMenorMemoriaMayor = discoMenorMemoria;
                elegido = i;
            }
        }
    }

    generarNumero(numero,base,cantTablas,elegido);
    for (int i = 0; i < cantTablas; i++) {
        cout << "Disco " << numero[i] + 1 << ": " << i + 1 << endl;
    }
    cout << "La solucion tiene una velocidad minima e grupo de " << espacioMinimoMayor
         << " que se da en el disco " << discoMenorMemoriaMayor + 1 << endl
     ;

}

void generarNumero(int *numero, int base, int cantTablas, int num) {

    int a = 0;

    for (int i = 0; i < cantTablas; i++) numero[i] = 0;
    while (num > 0) {
        numero[a] = num % base;
        num = num / base;
        a++;
    }

}

int encontrarEspacioMinimo(int *espacioDiscos, int &discoMenorMemoria) {

    int espacioMinimo = 250;

    for (int i = 0; i < 3; i++) {
        if (espacioMinimo > espacioDiscos[i] and espacioMinimo > 0) {
            discoMenorMemoria = i;
            espacioMinimo = espacioDiscos[i];
        }
    }

    return espacioMinimo;

}
