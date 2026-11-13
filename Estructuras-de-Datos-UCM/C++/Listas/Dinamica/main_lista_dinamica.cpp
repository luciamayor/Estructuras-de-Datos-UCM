#include <iostream>
#include "lista_dinamica.h"


int main (int argc, char * const argv[]) {
   
	TListaDinamica<int> l;
	
	l.ponDetras(3);
	l.ponDetras(4);
	
	l.escribe( );
	
	l.ponDelante(2);
	l.ponDelante(1);
	
	l.escribe( );
	
	TListaDinamica<int> m;
	
	m.ponDelante(6);
	m.ponDelante(5);
	
	m.escribe( );
	
	l.concatena(m);
	l.escribe( );
	
	int n = 3;
	cout << endl << "El elemento de la lista en la posicion " << n << " es: " << l.elemEn(n) << endl;
	
	try{
		
		cout << "El ultimo elemento de la lista es: " << l.ultimo( ) << endl;
		
	}
	catch( EDesbordamiento e ) {
		
		cout << endl << e.mensaje( ) << endl;
		
	}
	catch ( EAccesoIndebido e ) {
		
		cout << endl << e.mensaje( ) << endl;
		
	}
	
	l.quitaPrim( );
	l.quitaUlt( );
	l.quitaPrim( );
	l.quitaUlt( );
	l.quitaPrim( );
	l.quitaUlt( );
	l.escribe( );
	
	try{
		
		l.quitaUlt( );
		
	}
	catch( EDesbordamiento e ) {
		
		cout << endl << e.mensaje( ) << endl;
		
	}
	catch ( EAccesoIndebido e ) {
		
		cout << endl << e.mensaje( ) << endl;
		
	}
	
	try{
		
		l.ultimo( );
		
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