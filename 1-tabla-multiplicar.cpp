/******************************************************************************
 * Curso de Programación 1. Tema 14 (Ficheros de texto)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 3 de Diciembre de 2020
 * Resumen: Soluciones a los problemas del tema 14
 * Nota: El programa completo está contenido en este fichero, por lo que puede
 *       compilarse y ejecutarse con la extensión Code Runner de Visual Studio
 *       Code.
 *       También puede compilarse desde la terminal través de la orden
 *           g++ -Wall -Wextra 1-tabla-multiplicar.cpp -o 1-tabla-multiplicar
 *       y ejecutarse en Windows a través de la orden
 *           .\1-tabla-multiplicar.exe
 *       o en Linux y macOS
 *           ./1-tabla-multiplicar
 *****************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

/*
 * Pre:  1 ≤ n ≤ 10
 * Post: Escribe en el fichero de nombre «nombreFichero» la tabla de
 *       multiplicar del «n»:
 *
 *            LA TABLA DEL «n»
 *            «n» x  0 =  0
 *            «n» x  1 = «n»
 *            «n» x  2 = ...
 *                 ...
 *            «n» x  9 = ...
 *            «n» x 10 = ...
 *       Si no puede escribir el fichero de nombre «nombreFichero», escribe un
 *       mensaje de error en «cerr».
 */
void escribirTablaEnFichero(const int n, const string nombreFichero) {
    ofstream f;
    f.open(nombreFichero);
    if (f.is_open()) {
        f << "LA TABLA DEL " << n << endl;
        for (unsigned i = 0; i <= 10; i++) {
            f << setw(3) << n << " x " << setw(2) << i << " = " 
              << setw(3) << n * i << endl;
        }
        f.close();
    } else {
        cerr << "No se ha podido crear el fichero \"" << nombreFichero << "\"."
             << endl;
    }
}

/*
 * Programa que solicita un número entero entre 1 y 10 y el nombre de un 
 * fichero y guarda en el fichero con el nombre introducido por el usuario la
 * tabla de  multiplicar correspondiente a ese número.
 */
int main() {
    int n;
    do {
        cout << "Introduzca un número: ";
        cin >> n;
    } while (n < 1 || n > 10);
    // 1 <= n <= 10 

    cout << "Nombre del fichero: ";
    string nombreFichero;
    cin >> nombreFichero;

    escribirTablaEnFichero(n, nombreFichero);    
    return 0;
}

