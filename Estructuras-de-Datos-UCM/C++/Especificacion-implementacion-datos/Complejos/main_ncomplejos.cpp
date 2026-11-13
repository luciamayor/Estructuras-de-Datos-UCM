/*

    PRACTICA 1: IMPLEMENTACION EN C++ DEL TAD DE LOS NUMEROS COMPLEJOS SOBRE LOS NUMEROS ENTEROS

    ASIGNATURA: ESTRUCTURAS DE DATOS
    CURSO:      2026-2027
    SUBGRUPO:    

    APELLIDOS:	
    NOMBRE:	    	

*/


#include <iostream>
#include "Complejo.h"


int main(int argc, char* argv[])
{
	
  MiComplejo c(-4, 5);
  
  cout << "(" << c.re() << ", " << c.im() << ")\n";
  cout << c.re() << " + " << c.im() << "i\n";
  
  c.mostrar();
  
  MiComplejo d(1, 3);
  
  cout << "(" << d.re() << ", " << d.im() << ")\n";
  cout << d.re() << " + " << d.im() << "i\n";
  
  c.suma(d);
  
  cout << c.re() << " + " << c.im() << "i\n";
  
  c.resta(d);
  
  cout << c.re() << " + " << c.im() << "i\n";
  
  if (c.iguales(d)) cout << "Si son iguales\n" ;
  else cout << "No son iguales\n" ;
  
}