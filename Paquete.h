#ifndef PAQUETE_H
#define PAQUETE_H
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Paquete{
private:
	int tam;
	int n;
	int* vistas;
public:
	Paquete( int tam ){
		this->tam = tam;
		this->n = 0;
		this->vistas = new int[tam];
	};

	bool agregarVista( int numero ){
		if( n < tam ){
			this->vistas[n] = numero;
			n++;
			return true;
		}else
			return false;
	};

	int buscarVista( int numero ){
		for (int i = 0; i < this->n; ++i){
			if( this->vistas[i] == numero )
				return i;
		}
		return -1;
	};

	int* getVistas(){
		return this->vistas;
	};

	string toString(){
		string ret = "Vistas: ";
		stringstream ss;
		for (int i = 0; i < this->n; ++i){
			ss << this->vistas[i];
			if( i < this->n-1 )
				ret += ss.str() + " , ";
			else if( i == this->n-1 )
				ret += ss.str();
			ss.str("");
		}
		return ret;
	};

	~Paquete(){
		free( this->vistas );
	}
};

#endif //PAQUETE_H