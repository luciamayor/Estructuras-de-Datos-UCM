#ifndef arbin_dinamicoH
#define arbin_dinamicoH


#include <iostream>
#include "secuencia_dinamica.h"


using namespace std;



template <class TElem>
class TArbinDinamico;


template <class TElem>
class TNodoArbin {
	
  private:
	
    TElem _elem;
    TNodoArbin<TElem> *_iz, *_dr;
	
    TNodoArbin( TElem, TNodoArbin<TElem>*, TNodoArbin<TElem>* );
	
  public:
	
    TElem& elem();
    TNodoArbin<TElem>* iz();
    TNodoArbin<TElem>* dr();
	
    friend class TArbinDinamico<TElem>;
	
};



template <class TElem>
class TArbinDinamico {
	
  public:
 
  // Constructoras
	
     TArbinDinamico( );
	
     TArbinDinamico( TArbinDinamico<TElem>&, TElem, TArbinDinamico<TElem>& );
	
	
  // Operaciones de los arboles
  
	 TArbinDinamico<TElem> hijoIz( ); // throw ( EAccesoIndebido );
     // Pre  : ! esVacio( )
     // Post : devuelve una copia del subarbol izquierdo
     // Lanza la excepcion 'EAccesoIndebido' si el arbol esta vacio

	
     TArbinDinamico<TElem> hijoDr ( ); // throw ( EAccesoIndebido );
     // Pre  : ! esVacio( )
     // Post : devuelve una copia del subarbol derecho
     // Lanza la excepcion 'EAccesoIndebido' si el arbol esta vacio


     TElem raiz( ); // throw ( EAccesoIndebido );
     // Pre  : ! esVacio( )
     // Post : devuelve el elemento almacenado en la raiz
     // Lanza la excepcion 'EAccesoIndebido' si el arbol esta vacio

	
     bool esVacio( );
     // Pre : true
     // Post: Devuelve true o false segun si el arbol esta o no vacio

		
  // Recorridos de arboles
	
	 TSecuenciaDinamica<TElem> preOrd( );
	 // Pre  : true
	 // Post : devuelve el recorrido en pre-orden del arbol
	
	 TSecuenciaDinamica<TElem> postOrd( );
	 // Pre  : true
	 // Post : devuelve el recorrido en post-orden del arbol
	
	 TSecuenciaDinamica<TElem> inOrd( );
	 // Pre  : true
	 // Post : devuelve el recorrido en in-orden del arbol  
	
		 
  // Operacion de escritura
	
     void escribe( );

	
  private:
	
  // Variables privadas
	
     TNodoArbin<TElem>* _ra;

	
  // Operaciones privadas

     void copia( TArbinDinamico<TElem>& );
	
     TNodoArbin<TElem>* copiaAux( TNodoArbin<TElem>* );
	
	
  // operacion privada de escritura
	
     void escribeAux( TNodoArbin<TElem>* p, string prefijo );
	
	
  // Constructora privada para los subarboles
	
     TArbinDinamico( TNodoArbin<TElem>* );

	
};



//---------------------------------------------------------------------------
//                              IMPLEMENTACION
//---------------------------------------------------------------------------



 // Clase de los nodos del arbol


    template <class TElem>
    TNodoArbin<TElem>::TNodoArbin( TElem elem, TNodoArbin<TElem>* iz, TNodoArbin<TElem>* dr ) :
      _elem(elem), _iz(iz), _dr(dr) {
    };


    template <class TElem>
    TElem& TNodoArbin<TElem>::elem( ) {
		
      return _elem;
		
    }


    template <class TElem>
    TNodoArbin<TElem>* TNodoArbin<TElem>::iz( ) {
		
      return _iz;
		
    }


    template <class TElem>
    TNodoArbin<TElem>* TNodoArbin<TElem>::dr( ) {
		
      return _dr;
		
    }



  // Constructoras de la clase de los nodos del arbol


     template <class TElem>
     TArbinDinamico<TElem>::TArbinDinamico( ) :
       _ra( 0 ) {
     };


     template <class TElem>
     TArbinDinamico<TElem>::TArbinDinamico( TArbinDinamico<TElem>& iz, TElem elem, TArbinDinamico<TElem>& dr ) :
       _ra( new TNodoArbin<TElem>( elem, copiaAux(iz._ra), copiaAux(dr._ra) ) ) {
     };



  // Constructora privada para los subarboles


	 template <class TElem>
	 TArbinDinamico<TElem>::TArbinDinamico( TNodoArbin<TElem>* ra ) :
	   _ra( ra ) {
	 };



  // Operaciones de los arboles


     template <class TElem>
     TArbinDinamico<TElem> TArbinDinamico<TElem>::hijoIz ( ) // throw ( EAccesoIndebido ) 
	 {
		 
       if( esVacio() )
		   
         throw EAccesoIndebido( "Error: no existe el hijo izquierdo de un arbol vacio" );
		 
       else
		   
         return TArbinDinamico<TElem>( copiaAux( _ra -> iz( ) ) );
		 
     };


     template <class TElem>
     TArbinDinamico<TElem> TArbinDinamico<TElem>::hijoDr( ) // throw ( EAccesoIndebido ) 
	 {
		 
       if( esVacio() )
		   
         throw EAccesoIndebido( "Error: no existe el hijo derecho de un arbol vacio" );
		 
       else
		   
         return TArbinDinamico<TElem>( copiaAux( _ra -> dr( ) ) );
		 
     };


     template <class TElem>
     TElem TArbinDinamico<TElem>::raiz( ) // throw ( EAccesoIndebido ) 
	 {
		 
       if( esVacio() )
		   
         throw EAccesoIndebido( "Error: no existe la raiz de un arbol vacio" );
		 
       else
		   
         return _ra -> elem( );
		 
     };


     template <class TElem>
     bool TArbinDinamico<TElem>::esVacio( ) {
		 
       return _ra == 0;
		 
     };



