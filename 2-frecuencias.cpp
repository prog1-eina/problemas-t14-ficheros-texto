/******************************************************************************\
 * Curso de Programación 1. Tema 14 (Ficheros de texto)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 26 de noviembre de 2020
 * Resumen: Soluciones a los problemas del tema 14: frecuencias de letras
\******************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
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
void analizar(const char nombreFichero[], int frecuencias[]) {
    // Inicializa la tabla de frecuencias
    for (char c = 'A'; c <= 'Z'; c++) {
        frecuencias[c - 'A'] = 0;
    }

    ifstream f;                     // Declara un flujo de entrada
    f.open (nombreFichero);         // Lo asocia al fichero nombreFichero
    if (f.is_open()) {
        // Intenta leer el 1.er carácter y, si es letra, la pasa a mayúscula
        char c = toupper(f.get());
        while (!f.eof()) {
            // Contabiliza el carácter si y solo si es alfabético
            if (isalpha(c)) {
                frecuencias[c - 'A']++;
            }
            c = toupper(f.get());   // Intenta leer un nuevo carácter
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
void escribirFrecuencias(const int frecuencias[]) {
    for (char letra = 'A'; letra <= 'Z'; letra++) {
        cout << letra << ": " << setw(7) << frecuencias[letra - 'A'] << endl;
    }
}

/* Programa de prueba */
int main() {
    const int NUM_LETRAS = 'Z' - 'A' + 1;
    int frecuencias[NUM_LETRAS];
    analizar("quijote.txt", frecuencias);
    escribirFrecuencias(frecuencias);
}
