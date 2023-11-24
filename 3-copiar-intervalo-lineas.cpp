/*********************************************************************************************\
 * Curso de Programación 1. Tema 14 (Ficheros de texto)
 * Autores: Miguel Ángel Latre
 * Última revisión: 24 de noviembre de 2023
 * Resumen: Soluciones a los problemas del tema 14
 * Nota: El programa completo está contenido en este fichero, por lo que puede compilarse y
 *       ejecutarse con la extensión Code Runner de Visual Studio Code.
 *       También puede compilarse desde la terminal través de la orden
 *           g++ -Wall -Wextra 3-copiar-intervalo-lineas.cpp -o 3-copiar-intervalo-lineas
 *       y ejecutarse en Windows a través de la orden
 *           .\3-copiar-intervalo-lineas.exe
 *       o en Linux y macOS
 *           ./3-copiar-intervalo-lineas
\*********************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
 * Pre:  El flujo «origen» está asociado con un fichero externo de texto, en disposición de
 *       leerse desde el principio. El flujo «destino» está asociado con un fichero externo de
 *       texto, en disposición de escribirse desde el principio.
 * Post: Copia en el flujo «origen» las líneas del flujo «destino» cuyo número se encuentra
 *       dentro del intervalo [«lineaInicial», «lineaFinal»].
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
 * Post: Copia en el fichero «ficheroDestino» las líneas del fichero «ficheroOrigen» cuyo
 *       número se encuentra dentro del intervalo [«lineaInicial», «lineaFinal»] y asigna a
 *       «ok» el valor «true». Si el fichero «ficheroOrigen» no se puede leer o el fichero
 *       «ficheroDestino» no se puede escribir, escribe un mensaje de error y asigna a «ok» el
 *       valor «false».
 */
void copiar(const string ficheroOrigen, const string ficheroDestino,
            const int lineaInicial, const int lineaFinal, bool& ok) {
    ifstream origen;
    origen.open(ficheroOrigen);
    if (origen.is_open()) {
        ofstream destino;
        destino.open(ficheroDestino);
        if (destino.is_open()) {
            copiar(origen, destino, lineaInicial, lineaFinal);
            origen.close();
            destino.close();
            ok = true;
        } else {
            origen.close();
            cerr << "No ha podido escribirse el fichero \"" << ficheroDestino << "\"." << endl;
            ok = false;
        }
    } else {
        cerr << "No ha podido leerse el fichero \"" << ficheroOrigen << "\"." << endl;
        ok = false;
    }
}

/*
 * Pre:  ---
 * Post: Solicita al usuario el nombre de un fichero de texto existente, que asigna a
 *       «nombreOrigen»; el nombre de un fichero nuevo, que asigna a «nombreDestino» y dos
 *       enteros que representan un intervalo de líneas, que asigna a «lineaInicial» y
 *       «lineaFinal», asegurándose de que ambos son mayores o iguales que 0.
 */
void pedirDatos(string& nombreOrigen, string& nombreDestino,
                unsigned& lineaInicial, unsigned& lineaFinal) {
    cout << "Nombre de un fichero existente: ";
    cin >> nombreOrigen;

    cout << "Nombre del fichero nuevo: ";
    cin >> nombreDestino;

    int inicio, fin;
    do {
        cout << "Escriba el intervalo de líneas a copiar: ";
        cin >> inicio >> fin;
    } while (inicio < 0 || fin < 0);
    // inicio ≥ 0 y fin ≥ 0
    lineaInicial = inicio;
    lineaFinal = fin;
}


/*
 * Programa que solicita al usuario el nombre de un fichero de texto existente, el nombre de un
 * fichero nuevo y dos enteros que representan un intervalo de líneas. El programa debe copiar
 * en el fichero nuevo las líneas del fichero existente cuyo número se encuentren dentro del
 * intervalo introducido por el usuario. Si el intervalo no es válido (es decir, el segundo
 * entero es menor que el primero) o si el número de líneas del fichero existente es menor que
 * el valor inicial del intervalo, creará el fichero nuevo, pero lo dejará sin contenido. Si el
 * número de líneas del fichero existente es inferior al valor final del intervalo, se copiarán
 * únicamente las líneas que se pueda del fichero existente, hasta llegar a su final.
 */
int main() {
    string nombreOrigen, nombreDestino;
    unsigned lineaInicial, lineaFinal;
    pedirDatos(nombreOrigen, nombreDestino, lineaInicial, lineaFinal);
    bool ficherosOk;
    copiar(nombreOrigen, nombreDestino, lineaInicial, lineaFinal, ficherosOk); 
    if (ficherosOk) {
        cout << "Fichero \"" << nombreDestino << "\" creado con éxito." << endl;
        return 0;
    } else {
        return 1;
    }
}

