#ifndef arbusH
#define arbusH


#include <iostream>
#include "secuencia_dinamica.h"


// Excepciones nuevas generadas por las operaciones de este TAD:
// Acceso cuando se accede con una clave que no esta en el arbol
// class EClaveErronea { };


using namespace std;


// El tipo 'TClave' debe implementar:
//    operator==
//    operator<
//    operator>


template <class TClave, class TValor>
class TArbus;

template <class TClave, class TValor>
class TNodoArbus {
	
  private:
	
    TClave _clave;
    TValor _valor;
	
    TNodoArbus<TClave,TValor> *_iz, *_dr;
	
    TNodoArbus( TClave, TValor, TNodoArbus<TClave,TValor>*, TNodoArbus<TClave,TValor>* );
	
  public:
	
    TClave clave();
    TValor valor();
	
    TNodoArbus<TClave,TValor>* iz();
    TNodoArbus<TClave,TValor>* dr();
	
    friend class TArbus<TClave,TValor>;
	
};



template <class TClave, class TValor>
class TArbus {
	
	
  public:

	
  // Constructoras
	
     TArbus( );
     TArbus( TArbus<TClave,TValor>& );
    

  // Operaciones de los arboles de busqueda
	
     void inserta( TClave, TValor );
     // Pre  : true
     // Post : inserta un par (clave,valor) en el arbol
	 //        si la clave ya esta en el arbol, se sustituye el valor antiguo por el nuevo

     void borra( TClave );
     // Pre  : true
     // Post : elimina un par (clave,valor) del arbol a partir de una clave dada
     //        si la clave no esta, el arbol no se modifica

     TValor consulta( TClave ); // throw ( EClaveErronea );
     // Pre  : esta( clave )
     // Post : devuelve el valor asociado con la clave dada
     // Lanza la excepcion 'EClaveErronea' si el arbol no contiene dicha clave

     bool esta( TClave );
     // Pre  : true
     // Post : devuelve true o false segun si el arbol contiene o no la clave

     bool esVacio( );
     // Pre: true
     // Post: Devuelve true o false segun si el arbol esta o no vacio

	
  // Recorridos 
	
	 TSecuenciaDinamica<TValor> recorre( );
	 // Pre  : true
	 // Post : devuelve los valores del arbol, ordenados por la clave
	
	 TSecuenciaDinamica<TClave> recorreClave( );
	 // Pre  : true
	 // Post : devuelve las claves del arbol ordenadas
	
	
  // Escritura
	
     void escribe( );

	
	
  private:

	
  // Variables privadas
	
     TNodoArbus<TClave,TValor>* _ra;
	
  // operacion privada de escritura
	
     void escribeAux( TNodoArbus<TClave, TValor>*, string );
	
  // operaciones auxiliares para los algoritmos recursivos
	
     void insertaAux( TClave, TValor, TNodoArbus<TClave, TValor>* &  );
	
	 TNodoArbus<TClave,TValor>* busca( TClave, TNodoArbus<TClave, TValor>* );
	
     void borraAux( TClave, TNodoArbus<TClave,TValor>* & );
     void borraRaiz( TNodoArbus<TClave,TValor>* & );
     void borraConMin( TNodoArbus<TClave,TValor>* &, TNodoArbus<TClave,TValor>* & );
	 
	
};



