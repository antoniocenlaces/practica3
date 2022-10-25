/*******************************************************************************
 * Curso de Programación 1. Práctica 3
 * Autor: Antonio José González Almela
 * 
 * Resumen: Escribe el calendario de cualquier mes de un año igual o 
 * posterior a 1900.
 ******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>

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

/*
 * Pre:  agno > 1582.
 * Post: Devuelve true si y solo si el año «agno» es bisiesto de
 *       acuerdo con las reglas del calendario gregoriano.
 */
bool esBisiesto(unsigned agno) {
    bool multiplo4   = (agno %   4 == 0);
    bool multiplo100 = (agno % 100 == 0);
    bool multiplo400 = (agno % 400 == 0);
    return multiplo400 || (multiplo4 && !multiplo100);
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

/*
 * Pre:  agno > 1582.
 * Post: Devuelve el número de días que tiene el año «agno».
 *       Por ejemplo: diasDelAgno(2018) devuelve 365 y
 *                    diasDelAgno(2020) devuelve 366.
 */
unsigned diasDelAgno(unsigned agno) {
    if (esBisiesto(agno)) {
      return 366;
    } else {
      return 365;
    }
}

/* Pre: year>=1900 y 1<= mes <=12
 * Post: Calcula el número de días del mes correspondiente y verifica bisiesto*/
unsigned calculaDiasDelMes(unsigned mes, unsigned year) {
  unsigned diasMes[12] = { 31, 28, 31, 30, 31, 30, 31, 31,
      30, 31, 30, 31};
  if (esBisiesto(year)) {
    diasMes[1] = 29;
  }
  return diasMes[mes-1];
}

/* Pre: year>=1900, 1<= mes <=12 y 1<= dia <=31
 * Post: Calcula el número de días gtranscurridos entre 01/01/1900
 * y dia/mes/year*/
unsigned calculaDiasTranscurridos(unsigned year, unsigned mes, unsigned dia) {
  unsigned result=0;
  for (unsigned i = 1900; i < year; i++) {
    result += diasDelAgno(i);
  }
  for (unsigned i = 0; i < mes -1; i++) {
    result += calculaDiasDelMes(i + 1, year);
  }
  result += dia - 1;
  return result;
}

/* Pre: year>=1900, 1<= mes <=12 y 1<= dia <=31
 * Post: Calcula el dia de la semana que corresponde a dia/mes/year
 * en el calendario Gregoriano.
 * Devuelve un número positivo entre 0 y 6
 * Correspondiente a L - M - X - J - V - S - D*/
unsigned calculadiaDeInicioSemana(unsigned year, unsigned mes, unsigned dia) {
  return calculaDiasTranscurridos(year, mes, dia) % 7;

}

/* Pre: year>=1900 y 1<= mes <=12
 * Función escribeCalendario recibe dos enteros sin signo:
 * (year>=1900 y 1<= mes <=12) y escribe en pantalla el calendario
 * mensual correspondiente*/
void escribeCalendario(unsigned mes, unsigned year) {
  escribeCabecera(mes, year);

  unsigned diaDeInicioSemana = calculadiaDeInicioSemana(year, mes, 1);
  unsigned diasDelMes=calculaDiasDelMes(mes, year);

  //  for (unsigned i=1; i<=diaDeInicioSemana; i++) {
  //   cout << setw(4) << " ";
  // } 
  // for (unsigned i=1; i<6; i++) {
  //   for (unsigned j=1; j<8; j++) {
  //       if ((7 * (i - 1) + j) <= diasDelMes) {
  //         cout << setw(4) << 7 * (i - 1) + j;
  //         }
  //   }
  //   cout << endl;
  // }

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
    unsigned mes=0,year=0;
    pideDatos(mes, year);
    escribeCalendario(mes, year);
    return 0;
}