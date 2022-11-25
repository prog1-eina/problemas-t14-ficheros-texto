/*********************************************************************************************\
 * Curso de Programación 1. Tema 14 (Ficheros de texto)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 29 de noviembre de 2021
 * Resumen: Soluciones a los problemas del tema 14: frecuencias de letras
 * Nota: El programa completo está contenido en este fichero, por lo que puede compilarse y
 *       ejecutarse con la extensión Code Runner de Visual Studio Code.
 *       También puede compilarse desde la terminal través de la orden
 *           g++ -Wall -Wextra 6-frecuencias.cpp -o 6-frecuencias
 *       y ejecutarse en Windows a través de la orden
 *           .\6-frecuencias.exe
 *       o en Linux y macOS
 *           ./6-frecuencias
\*********************************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


/*
 * Pre:  «nombreFichero» es el nombre de un fichero de texto válido y el número de componentes
 *       del vector «frecuencias» es igual al número de letras del alfabeto inglés.
 * Post: Asigna a cada componente del vector «frecuencias» el número de apariciones de cada una
 *       de las letras del alfabeto inglés en el fichero cuyo nombre es «nombreFichero»,
 *       no distinguiendo entre mayúsculas y minúsculas. La primera componente del vector es el
 *       número de veces que aparece la letra A, la segunda, las de la letra B y así
 *       sucesivamente.
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
        cerr << "No se ha podido leer del fichero \"" << nombreFichero << "\"." << endl;
    }
}


/*
 * Pre:  El número de componentes del vector «frecuencias» es igual al número de letras del
 *       alfabeto inglés. La primera componente del vector es el número de veces que aparece la
 *       letra A, la segunda, las de la letra B y así sucesivamente.
 * Post: Escribe en la pantalla una tabla con las frecuencias de apariciones de las letras
 *       según los valores de las componentes del vector «frecuencias».
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
