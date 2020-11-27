/******************************************************************************\
 * Curso de Programación 1. Tema 14 (Ficheros de texto)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 27 de noviembre de 2020
 * Resumen: Soluciones a los problemas del tema 14
\******************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

/*
 * Pre:  1 ≤ n ≤ 10
 * Post: Ha escrito en el fichero de nombre «nombreFichero» la tabla de
 *       multiplicar del «n»:
 *
 *            LA TABLA DEL «n»
 *            «n» x  0 =  0
 *            «n» x  1 = «n»
 *            «n» x  2 = ...
 *                 ...
 *            «n» x  9 = ...
 *            «n» x 10 = ...
 *       Si no ha podido escribir el fichero de nombre «nombreFichero», ha
 *       escrito un mensaje de error en «cerr».
 */
void escribirTablaEnFichero(const int n, const string nombreFichero) {
    ofstream f;
    f.open(nombreFichero);
    if (f.is_open()) {
        f << "LA TABLA DEL " << n << endl;
        for (unsigned int i = 0; i <= 10; i++) {
            f << setw(3) << n << " x " << setw(2) << i << " = " 
              << setw(3) << n * i << endl;
        }
        f.close();
    }
    else {
        cerr << "No se ha podido crear el fichero \"" << nombreFichero << "\""
             << endl;
    }
}

/*
 * Programa que solicita un número entero al usuario y escribe en la pantalla la
 * tabla de multiplicar correspondiente a ese número.
 */
int main() {
    int n;
    do {
        cout << "Introduzca un número: ";
        cin >> n;
    } while (n < 1 || n > 10);

    cout << "Nombre del fichero: ";
    string nombreFichero;
    cin >> nombreFichero;

    escribirTablaEnFichero(n, nombreFichero);    
    return 0;
}

