#include <iostream>
#include <cmath>

using namespace std;

#include "funciones.h"

void solucion(int (*informacionControladores)[C], int base, int numComponentes) {

    int numero[numComponentes];
    int numPresupuesto, numBeneficio, numFalsosNegativos,
        sumPresupuesto, sumBeneficio, sumFalsosNegativos;
    int numCombinaciones = pow(base, numComponentes) - 1;

    cin >> numPresupuesto >> numBeneficio >> numFalsosNegativos;
    for (int i = 0; i < numCombinaciones; i++) {
        generarNumero(numero,base,numComponentes,i);
        sumPresupuesto = 0;
        sumBeneficio = 0;
        sumFalsosNegativos = 0;
        for (int m = 0; m < numComponentes; m++) {
            if (numero[m] != 0) {
                sumPresupuesto += informacionControladores[m][1];
                sumBeneficio += informacionControladores[m][2];
                sumFalsosNegativos += informacionControladores[m][3];
            }
        }
        if ((sumPresupuesto <= numPresupuesto) and (sumBeneficio >= numBeneficio) and
            (sumFalsosNegativos <= numFalsosNegativos)) {
            cout << "Recursos: ";
            for (int m = 0; m < numComponentes; m++) {
                if (numero[m] != 0) {
                    cout << informacionControladores[m][0] << " ";
                }
            }
            cout << endl;
        }
    }

}

void generarNumero(int *numero, int base, int numComponentes, int num) {

    int m;

    for (m = 0; m < numComponentes; m++) numero[m] = 0;
    m = 0;
    while (num != 0) {
        numero[m++] = num % base;
        num = num / base;
    }

}
