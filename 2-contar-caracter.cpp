/*********************************************************************************************\
 * Curso de Programación 1. Tema 14 (Ficheros de texto)
 * Autores: Miguel Ángel Latre
 * Última revisión: 23 de noviembre de 2023
 * Resumen: Soluciones a los problemas del tema 14
 * Nota: El programa completo está contenido en este fichero, por lo que puede compilarse y
 *       ejecutarse con la extensión Code Runner de Visual Studio Code.
 *       También puede compilarse desde la terminal través de la orden
 *           g++ -Wall -Wextra 2-contar-caracter.cpp -o 2-contar-caracter
 *       y ejecutarse en Windows a través de la orden
 *           .\2-contar-caracter.exe
 *       o en Linux y macOS
 *           ./2-contar-caracter
\*********************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
 * Pre:  «flujo» está asociado con un fichero externo de texto, en disposición de leerse desde
 *       el primer carácter.
 * Post: Asigna al parámetro «apariciones» el número de veces que el carácter «caracter»
 *       aparece en «flujo».
 */
void contarApariciones(istream& flujo, const char caracter, unsigned& apariciones) {
    apariciones = 0;

    char caracterLeido;
    while (flujo.get(caracterLeido)) {
        // Si el último intento de lectura tuvo éxito, procesa el carácter leído
        if (caracter == caracterLeido) {
            apariciones++;
        }
    }
}

/*
 * Pre:  ---
 * Post: Si se puede leer el fichero de nombre «nombreFichero», asigna al parámetro
 *       «apariciones» el número de veces que el carácter «caracter» aparece en el fichero y al
 *       parámetro «lecturaOk» el valor «true». En caso contrario, asigna al parámetro
 *       «lecturaOk» el valor «false».
 */
void contarApariciones(const string nombreFichero, const char caracter, 
                       unsigned& apariciones, bool& lecturaOk) {
    lecturaOk = false;                        
    ifstream f;
    f.open(nombreFichero);
    if (f.is_open()) {
        lecturaOk = true;
        contarApariciones(f, caracter, apariciones);
        f.close();
    }
}

/*
 * Programa que solicita al usuario el nombre de un fichero de texto y un carácter. Si el
 * fichero existe y se puede abrir, el programa escribe en la pantalla el número de veces que
 * el carácter introducido aparece en el fichero.
 */
int main() {
    cout << "Nombre del fichero: ";
    string nombreFichero;
    cin >> nombreFichero;

    cout << "Escriba el carácter a contar: ";
    char caracter;
    cin >> caracter;

    unsigned apariciones;
    bool lecturaOk;
    contarApariciones(nombreFichero, caracter, apariciones, lecturaOk); 
    if (lecturaOk) {
        cout << "El carácter '" << caracter << "' aparece " << apariciones << " veces." << endl;
        return 0;
    } else {
        cerr << "No ha podido leerse el fichero \"" << nombreFichero << "\"." << endl;
        return 1;
    }
}
