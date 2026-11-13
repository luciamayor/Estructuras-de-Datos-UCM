#include <iostream>
#include "pila_estatica.h"



int main (int argc, char * const argv[]) {
	
	 TPila<char> pila;
	 
	 try {
		 pila.apila('a');
		 pila.apila('b');
		 pila.apila('c');
		 pila.apila('d');
		 pila.apila('e');
		 pila.apila('f');
	 
		 pila.escribe( );
	 
		 cout << endl;
		 if ( pila.esVacio( ) ) cout << "Pila vacia";
		 else cout << "Pila NO vacia";
		 cout << endl;
	 
		 cout << endl;
		 cout << "La cima de la pila es: " << pila.cima( );
		 cout << endl;
		 cout << endl;
		 
		 pila.desapila( );
		 pila.desapila( );
		 
		 pila.escribe( );
		 
		 cout << endl;
		 cout << "La cima de la pila es: " << pila.cima( );
		 cout << endl;
		 cout << endl;
		 
		 pila.desapila( );
		 pila.desapila( );
		 pila.desapila( );
		 pila.desapila( );
		 // pila.desapila( );
		 // pila.desapila( );
		 
		 cout << endl;
		 cout << "La cima de la pila es: " << pila.cima( );
		 cout << endl;
	 
	 }
	 catch( EDesbordamiento e ) {
		 cout << endl << e.mensaje( ) << endl;
	 }
	 catch ( EAccesoIndebido e ) {
		 cout << endl << e.mensaje( ) << endl;
	 }
	
	
	 cout << endl;
	
	 return 0;
	
}
