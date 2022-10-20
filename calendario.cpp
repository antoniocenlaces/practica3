/*******************************************************************************
 * Curso de Programación 1. Práctica 3
 * Autor: Antonio José González Almela
 * 
 * Resumen: Escribe el calendario de cualquier mes de un año igual o 
 * posterior a 1900.
 ******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

/* Pre: year>=1900 y 1<= mes <=12
 * Función escribeCalendario recibe dos enteros sin signo:
 * (year>=1900 y 1<= mes <=12) y escribe en pantalla el calendario
 * mensual correspondiente*/
void escribeCalendario(unsigned year, unsigned mes) {

}

/* Pre: ---
 * Función pideDatos, solicita retieradamente al usuario un mes y año
 * hasta que cumplen la consición (year>=1900 y 1<= mes <=12) */
   void pideDatos(unsigned& mes, unsigned& year) {

   }

/* Pre: year>=1900 y 1<= mes <=12
 * Función escribeMesYAgno, escribe el nombre del mes que corresponde
 * en mayúsculas y el año */
void escribeMesYAgno(unsigned mes, unsigned year) {

}

/* Pre: year>=1900 y 1<= mes <=12
 * Función escribeCabecera, escribe por pantalla la cabecera del calendario
 * correspondiente a mes con el formato:
 *                   OCTUBRE 2022
 *      L   M   X   J   V   S   D
 *     -------------------------- */
void escribeCabecera(unsigned mes, unsigned year) {

}

int main() {
    unsigned mes,year;
    pideDatos(mes, year);
    escribeCabecera(mes, year);
    escribeCalendario(mes, year);
}