// Recorrido en pre-orden del arbol


   template <class TElem>
   void preOrdAcu( TNodoArbin<TElem>* p, TSecuenciaDinamica<TElem>& xs ) {
	   
      if ( p != 0 ) {
		  
		  xs.inserta( p -> elem( ) );
		  
		  preOrdAcu( p -> iz( ), xs );
		  preOrdAcu( p -> dr( ), xs );
		  
	  }
	   
   };


   template <class TElem>
   TSecuenciaDinamica<TElem> TArbinDinamico<TElem>::preOrd( ) {
	   
	   TSecuenciaDinamica<TElem> r;
	   
	   preOrdAcu( _ra, r );
	   
	   return r;
   
   };



// Recorrido en post-orden del arbol


   template <class TElem>
   void postOrdAcu( TNodoArbin<TElem>* p, TSecuenciaDinamica<TElem>& xs ) {
	   
	   if ( p != 0 ) {
		   
		   postOrdAcu( p -> iz( ), xs );
		   postOrdAcu( p -> dr( ), xs );
		   
		   xs.inserta( p -> elem( ) );
		   
	   }
	   
   };



   template <class TElem>
   TSecuenciaDinamica<TElem> TArbinDinamico<TElem>::postOrd( ) {
	   
	   TSecuenciaDinamica<TElem> r;
	   
	   postOrdAcu( _ra, r );
	   
	   return r;
	   
   };



// Recorrido en in-orden

   
   template <class TElem>
   void inOrdAcu( TNodoArbin<TElem>* p, TSecuenciaDinamica<TElem>& xs ) {
	   
	   if ( p != 0 ) {
		   
		   inOrdAcu( p -> iz( ), xs );
		   
		   xs.inserta( p -> elem( ) );
		   
		   inOrdAcu( p -> dr( ), xs );
	   
	   }
   
   };


   template <class TElem>
   TSecuenciaDinamica<TElem> TArbinDinamico<TElem>::inOrd( ) {
	   
	   TSecuenciaDinamica<TElem> r;
	   
	   inOrdAcu( _ra, r );
	   
	   return r;
   
   };



  // Operaciones de escritura de arboles


     template <class TElem>
     void TArbinDinamico<TElem>::escribeAux( TNodoArbin<TElem>* p, string prefijo ) {
		 
       if ( p != 0 ) {
		   
		   cout << ( prefijo + " : " ) << p -> elem( ) << endl;
		   
		   escribeAux( p -> iz( ), prefijo + ".1" );
		   escribeAux( p -> dr( ), prefijo + ".2" );
		   
       }
		 
     }


     template <class TElem>
     void TArbinDinamico<TElem>::escribe( ) {
		 
		 cout << endl;
		 
		 escribeAux( _ra, "1" );
		 
     };



  // Operaciones privadas


     template <class TElem>
     TNodoArbin<TElem>* TArbinDinamico<TElem>::copiaAux( TNodoArbin<TElem>* p ) {
		 
       TNodoArbin<TElem>* r;

       if ( p == 0 )
		   
         r = 0;
		 
       else
		   
         r = new TNodoArbin<TElem>( p -> elem( ), copiaAux( p -> iz( ) ), copiaAux( p -> dr( ) ) );
		 
       return r;
		 
     };


     template <class TElem>
     void TArbinDinamico<TElem>::copia( TArbinDinamico<TElem>& arb) {
		 
       _ra = copiaAux( arb._ra );
		 
     };



#endif