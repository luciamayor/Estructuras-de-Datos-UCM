#ifndef cola_estaticaH
#define cola_estaticaH


/*
 
 
 especificación COLAS[ELEM]
 
 usa BOOLEANOS
 
 tipos cola
 
 operaciones
 
	cola-vacía     :                -->   cola     { constructora }
	pedir-vez      : cola elemento  -->   cola     { constructora }
	avanzar        : cola           -/->  cola
	primero        : cola           -/->  elemento
	es-cola-vacía? : cola           -->   bool
 
 variables
 
	e : elemento
	p : cola
 
 ecuaciones
 
	avanzar(cola-vacía)     = error
	avanzar(pedir-vez(c,e)) = cola-vacía               <==   es-cola-vacía?(c)
	avanzar(pedir-vez(c,e)) = pedir-vez(avanzar(c),e)  <==  ¬es-cola-vacía?(c)
 
	primero(cola-vacía)     = error
	primero(pedir-vez(c,e)) = e           <==   es-cola-vacía?(c)
	primero(pedir-vez(c,e)) = primero(c)  <==  ¬es-cola-vacía?(c)
 
	es-cola-vacía?(cola-vacía)     = cierto
	es-cola-vacía?(pedir-vez(c,e)) = falso
 
 fespecificación
 
 
*/


#include <iostream>
#include <string>

using namespace std;



// Tratamiento de excepciones


class EAccesoIndebido {
	
public:
	
    EAccesoIndebido( string mensaje = "" ) : _mensaje(mensaje) { };
	
    string mensaje ( ) {
		return _mensaje;
    };
	
private:
	
    string _mensaje;
	
};



template <class TElem>
class TColaEstatica {
	
  public:

  // Constructora
	
     TColaEstatica( int = 5 );
     // Recibe el tamaño inicial de la cola
     // O(1) sobre tipos predefinidos


  // Operaciones de las colas
	
     void ponDetras( TElem elem );
     // Pre: true
     // Post: Se añade 'elem' al final de la cola
     // Si _longitud <  _capacidad O(1) sobre tipos predefinidos
     // Si _longitud == _capacidad O(n) sobre tipos predefinidos

     TElem primero( ); // throw (EAccesoIndebido);
     // Pre: ! esVacio( )
     // Post: Devuelve el primer elemento de la cola
     // Lanza la excepción "EAccesoIndebido" si la cola está vacía
     // O(1)

     void quitaPrim( ); // throw (EAccesoIndebido);
     // Pre: ! esVacio( )
     // Post: Elimina el primer elemento de la cola
     // Lanza la excepción "EAccesoIndebido" si la cola está vacía
     // O(1)

     bool esVacio( );
     // Pre: true
     // Post: Devuelve true o false según si la cola está o no vacía
     // O(1)

  // Escritura
	
     void escribe( );
     // Pre: true
     // Post: escribe el contenido de la cola
     // O(n)


  private:
	
  // Variables privadas
	
     int _longitud;      // número de elementos de la cola
     int _capacidad;
     TElem *_espacio;    // _espacio[_capacidad]
     int _ini, _fin;

};



//---------------------------------------------------------------------------
// IMPLEMENTACION
//---------------------------------------------------------------------------


  // Constructora

     template <class TElem>
     TColaEstatica<TElem>::TColaEstatica( int capacidad ) :

       _capacidad(capacidad), _ini(0), _fin(-1), _longitud(0),

       _espacio(new TElem[_capacidad]) {
     };



  // Operaciones de las colas

     template <class TElem>
     void TColaEstatica<TElem>::ponDetras( TElem elem ) {
		 
       if( _longitud == _capacidad ){
		   
         _capacidad *= 2;
		   
         TElem* nuevo = new TElem[_capacidad];
		   
         for( int i = 0; i < _longitud; i++ )
           nuevo[i] = _espacio[ (_ini + i) % (_capacidad / 2) ] ;
		   
         delete [] _espacio;
			 
         _espacio = nuevo;
         _ini = 0;
         _fin = _longitud - 1;
			 
         cout << endl << "Creciendo" << endl;
			 
       }
			 
       _fin = (_fin + 1) % _capacidad ;
       _longitud++;
       _espacio[_fin] = elem;
			 
     };

			 
			 
     template <class TElem>
     TElem TColaEstatica<TElem>::primero( ) // throw (EAccesoIndebido) 
	 {
			   
       if( esVacio() )
         throw EAccesoIndebido("Cola vacia");
			   
       return _espacio[_ini];
			   
     };

			 
			 
     template <class TElem>
     void TColaEstatica<TElem>::quitaPrim( ) //throw (EAccesoIndebido) 
	 {
			   
       if( esVacio() )
         throw EAccesoIndebido("Cola vacia");
			   
       _ini = (_ini + 1) % _capacidad;
       _longitud--;
			   
     };

			 
			 
     template <class TElem>
     bool TColaEstatica<TElem>::esVacio( ) {
			   
       return _longitud == 0;
			   
     };


  // Operaciones de entrada/salida

     template <class TElem>
     void TColaEstatica<TElem>::escribe( ) {
			   
	   cout << endl;
       for ( int i = 0; i < _longitud; i++ )
         cout << _espacio[ (_ini + i) % _capacidad ] << endl;
		 
	   cout << endl;
			   
     };



#endif
