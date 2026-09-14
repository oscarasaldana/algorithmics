#include <iostream>
#include <cmath>

using namespace std;

#include "funciones.h"

void solucion(int (*informacionDientes)[4], int (*informacionCitas)[3], int *duracionCitas,
              int base, int numDientes) {

    int numero[8] {}, tiempoCita[3] {};
    int numCombinaciones, tipoDiente, cantCaries, tiempoCuracion, precioCuracion;
    int gananciaTotal, gananciaMaxima = 0, num, numCitas = 3, cita;
    bool cumple = true;

    numCombinaciones = pow(base, numDientes);
    for (int i = 1; i < numCombinaciones; i++) {
        generarCombinacion(numero,base,numDientes,i);
        for (int a = 0; a < numCitas; a++) tiempoCita[a] = 0;
        gananciaTotal = 0;
        for (int a = 0; a < numDientes; a++) {
            if (numero[a] != 0) {
                cita = numero[a];
                tipoDiente = informacionDientes[a][2];
                cantCaries = informacionDientes[a][3];
                tiempoCuracion = cantCaries * informacionCitas[tipoDiente - 1][1];
                precioCuracion = cantCaries * informacionCitas[tipoDiente - 1][2];
                tiempoCita[cita - 1] += tiempoCuracion;
                gananciaTotal += precioCuracion;
            }
        }
        cumple = true;
        for (int a = 0; a < numCitas; a++) {
            if (tiempoCita[a] > duracionCitas[a] or tiempoCita[a] == 0) {
                cumple = false;
                break;
            }

        }
        if (cumple and gananciaTotal > gananciaMaxima) {
            gananciaMaxima = gananciaTotal;
            num = i;
        }
    }
    generarCombinacion(numero,base,numDientes,num);
    for (int a = 0; a < numDientes; a++) {
        if (numero[a] != 0) {
            cout << "Cita: " << numero[a]  << "  Diente: " << a+1 << endl;
        }
    }
    cout << "La ganancia máxima es: " << gananciaMaxima << endl;

}

void generarCombinacion(int *numero, int base, int numDientes, int num) {

    int i;

    for (i = 0; i < numDientes; i++) numero[i] = 0;
    i = 0;
    while (num != 0) {
        numero[i] = num % base;
        num = num / base;
        i++;
    }

}
