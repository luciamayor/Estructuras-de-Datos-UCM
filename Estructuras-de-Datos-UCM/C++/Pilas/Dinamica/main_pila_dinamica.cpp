#include <iostream>
#include "pila_dinamica.h"



int main (int argc, char * const argv[]) {
	
	TPila<char> pila;
	TPila<char> pila1;
	TPila<char> pila2;
	TPila<char> pila3;
	TPila<char> pila4;
	
	try {
		
		cout << endl;
		if ( pila.esVacio() ) cout << "Pila vacia";
		else cout << "Pila NO vacia";
		cout << endl;
		
		pila.apila('a');
		pila.apila('b');
		pila.apila('c');
		pila.apila('d');
		pila.apila('e');
		pila.apila('f');
		pila.escribe();
		
		cout << endl;
		cout << "La cima de la pila es: " << pila.cima();
		cout << endl;
		
		pila.escribe();
		
		pila1.apila('1');
		pila1.apila('2');
		pila1.apila('3');
		pila1.escribe();
		
		pila2.apila('4');
		pila2.apila('5');
		pila2.apila('6');
		pila2.escribe();
		
		pila1.concatenar(pila2);
		pila1.escribe();
		
		cout << endl;
		cout << "La cima de la pila es: " << pila1.cima();
		cout << endl;
		
		pila3.apila('1');
		pila3.apila('3');
		pila3.apila('5');
		pila3.escribe();
		
		pila4.apila('2');
		pila4.apila('4');
		pila4.escribe();
		
		pila3.entremezclar(pila4);
		pila3.escribe();
		
		pila3.borrar();
		
		cout << endl;
		if ( pila3.esVacio() ) cout << "Pila vacia";
		else cout << "Pila NO vacia";
		cout << endl;
		
		cout << endl;
		
	}
	catch ( EAccesoIndebido e ) {
		
		cout << e.mensaje();
		
	}
	
	
	return 0;
	
}