/*

    PRACTICA 1: IMPLEMENTACION EN C++ DEL TAD GENERICO DE LOS CONJUNTOS FINITOS 
	            USANDO ARRAYS ORDENADOS SIN REPETICIONES

    ASIGNATURA: ESTRUCTURAS DE DATOS
    CURSO:      2026-2027
    SUBGRUPO:    

    APELLIDOS:	
    NOMBRE:	    	

*/


#include <iostream>
#include "Conjunto.h"


int main(int argc, char* argv[])
{
	
  TCjto<char> cjto;

  cjto.pon('c');
  cjto.pon('a');
  cjto.pon('b');

  cout << cjto;
  
  cjto.quita('a');
  
  cout << cjto;
  
  if (cjto.esVacio()) cout << "Si es vacio\n" ;
  else cout << "No es vacio\n" ;
  
  if (cjto.pertenece('b')) cout << "Si pertenece\n" ;
  else cout << "No pertenece\n" ;
  
  if (cjto.esLleno()) cout << "Si esta lleno\n" ;
  else cout << "No esta lleno\n" ;
  
  cjto.quita('b');
  
  cout << cjto;
  
  if (cjto.esVacio()) cout << "Si es vacio\n" ;
  else cout << "No es vacio\n" ;
  
  if (cjto.pertenece('b')) cout << "Si pertenece\n" ;
  else cout << "No pertenece\n" ;
  
  if (cjto.esLleno()) cout << "Si esta lleno\n" ;
  else cout << "No esta lleno\n" ;

}