//---------------------------------------------------------------------------
//                              IMPLEMENTACION
//---------------------------------------------------------------------------



  // Clase de los nodos del arbol de busqueda

    template <class TClave, class TValor>
    TNodoArbus<TClave,TValor>::TNodoArbus( TClave clave, TValor valor, 
										   TNodoArbus<TClave,TValor>* iz, 
										   TNodoArbus<TClave,TValor>* dr ) :
      _clave(clave), _valor(valor), _iz(iz), _dr(dr) {
    };


    template <class TClave, class TValor>
    TClave TNodoArbus<TClave,TValor>::clave( ) {
		
      return _clave;
		
    }


    template <class TClave, class TValor>
    TValor TNodoArbus<TClave,TValor>::valor( ) {
		
      return _valor;
		
    }


    template <class TClave, class TValor>
    TNodoArbus<TClave,TValor>* TNodoArbus<TClave,TValor>::iz( ) {
		
      return _iz;
		
    }


    template <class TClave, class TValor>
    TNodoArbus<TClave,TValor>* TNodoArbus<TClave,TValor>::dr( ) {
		
      return _dr;
		
    }


  // Constructoras de la clase de arboles de busqueda

     template <class TClave, class TValor>
     TArbus<TClave,TValor>::TArbus( ) :
       _ra( 0 ) {
     };


  // Operaciones de los arboles de busqueda


     // Insercion

     template <class TClave, class TValor>
     void TArbus<TClave,TValor>::inserta( TClave clave, TValor valor ) {
		 
       insertaAux( clave, valor, _ra );
		 
     };


     template <class TClave, class TValor>
     void TArbus<TClave,TValor>::insertaAux( TClave clave, TValor valor, TNodoArbus<TClave,TValor>* & p) {
		 
       if ( p == 0 )
		   
         p = new TNodoArbus<TClave,TValor>( clave, valor, 0, 0 );
		 
       else if ( clave == p -> clave( ) )
		   
         p -> _valor = valor;
		 
       else if ( clave < p -> clave( ) )
		   
         insertaAux( clave, valor, p -> _iz );
		 
       else
		   
         insertaAux( clave, valor, p -> _dr );
		 
     };



     // Borrado

     template <class TClave, class TValor>
     void TArbus<TClave,TValor>::borra( TClave clave ) {
		 
       borraAux( clave, _ra );
		 
     };


     template <class TClave, class TValor>
     void TArbus<TClave,TValor>::borraAux( TClave clave, TNodoArbus<TClave,TValor>* & p ) {
		 
       if ( p != 0 ) {
		   
         if ( clave == p -> clave( ) )
			 
           borraRaiz(p);
		   
         else if ( clave < p -> clave( ) )
			 
           borraAux( clave, p -> _iz );
		   
         else
			 
           borraAux( clave, p -> _dr );
		   
       }
		 
     };


     template <class TClave, class TValor>
     void TArbus<TClave,TValor>::borraRaiz( TNodoArbus<TClave,TValor>* & p ) {
		 
       TNodoArbus<TClave,TValor>* aux;

       if ( p -> iz( ) == 0 ) {
		   
         aux = p;
         p = p -> dr( );
		   
         delete aux;
		   
       }
       else if ( p -> dr() == 0 ) {
		   
         aux = p;
         p = p -> iz();
		   
         delete aux;
		   
       }
       else
		   
         borraConMin( p, p -> _dr );
		 
     };


     template <class TClave, class TValor>
     void TArbus<TClave,TValor>::borraConMin( TNodoArbus<TClave,TValor>* & p, TNodoArbus<TClave,TValor>* & q ) {
		 
       TNodoArbus<TClave,TValor>* aux;

       if ( q -> iz( ) != 0 )
		   
         borraConMin( p, q -> _iz );
		 
       else {
		   
         p -> _clave = q -> clave( );
         p -> _valor = q -> valor( );
		   
         aux = q;
         q = q -> dr( );
		   
         delete aux;
		   
       }
		 
     };
 
 

     // Consultas

     template <class TClave, class TValor>
     TValor TArbus<TClave,TValor>::consulta( TClave clave ) // throw ( EClaveErronea ) 
	 {
		 
       TNodoArbus<TClave,TValor>* aux;

       aux = busca(clave, _ra);
		 
       if ( aux == 0 )
		   
         throw EClaveErronea( "Error: el arbol no contiene la clave" );
		 
       else
		   
         return aux -> valor( );
		 
     };


     template <class TClave, class TValor>
     bool TArbus<TClave,TValor>::esta( TClave clave ) {
		 
       return busca(clave, _ra) != 0;
		 
     };


     template <class TClave, class TValor>
     TNodoArbus<TClave,TValor>* TArbus<TClave,TValor>::busca( TClave clave, TNodoArbus<TClave,TValor>* p ) {
		 
       TNodoArbus<TClave,TValor>* r;

       if ( p == 0 )
		   
         r = 0;
		 
       else if ( clave == p -> clave( ) )
		   
         r = p;
		 
       else if ( clave < p -> clave( ) )
		   
         r = busca( clave, p -> iz( ) );
		 
       else
		   
         r = busca( clave, p -> dr( ) );
		 
       return r;
		 
     };


     template <class TClave, class TValor>
     bool TArbus<TClave,TValor>::esVacio( ) {
		 
       return _ra == 0;
		 
     };



  // Recorridos

     template <class TClave, class TValor>
     void inOrdAcu( TNodoArbus<TClave,TValor>* p, TSecuenciaDinamica<TValor>& xs ) {
		 
       if ( p != 0 ) {
		   
         inOrdAcu( p -> iz( ), xs );
		   
         xs.inserta( p -> valor( ) );
		   
         inOrdAcu( p -> dr( ), xs );
		   
       }
		 
     };


     template <class TClave, class TValor>
     TSecuenciaDinamica<TValor> TArbus<TClave,TValor>::recorre( ) {
		 
       TSecuenciaDinamica<TValor> r;

       inOrdAcu( _ra, r );
		 
       return r;
		 
     };


     template <class TClave, class TValor>
     void inOrdAcuClave( TNodoArbus<TClave,TValor>* p, TSecuenciaDinamica<TClave>& xs ) {
		 
       if ( p != 0 ) {
		   
         inOrdAcuClave( p -> iz( ), xs );
		   
         xs.inserta( p -> clave( ) );
		   
         inOrdAcuClave( p -> dr( ), xs );
		   
       }
		 
     };


     template <class TClave, class TValor>
     TSecuenciaDinamica<TClave> TArbus<TClave,TValor>::recorreClave( ) {
		 
       TSecuenciaDinamica<TClave> r;

       inOrdAcuClave( _ra, r );
		 
       return r;
		 
     };

 

  // Operaciones de escritura de arboles binarios de busqueda


     template <class TClave, class TValor>
     void TArbus<TClave,TValor>::escribeAux( TNodoArbus<TClave,TValor>* p, string prefijo ) {
		 
       if ( p != 0 ) {
		   
         cout << ( prefijo + " : " ) << "(" << p -> clave( ) << "," << p -> valor( ) << ")" << endl;
		   
         escribeAux( p -> iz( ), prefijo + ".1" );
         escribeAux( p -> dr( ), prefijo + ".2" );
		   
       }
		 
     }


     template <class TClave, class TValor>
     void TArbus<TClave,TValor>::escribe( ) {
		 
	   cout << endl;
		 
       escribeAux( _ra, "1" );
		 
     };



#endif