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
  cout << right << setw(28) << " L   M   X   J   V   S   D" << endl;
  cout << right << setw(28) << "--------------------------" << endl;
}

/* Pre: year>=1900 y 1<= mes <=12
 * Función escribeCalendario recibe dos enteros sin signo:
 * (year>=1900 y 1<= mes <=12) y escribe en pantalla el calendario
 * mensual correspondiente*/
void escribeCalendario(unsigned mes, unsigned year) {
  escribeCabecera(mes, year);

  unsigned diaDeInicioSemana = 3;
  unsigned diasDelMes=31;

   for (unsigned i=1; i<=diaDeInicioSemana; i++) {
    cout << setw(4) << " ";
  } 
  for (unsigned i=1; i<6; i++) {
    for (unsigned j=1; j<8; j++) {
        if ((7 * (i - 1) + j) <= diasDelMes) {
          cout << setw(4) << 7 * (i - 1) + j;
          }
    }
    cout << endl;
  }

  /*Forma resuelta en clase
   con este método una función diasDelMes me sirve como tope del bucle
   deja espacios (tantos como el dia en el que inicia la semana)
   diaDeLaSemana es el número de días de 1900 hasta la fecha y hacer módulo 7*/
  
  for (unsigned i=1; i<=diaDeInicioSemana; i++) {
    cout << setw(4) << " ";
  }
  for (unsigned i=1; i<=diasDelMes; i++) {
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

int main() {
    unsigned mes,year;
    pideDatos(mes, year);
    escribeCalendario(mes, year);
    return 0;
}