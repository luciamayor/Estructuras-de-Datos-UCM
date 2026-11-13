#include <iostream>
#include "cola_estatica.h"

int main (int argc, char * const argv[]) {
	
	try {
		
		TColaEstatica<char> cola;
	
		cola.ponDetras('a');
		cola.ponDetras('b');
		cola.ponDetras('c');
		cola.ponDetras('d');
	
		cola.escribe();
	
		cola.ponDetras('e');
	
		cola.escribe();
	
		cola.ponDetras('f');
	
		cola.escribe();
	
		cola.ponDetras('g');
	
		cola.escribe();
	
		cout << endl;
		cout << "El primer elemento de la cola es: " << cola.primero();
		cout << endl;
	
		cola.quitaPrim();
	
		cola.escribe();
	
		cout << endl;
		cout << "El primer elemento de la cola es: " << cola.primero();
		cout << endl;
	
		cout << endl;
		if ( cola.esVacio() ) cout << "La cola SI esta vacia";
		else cout << "La cola NO esta vacia";
		cout << endl;
	
		cout << endl;
		
	}
	catch ( EAccesoIndebido e ) {
		cout << e.mensaje( );
	}

    return 0;
	
}
