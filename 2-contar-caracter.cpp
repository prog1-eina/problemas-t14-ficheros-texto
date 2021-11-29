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
 * Pre:  «flujo» está asociado con un fichero externo de texto, en disposición
 *       de leerse desde el primer carácter.
 * Post: Ha asignado al parámetro «apariciones» el número de veces que el
 *       carácter «caracter» aparece en «flujo».
 */
void contarApariciones(istream& flujo, const char caracter, 
                       unsigned& apariciones) {
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
 * Post: Si se puede leer el fichero de nombre «nombreFichero», ha asignado al
 *       parámetro «apariciones» el número de veces que el carácter «caracter»
 *       aparece en el fichero y ha devuelto «true». En caso contrario, ha
 *       devuelto «false».
 */
bool contarApariciones(const string nombreFichero, const char caracter, 
                       unsigned& apariciones) {
    ifstream f;
    f.open(nombreFichero);
    if (f.is_open()) {
        contarApariciones(f, caracter, apariciones);
        f.close();
        return true;
    }
    else {
        return false;
    }
}

/*
 * Programa que solicita al usuario el nombre de un fichero de texto y un 
 * carácter. Si el fichero existe y se puede abrir, el programa escribe en la 
 * pantalla el número de veces que el carácter introducido aparece en el 
 * fichero.
 */
int main() {
    cout << "Nombre del fichero: ";
    string nombreFichero;
    cin >> nombreFichero;

    cout << "Escriba el carácter a contar: ";
    char caracter;
    cin >> caracter;

    unsigned apariciones;
    bool ok = contarApariciones(nombreFichero, caracter, apariciones); 
    if (ok) {
        cout << "El carácter '" << caracter << "' aparece " 
             << apariciones << " veces." << endl;
        return 0;
    }
    else {
        cerr << "No ha podido leerse el fichero \"" 
             << nombreFichero << "\"." << endl;
        return 1;
    }
}

