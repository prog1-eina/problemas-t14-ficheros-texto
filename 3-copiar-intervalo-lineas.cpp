/******************************************************************************\
 * Curso de Programación 1. Tema 14 (Ficheros de texto)
 * Autores: Miguel Ángel Latre
 * Última revisión: 29 de noviembre de 2021
 * Resumen: Soluciones a los problemas del tema 14
\******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
 * Pre:  El flujo «origen» está asociado con un fichero externo de texto, en 
 *       disposición de leerse desde el principio. El flujo «destino» está
 *       asociado con un fichero externo de texto, en disposición de escribirse 
 *       desde el principio.
 * Post: Copia en el flujo «origen» las líneas del flujo «destino» cuyo número 
 *       se encuentra dentro del intervalo [«lineaInicial», «lineaFinal»].
 */
void copiar(istream& origen, ostream& destino,
            const unsigned lineaInicial, const unsigned lineaFinal) {
    unsigned lineasLeidas = 0;
    string linea;
    while (getline(origen, linea) && lineasLeidas < lineaFinal) {
        // Si el último intento de lectura tuvo éxito, procesa la línea leída:
        lineasLeidas++;
        if (lineaInicial <= lineasLeidas && lineasLeidas <= lineaFinal) {
            destino << linea << endl;
        }
    }
}

/*
 * Pre:  ---
 * Post: Copia en el fichero «ficheroDestino» las líneas del fichero
 *       «ficheroOrigen» cuyo número se encuentra dentro del intervalo
 *       [«lineaInicial», «lineaFinal»] y devuelve «true». Si el fichero
 *       «ficheroOrigen» no se puede leer o el fichero «ficheroDestino» no se
 *       puede escribir, escribe un mensaje de error y devuelve «false».
 */
bool copiar(const string ficheroOrigen, const string ficheroDestino,
            const int lineaInicial, const int lineaFinal) {
    ifstream origen;
    origen.open(ficheroOrigen);
    if (origen.is_open()) {
        ofstream destino;
        destino.open(ficheroDestino);
        if (destino.is_open()) {
            copiar(origen, destino, lineaInicial, lineaFinal);
            origen.close();
            destino.close();
            return true;
        }
        else {
            origen.close();
            cerr << "No ha podido escribirse el fichero \"" 
                << ficheroDestino << "\"." << endl;
            return false;
        }
    }
    else {
        cerr << "No ha podido leerse el fichero \"" 
             << ficheroOrigen << "\"." << endl;
        return false;
    }
}

/*
 * Programa que solicita al usuario el nombre de un fichero de texto existente,
 * el nombre de un fichero nuevo y dos enteros que representan un intervalo de
 * líneas. El programa debe copiar en el fichero nuevo las líneas del fichero
 * existente cuyo número se encuentren dentro del intervalo introducido por el
 * usuario. Si el intervalo no es válido (es decir, el segundo entero es menor
 * que el primero) o si el número de líneas del fichero existente es menor que
 * el valor inicial del intervalo, creará el fichero nuevo, pero lo dejará sin
 * contenido. Si el número de líneas del fichero existente es inferior al valor
 * final del intervalo, se copiarán únicamente las líneas que se pueda del
 * fichero existente, hasta llegar a su final.
 */
int main() {
    cout << "Nombre de un fichero existente: ";
    string ficheroOrigen;
    cin >> ficheroOrigen;

    cout << "Nombre del fichero nuevo: ";
    string ficheroDestino;
    cin >> ficheroDestino;

    int lineaInicial, lineaFinal;
    do {
        cout << "Escriba el intervalo de líneas a copiar: ";
        cin >> lineaInicial >> lineaFinal;
    } while (lineaInicial <= 0 || lineaInicial > lineaFinal);
    // 0 < lineaInicial ≤ lineaFinal

    bool ok = copiar(ficheroOrigen, ficheroDestino, lineaInicial, lineaFinal); 
    if (ok) {
        cout << "Fichero \"" << ficheroDestino << "\" creado con éxito." << endl;
        return 0;
    }
    else {
        return 1;
    }
}

