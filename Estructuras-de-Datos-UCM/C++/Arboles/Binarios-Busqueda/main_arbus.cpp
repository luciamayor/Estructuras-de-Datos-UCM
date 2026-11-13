#include <iostream>
#include "arbus.h"


int main (int argc, char * const argv[]) {
	
	
	try {
		
		TArbus<char,int> b;
		
		b.inserta('a',7);
		b.inserta('b',5);
		b.inserta('c',9);
		b.inserta('d',3);
		b.inserta('e',4);
		b.inserta('f',6);
		
		b.escribe();
		
		cout << endl << "Las claves del arbol ordenadas son: " << endl;
		
		TSecuenciaDinamica<char> s1;
		
		s1 = b.recorreClave();
		
		s1.escribe();
		
		cout << endl << "Los valores del arbol ordenados por la clave son: " << endl;
		
		TSecuenciaDinamica<int> s2;
		
		s2 = b.recorre();
		
		s2.escribe();
		
		
		char clave = 'z';
		
		cout << endl << "El valor asociado a la clave " << clave << " es: " << b.consulta(clave) << endl;
		
	}
	catch( EClaveErronea e ) {
		
		cout << endl << endl << e.mensaje( ) << endl;
		
	}
	
	
	try {
		
		TArbus<int,char> arbol;
	
		if ( arbol.esVacio() ) cout << endl << "El arbol SI esta vacio" << endl;
		else cout << endl << "El arbol NO esta vacio" << endl;
	
		arbol.inserta(7,'a');
		arbol.inserta(5,'b');
		arbol.inserta(9,'c');
		arbol.inserta(3,'d');
		arbol.inserta(4,'e');
		arbol.inserta(6,'f');
	
		arbol.escribe();
	
		arbol.inserta(7,'z');
		arbol.inserta(4,'v');
	
		arbol.escribe();
	
		if ( arbol.esVacio() ) cout << endl << "El arbol SI esta vacio" << endl;
		else cout << endl << "El arbol NO esta vacio" << endl;
	
		int clave1 = 4;
	
		cout << endl << "El valor asociado a la clave " << clave1 << " es: " << arbol.consulta(clave1) << endl;
	
		if ( arbol.esta(clave1) ) cout << endl << "El arbol SI contiene la clave " << clave1 << endl;
		else cout << endl << "El arbol NO contiene la clave " << clave1 << endl;
	
		int clave2 = 12;
	
		if ( arbol.esta(clave2) ) cout << endl << "El arbol SI contiene la clave " << clave2 << endl;
		else cout << endl << "El arbol NO contiene la clave " << clave2 << endl;
	
		int clave3 = 5;
	
		cout << endl << "Eliminamos el par (" << clave3 << "," << arbol.consulta(clave3) << ") en el arbol: " << endl;
	
		arbol.borra(clave3);
	
		arbol.escribe();
	
		cout << endl << "Las claves del arbol ordenadas, son: " << endl;
	
		TSecuenciaDinamica<int> sec1;
	
		sec1 = arbol.recorreClave();
	
		sec1.escribe();
	
		cout << endl << "Los valores del arbol, ordenados por la clave, son: " << endl;
	
		TSecuenciaDinamica<char> sec2;
	
		sec2 = arbol.recorre();
	
		sec2.escribe();
	
		cout << endl;
		
	}
	catch( EClaveErronea e ) {
		
		cout << endl << endl << e.mensaje( ) << endl << endl;
		
	}
	
    return 0;
	
}