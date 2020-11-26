﻿/********************************************************************************\
 * Curso de Programación 1. Tema 14 (Ficheros de texto)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 2 de diciembre de 2019
 * Resumen: Soluciones a los problemas del tema 14: filtrar alumnos
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

const int LONGITUD_MAXIMA = 250;

/*
 * Pre:  «origen» es un flujo de entrada asociado a un texto donde cada línea
 *       corresponde a los siguientes datos de un alumno, separados por espacios:
 *       NIP, grupo y nombre completo. «destino» es un flujo de salida asociado a
 *       un texto.
 * Post: Ha filtrado el contenido del flujo «origen» para dejar, en el flujo
 *       «destino», solo el NIP y el nombre completo de aquellos alumnos que
 *       pertenecen al grupo indicado por el valor del parámetro «grupo».
 */
void filtrar(istream& origen, ostream& destino, const int grupo) {
    int nipAlumno;
    origen >> nipAlumno;
    while (!origen.eof()) {
        int grupoAlumno;
        origen >> grupoAlumno;
        char nombreAlumno[LONGITUD_MAXIMA];
        origen.getline(nombreAlumno, LONGITUD_MAXIMA);
        if (grupoAlumno == grupo) {
            // «nombreAlumno» comienza con un separador
            destino << nipAlumno << nombreAlumno << endl;
        }
        origen >> nipAlumno;
    }
}


/*
 * Pre:  «nombreOrigen» es el nombre de un fichero de texto donde cada línea
 *       corresponde a los siguientes datos de un alumno, separados por espacios:
 *       NIP, grupo y nombre completo.
 * Post: Ha filtrado un fichero cuyo nombre es el valor de «nombreOrigen» para
 *       dejar, en un fichero cuyo nombre es el del valor del parámetro
 *       «nombreDestino», solo el NIP y el nombre completo de aquellos alumnos que
 *       pertenecen al grupo indicado por el valor del parámetro «grupo».
 */
void filtrar(const char nombreOrigen[], const char nombreDestino[],
             const int grupo) {
    ifstream origen;
    origen.open(nombreOrigen);
    if (origen.is_open()) {
        ofstream destino;
        destino.open(nombreDestino);
        if (destino.is_open()) {
            filtrar(origen, destino, grupo);
            destino.close();
        }
        else {
            cerr << "No se ha podido escribir en el fichero \"" << nombreDestino
                 << "\"" << endl;
        }
        origen.close();
    }
    else {
        cerr << "No se ha podido leer del fichero \"" << nombreOrigen
             << "\"" << endl;
    }
}


/*
 * Función de prueba. El fichero «alumnos.txt» debe estar en el directorio
 * del proyecto, donde también se creará el fichero «alumnos-tardes.txt».
 * Este programa no escribe nada en la pantalla si la ejecución es correcta.
 */
int main() {
    filtrar("../alumnos.txt", "../alumnos-tardes.txt", 412);
    return 0;
}
