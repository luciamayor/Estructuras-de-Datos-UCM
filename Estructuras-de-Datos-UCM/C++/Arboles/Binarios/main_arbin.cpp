#include <iostream>
#include "arbin.h"


int main (int argc, char * const argv[]) {
	
	try {
		
		TArbinDinamico<int> b1;
		
		if ( b1.esVacio() ) cout << "El arbol SI es vacio";
		else cout << "El arbol NO es vacio";
		cout << endl;
		
		cout << endl << "La raiz del arbol es: " << b1.raiz() << endl << endl;
		
	}
	catch( EAccesoIndebido e ) {
		
		cout << endl << e.mensaje( ) << endl << endl;
		
	}
	
	try {
		
		TArbinDinamico<int> b2;
		
		if ( b2.esVacio() ) cout << "El arbol SI es vacio";
		else cout << "El arbol NO es vacio";
		cout << endl;
		
		(b2.hijoIz()).escribe();
		
	}
	catch( EAccesoIndebido e ) {
		
		cout << endl << e.mensaje( ) << endl << endl;
		
	}
	
	try {
		
		TArbinDinamico<int> b3;
		
		if ( b3.esVacio() ) cout << "El arbol SI es vacio";
		else cout << "El arbol NO es vacio";
		cout << endl;
		
		(b3.hijoDr()).escribe();
		
	}
	catch( EAccesoIndebido e ) {
		
		cout << endl << e.mensaje( ) << endl << endl;
		
	}
	
	try {
		
		TArbinDinamico<int> a11;
		TArbinDinamico<int> a12;
		TArbinDinamico<int> arbol1(a11,5,a12);
	
		TArbinDinamico<int> a211;
		TArbinDinamico<int> a212;
		TArbinDinamico<int> arbol21(a211,2,a212);
	
		TArbinDinamico<int> a221;
		TArbinDinamico<int> a222;
		TArbinDinamico<int> arbol22(a221,1,a222);
	
		TArbinDinamico<int> arbol2(arbol21,3,arbol22);
	
		TArbinDinamico<int> arbol(arbol1,7,arbol2);
		
		if ( arbol.esVacio() ) cout << "El arbol SI es vacio";
		else cout << "El arbol NO es vacio";
		cout << endl;
	
		cout << endl << "El arbol es:" << endl;
	
		arbol.escribe();
	
		cout << endl << "La raiz del arbol es: " << arbol.raiz() << endl;
	
		cout << endl << "El hijo izquierdo del arbol es:" << endl;
	
		(arbol.hijoIz()).escribe();
	
		cout << endl << "El hijo derecho del arbol es:" << endl;
	
		(arbol.hijoDr()).escribe();
	
		cout << endl << "El recorrido en pre-orden del arbol es:" << endl;
	
		TSecuenciaDinamica<int> sec1;
	
		sec1 = arbol.preOrd();
	
		sec1.escribe();
	
		cout << endl << "El recorrido en post-orden del arbol es:" << endl;
	
		TSecuenciaDinamica<int> sec2;
	
		sec2 = arbol.postOrd();
	
		sec2.escribe();
	
		cout << endl << "El recorrido en in-orden del arbol es:" << endl;
	
		TSecuenciaDinamica<int> sec3;
	
		sec3 = arbol.inOrd();
	
		sec3.escribe();
		
	}
	catch( EAccesoIndebido e ) {
		
		cout << endl << endl << e.mensaje( ) << endl ;
		
	}
	
    return 0;

}