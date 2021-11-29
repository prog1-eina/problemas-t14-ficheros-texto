/******************************************************************************\
 * Curso de Programación 1. Tema 14 (Ficheros de texto)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 29 de noviembre de 2021
 * Resumen: Soluciones a los problemas del tema 14: frecuencias de letras
\******************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


/*
 * Pre:  «nombreFichero» es el nombre de un fichero de texto válido y el número
 *       de componentes de la tabla «frecuencias» es igual al número de letras
 *       del alfabeto inglés.
 * Post: Ha asignado a la tabla «frecuencias» el número de apariciones de cada
 *       una de las letras del alfabeto inglés en el fichero cuyo nombre es
 *       «nombreFichero», no estableciendo diferencias entre mayúsculas y
 *       minúsculas.
 */
void analizar(const string nombreFichero, unsigned frecuencias[]) {
    // Inicializa la tabla de frecuencias
    for (char c = 'A'; c <= 'Z'; c++) {
        frecuencias[c - 'A'] = 0;
    }

    ifstream f;                     // Declara un flujo de entrada
    f.open(nombreFichero);          // Lo asocia al fichero nombreFichero
    if (f.is_open()) {
        char c;
        while (f.get(c)) {
        // Mientras el último intento de lectura fue correcto
            // Contabiliza el carácter si y solo si es alfabético
            if (isalpha(c)) {
                frecuencias[toupper(c) - 'A']++;
            }
        }
        f.close();                  // Libera el fichero y lo disocia de f
    }
    else {
        cerr << "No se ha podido leer del fichero \"" << nombreFichero
             << "\"." << endl;
    }
}


/*
 * Pre:  ---
 * Post: Ha escrito en la pantalla una tabla con las frecuencias de apariciones
 *       de las letras según los valores de la tabla «frecuencias». La primera
 *       componente de la tabla es el número de veces que aparece la letra A, la
 *       segunda, la letra B y así sucesivamente.
 */
void escribirFrecuencias(const unsigned frecuencias[]) {
    for (char letra = 'A'; letra <= 'Z'; letra++) {
        cout << letra << ": " << setw(7) << frecuencias[letra - 'A'] << endl;
    }
}


/* Programa de prueba */
int main() {
    const unsigned NUM_LETRAS = 'Z' - 'A' + 1;
    unsigned frecuencias[NUM_LETRAS];
    analizar("quijote.txt", frecuencias);
    escribirFrecuencias(frecuencias);
    return 0;
}
