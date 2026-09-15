#include <iostream>
#include <cmath>

using namespace std;

#include "funciones.h"

void solucion(int (*recursoSeguridad)[3], int (*recursoNecesarioPrevio)[3], int base, int numRecursos) {

    int numero[10] {};
    int presupuesto, precioTotal, precioRecurso, precioExtra, recursoExtra;
    int numCombinaciones = pow(base, numRecursos) - 1;

    cout << "Ingresa el presupuesto en miles de soles: ";
    cin >> presupuesto;
    for (int i = 0; i < numCombinaciones; i++) {
        generarNumero(numero,base,numRecursos,i);
        precioTotal = 0;
        precioExtra = 0;
        for (int a = 0; a < numRecursos; a++) {
            if (numero[a] != 0) {
                precioRecurso = recursoSeguridad[a][1];
                for (int m = 0; m < 3; m++) {
                    if (recursoNecesarioPrevio[a][m] != 0) {
                        recursoExtra = recursoNecesarioPrevio[a][m];
                        precioExtra += recursoSeguridad[recursoExtra - 1][1];
                    }
                }
                precioTotal += precioRecurso + precioExtra;
            }
        }
        if (precioTotal >= (presupuesto * 0.8) and precioTotal <= presupuesto) {
            cout << "Combinacion " << i << " Costo: " << precioTotal << endl;
        }
    }

}

void generarNumero(int *numero, int base, int numRecursos, int num) {

    int i = 0;

    for (int a = 0; a < numRecursos; a++) numero[a] = 0;
    while (num > 0) {
        numero[i] = num % base;
        num = num / base;
        i++;
    }

}
