#ifndef lista_dinamicaH
#define lista_dinamicaH


/*

 
 especificacion LISTAS[ELEM]
 
 usa
 
    BOOLEANOS, NATURALES
  
 tipo
 
    lista
 
 operaciones
 
    vacio      :             -->  lista        { constructora }
    ponDelante : elem lista  -->  lista        { constructora }
    ponDetras  : lista elem  -->  lista         
    primero    : lista       -/-> elem                        
    quitaPrim  : lista       -/-> lista              
    ultimo     : lista       -/-> elem                        
    quitaUlt   : elem        -/-> lista               
    concatena  : lista lista -->  lista  
    esVacio    : lista       -->  bool                          
    numElem    : lista       -->  nat                           
    elemEn     : lista nat   -/-> elem   
 
  variables
 
    x, y   : elem
    xs, ys : lista
    n      : nat
 
  ecuaciones
 
    concatena(vacio, ys)                     = ys
    concatena(ponDelante(x, xs), ys)         = ponDelante(x, concatena(xs, ys))
 
    ponDetras(xs, x)                         = concatena(xs, ponDelante(x, vacio))
 
    esVacio(vacio)                           = cierto
    esVacio(ponDelante(x, xs))               = falso
 
    primero(vacio)                           = error
    primero(ponDelante(x, xs))               = x
 
    quitaPrim(vacio)                         = error
    quitaPrim(ponDelante(x, xs))             = xs
 
    ultimo(vacio)                            = error
    ultimo(ponDelante(x, xs))                = x            <==  esVacio(xs)
    ultimo(ponDelante(x, xs))                = ultimo(xs)   <== ¬esVacio(xs)
 
    quitaUlt(vacio)                          = error
    quitaUlt(ponDelante(x, xs))              = vacio        <==  esVacio(xs)
    quitaUlt(ponDelante(x, xs))              = ponDelante(x, quitaUlt(xs))
                                                            <== ¬esVacio(xs)
 
    numElem(vacio)                           = cero
    numElem(ponDelante(x, xs))               = suc(numElem(xs))
 
    elemEn(xs, n)                            = error <== ( n == cero ) \/ 
                                                         ( n > (numElem xs) )
    elemEn(ponDelante(x, xs), suc(cero))     = x
    elemEn(ponDelante(x, ponDelante(y, ys)), suc(suc(n))
                                             = elemEn(ponDelante(y, ys), suc(n))
 
 fespecificacion


 La complejidad de las operaciones viene dada por el número "n" de elementos
 de la lista.

 
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



// Clase de los nodos de la lista


template <class TElem>
class TListaDinamica;


template <class TElem>
class TNodoLista {
	
  private:
	
    TElem _elem;
    TNodoLista<TElem> *_sig, *_ant;
	
    TNodoLista( TElem, TNodoLista<TElem>* = 0, TNodoLista<TElem>* = 0 );
	
  public:
	
    TElem elem( );
    TNodoLista<TElem>* sig( );
    TNodoLista<TElem>* ant( );
	
    friend class TListaDinamica<TElem>;
	
};



// Clase de las listas genericas


template <class TElem>
class TListaDinamica {
	
  public:

  // Constructora
	
     TListaDinamica( );
     // O(1)


  // Operaciones de las listas
	
     void ponDetras( TElem );
     // Pre: true
     // Post: Se añade 'elem' al final de la lista
     // O(1) sobre tipos predefinidos

     void ponDelante( TElem );
     // Pre: true
     // Post: Se añade 'elem' al principio de la lista
     // OO(1) sobre tipos predefinidos

     TElem primero( ); // throw ( EAccesoIndebido );
     // Pre: ! esVacio( )
     // Post: Devuelve el primer elemento de la lista
     // Lanza la excepcion "EAccesoIndebido" si la lista esta vacia
     // O(1)

     TElem ultimo( ); // throw ( EAccesoIndebido );
     // Pre: ! esVacio( )
     // Post: Devuelve el último elemento de la lista
     // Lanza la excepcion "EAccesoIndebido" si la lista esta vacia
     // O(1)

     void quitaPrim( ); // throw ( EAccesoIndebido );
     // Pre: ! esVacio( )
     // Post: Elimina el primer elemento de la lista
     // Lanza la excepción "EAccesoIndebido" si la lista esta vacia
     // O(1) sobre tipos predefinidos

     void quitaUlt( ); // throw ( EAccesoIndebido );
     // Pre: ! esVacio( )
     // Post: Elimina el último elemento de la lista
     // Lanza la excepción "EAccesoIndebido" si la lista esta vacia
     // O(1) sobre tipos predefinidos

     bool esVacio( );
     // Pre: true
     // Post: Devuelve true o false según si la pila esta o no vacia
     // O(1)

     void concatena( TListaDinamica<TElem>& lista );
     // Pre: true
     // Post: concatena la lista pasada como parametro, dejándola vacia
     // O(1)

     int numElem( );
     // Pre: true
     // Post: Devuelve el numero de elementos de la lista
     // O(1)

     TElem elemEn( int n ); // throw ( EAccesoIndebido );
     // Pre: 1 <= n <= numElem( )
     // Post: Devuelve el elemento en la posicion n
     // O(n)

	
  // Escritura
	
     void escribe( );
     // O(n)
	

  private:
	
  // Variables privadas
	
	 int _longitud;
     TNodoLista<TElem> *_prim, *_ult;
     
};



//---------------------------------------------------------------------------
// IMPLEMENTACION
//---------------------------------------------------------------------------



  // Clase de los nodos

    template <class TElem>
    TNodoLista<TElem>::TNodoLista( TElem elem, TNodoLista<TElem>* sig, TNodoLista<TElem>* ant ) :
      _elem(elem), _sig(sig), _ant(ant) {
    };


    template <class TElem>
    TElem TNodoLista<TElem>::elem( ) {
		
      return _elem;
		
    }


    template <class TElem>
    TNodoLista<TElem>* TNodoLista<TElem>::sig( ) {
		
      return _sig;
		
    }


    template <class TElem>
    TNodoLista<TElem>* TNodoLista<TElem>::ant( ) {
		
      return _ant;
		
    }


  // Constructora

     template <class TElem>
     TListaDinamica<TElem>::TListaDinamica( ) :
       _prim(0), _ult(0), _longitud(0) {
     };


  // Operaciones de las listas

     template <class TElem>
     void TListaDinamica<TElem>::ponDetras( TElem elem ) {
		 
       TNodoLista<TElem>* p = new TNodoLista<TElem>(elem);
		 
       if( esVacio( ) )
		   
         _prim = _ult = p;
		 
       else {
		   
         _ult -> _sig = p;
         p -> _ant = _ult;
         _ult = p;
		   
       }
		 
       _longitud++;
		 
     };


     template <class TElem>
     void TListaDinamica<TElem>::ponDelante( TElem elem ) {
		 
       TNodoLista<TElem>* p = new TNodoLista<TElem>(elem);
		 
       if( esVacio( ) )
		   
         _prim = _ult = p;
		 
       else {
		   
         _prim -> _ant = p;
         p -> _sig = _prim;
         _prim = p;
		   
       }
		 
       _longitud++;
		 
     };


     template <class TElem>
     TElem TListaDinamica<TElem>::primero( ) // throw ( EAccesoIndebido ) 
	 {
		 
       if( esVacio( ) )
		   
         throw EAccesoIndebido( "Error: no existe el primero de la lista vacia" );
       
	   else
		   
         return _prim -> elem( );
		 
     };


     template <class TElem>
     TElem TListaDinamica<TElem>::ultimo( ) // throw ( EAccesoIndebido ) 
	 {
		 
       if( esVacio() )
		   
         throw EAccesoIndebido( "Error: no existe el ultimo de la lista vacia" );
       
	   else
		   
         return _ult -> elem( );
		 
     };


     template <class TElem>
     void TListaDinamica<TElem>::quitaPrim( ) // throw ( EAccesoIndebido ) 
	 {
		 
       if( esVacio( ) )
		   
         throw EAccesoIndebido( "Error: no se puede quitar el primero de la lista vacia" );
       
	   else {
		   
         TNodoLista<TElem>* tmp = _prim;
		   
         _prim = _prim -> sig( );
		   
         if( _prim == 0 )
			 
           _ult = 0;
         
		 else
			 
           _prim -> _ant = 0;
         
		 delete tmp;
		   
         _longitud--;
		   
       }
		 
     };


     template <class TElem>
     void TListaDinamica<TElem>::quitaUlt( ) // throw ( EAccesoIndebido ) 
	 {
		 
       if( esVacio( ) )
		   
         throw EAccesoIndebido( "Error: no se puede quitar el ultimo de la lista vacia" );
       
	   else {
		   
         TNodoLista<TElem>* tmp = _ult;
		   
         _ult = _ult ->ant( );
		   
         if ( _ult == 0 )
			 
           _prim = 0;
		   
         else
			 
           _ult -> _sig = 0;
		   
         delete tmp;
		   
         _longitud--;
		   
       }
		 
     };


     template <class TElem>
     bool TListaDinamica<TElem>::esVacio( ) {
		 
       return _prim == 0;
		 
     };


     template <class TElem>
     void TListaDinamica<TElem>::concatena( TListaDinamica<TElem>& lista ) {

       if ( ! lista.esVacio( ) ) {
		   
         if ( esVacio( ) ) {
			 
           _prim = lista._prim;
           _ult = lista._ult;
           _longitud = lista._longitud;
			 
         }
         else {
			 
           _ult -> _sig = lista._prim;
           lista._prim -> _ant = _ult;
           _ult = lista._ult;
           _longitud += lista._longitud;
			 
         }
		   
         lista._prim = 0;
         lista._ult = 0;
         lista._longitud = 0;
		   
       }

     }


     template <class TElem>
     int TListaDinamica<TElem>::numElem( ) {

       return _longitud;

     }



     template <class TElem>
     TElem TListaDinamica<TElem>::elemEn( int n ) // throw ( EAccesoIndebido ) 
	 {

       if ( ( n < 1 ) || ( n > numElem( ) ) )
		   
         throw EAccesoIndebido( "Error: posicion inexistente" );

       TNodoLista<TElem>* p = _prim;
		 
       for ( int i = 1; i < n; i++ )
		   
         p = p -> sig( );
		 
       return p -> elem( );
		 
     }



  // Operaciones de entrada/salida

     template <class TElem>
     void TListaDinamica<TElem>::escribe( ) {
		 
       TNodoLista<TElem>* tmp = _prim;
		 
		 cout << endl;
		 
       while ( tmp != 0 ) {
		   
         cout << tmp -> elem( ) << " ";
         tmp = tmp -> sig( );
		   
       }
		 
	   cout << endl;
		 
     };



#endif