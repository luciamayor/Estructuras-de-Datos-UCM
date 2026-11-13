#ifndef pila_estaticaH
#define pila_estaticaH


/*
 
 
 especificación PILAS[ELEM]
 
 usa BOOLEANOS
 
 tipos pila
 
 operaciones
 
	pila-vacía     :                -->   pila     { constructora }
	apilar         : elemento pila  -->   pila     { constructora }
	desapilar      : pila           -/->  pila
	cima           : pila           -/->  elemento
	es-pila-vacía? : pila           -->   bool
 
 variables
 
	e : elemento
	p : pila
 
 ecuaciones
 
	desapilar(pila-vacía)  = error
	desapilar(apilar(e,p)) = p
 
	cima(pila-vacía)  = error
	cima(apilar(e,p)) = e
 
	es-pila-vacía?(pila-vacía)  = cierto
	es-pila-vacía?(apilar(e,p)) = falso
 
 fespecificación
 
 
*/


#include <iostream>
#include <string>

using namespace std;



// Tratamiento de excepciones


class EDesbordamiento {
	
  public:
	
    EDesbordamiento( string mensaje = "" ) : _mensaje(mensaje) { };
	
    string mensaje ( ) {
      return _mensaje;
    };
	
  private:
	
    string _mensaje;
	
};


class EAccesoIndebido {
	
  public:
	
    EAccesoIndebido( string mensaje = "" ) : _mensaje(mensaje) { };
	
    string mensaje ( ) {
      return _mensaje;
    };
	
  private:
	
    string _mensaje;
	
};



// Clase principal del TAD genérico de las pilas (implementación estática)


template<class TElem>
class TPila {
	
  public:

  // Tamaño máximo
	
     static const int longMax = 100;

	
  // Constructora
	
     TPila( );
     // Pre: true
     // Post: construye un valor que representa a la pila vacía
     // O(1)

	
  // Operaciones de las pilas
	
     bool esVacio( );
     // Pre: true
     // Post: determina si la pila está vacía
     // O(1)

     void apila( TElem x ); //throw ( EDesbordamiento );
     // Pre: ! esLleno( )
     // Post: modifica la pila, añadiéndole x en la cima
     // Lanza la excepción "EDesbordamiento" si la pila está llena
     // O(1)

     void desapila( ); //throw ( EAccesoIndebido );
     // Pre: ! esVacio()
     // Post: modifica la pila, quitando el elemento que está en la cima
     // Lanza la excepción "EAccesoIndebido" si la pila está vacía
     // O(1)

     TElem cima( ); //throw ( EAccesoIndebido );
     // Pre: ! esVacio()
     // Post: devuelve el elemento que está en la cima de la pila
     // Lanza la excepción "EAccesoIndebido" si la pila está vacía
     // O(1)

     bool esLleno( );
     // Pre: true
     // Post: determina si la pila tiene 'longMax' elementos
     // O(1)

	
  // Escritura
     void escribe( );
     // Pre: true
     // Post: escribe el contenido de la pila

	
  private:
	
  // Variables privadas
	
     TElem _espacio[longMax];
     int _indCima;
	
};




/*
 
    Implementación estática de las pilas como arrays
 
*/



//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//                       OPERACIONES PUBLICAS                               //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////



template<class TElem>
TPila<TElem>::TPila( ) {

  _indCima = -1;

}



template<class TElem>
bool TPila<TElem>::esVacio( ) {

  return _indCima == -1;

}



template<class TElem>
void TPila<TElem>::apila( TElem x ) //throw ( EDesbordamiento ) 
{

  if ( esLleno( ) )
	  
    throw EDesbordamiento( "Pila llena" );
	
  else {
	  
    _indCima++;
    _espacio[_indCima] = x;
	  
  }

}



template<class TElem>
void TPila<TElem>::desapila( ) //throw ( EAccesoIndebido ) 
{

  if ( esVacio( ) )
	  
    throw EAccesoIndebido( "No se puede desapilar de la pila vacía" );
	
  else
	  
    _indCima--;

}



template<class TElem>
TElem TPila<TElem>::cima( ) //throw ( EAccesoIndebido ) 
{

  if ( esVacio( ) )
	  
    throw EAccesoIndebido( "No existe la cima de la pila vacia" );
	
  else
	  
    return _espacio[_indCima];

}



//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//                       OPERACIONES DE ESCRITURA                           //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////



template<class TElem>
void TPila<TElem>::escribe( ) {

  cout << endl;
	
  for ( int i = 0; i <= _indCima; i++ ) {
	  
    cout << _espacio[i];
	  
    if ( i < _indCima )
      cout << ", ";
	  
  }
	
  cout << endl;
  cout << endl;

}




//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//             OPERACIONES AUXILARES DE LA ESPECIFICACION                   //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////


/*
 
    Limitación impuesta por la implementación (esLleno)

*/


template<class TElem>
bool TPila<TElem>::esLleno( ) {

  return _indCima == longMax - 1;

}



#endif
