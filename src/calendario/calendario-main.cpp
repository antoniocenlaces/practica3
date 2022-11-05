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
#include <iomanip>
#include "fechas.hpp"
using namespace std;

/* Pre: year>=1900 y 1<= mes <=12
 * Función escribeMesYAgno, escribe el nombre del mes que corresponde
 * en mayúsculas y el año */
void escribeMesYAgno(unsigned mes, unsigned year) {
  const string NOMBRES_MES[12] = { "ENERO",
            "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO",
            "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE" };
            cout << right << setw(23) << NOMBRES_MES[mes - 1] << " "
                << year << endl;
}

/* Pre: year>=1900 y 1<= mes <=12
 * Función escribeCabecera, escribe por pantalla la cabecera del calendario
 * correspondiente a mes con el formato:
 *                   OCTUBRE 2022
 *      L   M   X   J   V   S   D
 *     -------------------------- */
void escribeCabecera(unsigned mes, unsigned year) {
  escribeMesYAgno(mes, year);
  cout << setw(28) << " L   M   X   J   V   S   D" << endl;
  cout << setw(28) << "--------------------------" << endl;
}

/* Pre: year>=1900 y 1<= mes <=12
 * Función escribeCalendario recibe dos enteros sin signo:
 * (year>=1900 y 1<= mes <=12) y escribe en pantalla el calendario
 * mensual correspondiente*/
void escribeCalendario(unsigned mes, unsigned year) {
  escribeCabecera(mes, year);
    unsigned diaDeInicioSemana = diaDeLaSemana(1, mes, year);
  unsigned diasEnElMes =diasDelMes(mes, year);

  /*Forma resuelta en clase
   con este método una función diasDelMes me sirve como tope del bucle
   deja espacios (tantos como el dia en el que inicia la semana)
   diaDeLaSemana es el número de días de 1900 hasta la fecha y hacer módulo 7*/
  
  for (unsigned i=1; i<=diaDeInicioSemana; i++) {
    cout << setw(4) << " ";
  }
  for (unsigned i=1; i<=diasEnElMes; i++) {
    cout << setw(4) << i;
    if ((i + diaDeInicioSemana) % 7 == 0) {
      cout << endl;
    }
  }
}

/* Pre: ---
 * Función pideDatos, solicita retieradamente al usuario un mes y año
 * hasta que cumplen la consición (year>=1900 y 1<= mes <=12) */
   void pideDatos(unsigned& mes, unsigned& year) {
      cout << "Introduzca el mes [1-12]: ";
      cin >> mes;
      while (mes <= 0 || mes > 12) {
        cout << "El mes debe estar comprendido entre 1 y 12: ";
        cin >> mes;
      }
      cout << "Introduzca un año igual o posterior a 1900: ";
      cin >> year;
      while (year < 1900) {
        cout << "El año debe ser igual o posterior a 1900: ";
        cin >> year;
      }
   }

/*
 * ¡ESCRIBE LA ESPECIFICACIÓN!
 */
int main() {
    unsigned mes=0,year=0;
    pideDatos(mes, year);
    escribeCalendario(mes, year);
    return 0;
}
