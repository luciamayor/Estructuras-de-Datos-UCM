/*

    PRACTICA 1: IMPLEMENTACION EN C++ DEL TAD DE LOS NUMEROS COMPLEJOS SOBRE LOS ENTEROS

    ASIGNATURA: ESTRUCTURAS DE DATOS
    CURSO:      2026-2027
    SUBGRUPO:    

    APELLIDOS:	
    NOMBRE:	    	

*/


#include <iostream>
#include <string>


using namespace std;


class MiComplejo {
	
	public:
		
		MiComplejo();
		MiComplejo(int, int);
		int re();
		int im();
		void suma(MiComplejo &c);
		void resta(MiComplejo &c);
		void conjugado();
		bool iguales(MiComplejo &c);
    	MiComplejo& operator=(MiComplejo &p);
		bool operator==(MiComplejo &c);
		void mostrar();
		
	private:
		
		int p_re;
		int p_im;
	
};


MiComplejo::MiComplejo() {
	
   p_re = 0;
   p_im = 0;
   
}


MiComplejo::MiComplejo(int x, int y) {
	
   p_re = x;
   p_im = y;
   
}


int MiComplejo::re() {

	return p_re;
	
}


int MiComplejo::im() {

	return p_im;
	
}


void MiComplejo::suma(MiComplejo &c) {
	
	p_re += c.p_re;
	p_im += c.p_im;
	
}


void MiComplejo::resta(MiComplejo &c) {
	
	p_re -= c.p_re;
	p_im -= c.p_im;
	
}


void MiComplejo::conjugado() {
	
	p_im = -p_im;
	
}


bool MiComplejo::iguales(MiComplejo &c) {
	
	if (this == &c) return true;
	
	if ((p_re == c.p_re) && (p_im == c.p_im)) return true;
	else return false;
	
}


bool MiComplejo::operator==(MiComplejo &c) {  

	if (this == &c) return true;

   	if ((p_re == c.p_re) && (p_im == c.p_im)) return true;
   	
   	else return false;
}


MiComplejo& MiComplejo::operator=(MiComplejo &c){  	

	if (this != &c) {
		
		this->p_re = c.p_re;
		this->p_re = c.p_re;
		
	}
	
	return *this;
	
}


void MiComplejo::mostrar() {
	
	cout << "Parte real: " << p_re << endl << "Parte imaginaria: " << p_im << endl;
	
}