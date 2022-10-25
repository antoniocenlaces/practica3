/******************************************************************************\
 * Curso de Programación 1. Práctica 3
 * Autores: ¡PON AQUÍ TU NOMBRE!
 * Última revisión: 21 de octubre de 2021
 * Resumen: Programa que escribe en la pantalla el calendario de un determinado
 *          mes de un año, que se solicitan al usuario. El programa se asegura 
 *          de que el mes introducido está comprendido entre 1 y 12 y de que el 
 *          año es igual o posterior a 1900.
 *          Clase de problemas correspondiente al tema 7 (diseño modular y
 *          descendente) y 3ª práctica.
 * Nota: Leer el fichero README.md, que contiene instrucciones para su 
 *       compilación y ejecución.
\******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

/*
 * Pre:  1 ≤ mes ≤ 12
 * Post: Ha escrito en la pantalla el nombre (en mayúsculas) del mes
 *       correspondiente al valor del parámetro «mes».
 * Nota: Este código lo podrás comprender adecuadamente cuando hayamos visto
 *       los temas 9 (vectores) y 10 (cadenas de caracteres).
 */
void escribirNombreMes(unsigned mes) {
    const string NOMBRES_MES[12] = { "ENERO",
            "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO",
            "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE" };
    cout << NOMBRES_MES[mes - 1];
}


/*
 * ¡ESCRIBE LA ESPECIFICACIÓN!
 */
int main() {
    return 0;
}
