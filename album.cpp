#include <iostream>
#include <stdlib.h>
#include "Paquete.h"
using namespace std;

bool vistaIngresada( int totalPaquetes, int vista, int* _nuevos ){
	for (int i = 0; i < totalPaquetes; ++i){
		if( _nuevos[i] != 0 && _nuevos[i] == vista )
			return true;
	}
	return false;
}

void setCover( int tamPaquete, int totalPaquetes, Paquete** _paquetes, int* _nuevos, int* _vistasIngresadas ){
	int cont = 0;
	int contValores = 0;
	int acum = 0;
	int tmp[tamPaquete];
	for (int i = 0; i < totalPaquetes; ++i){	
		for (int j = 0; j < tamPaquete; ++j){
			if( vistaIngresada(totalPaquetes, _paquetes[i]->getVistas()[j], _vistasIngresadas ) == false ){
				tmp[cont] = _paquetes[i]->getVistas()[j];
				cont++;
			}
		}
		if( (cont/tamPaquete)*100 >= 50 || cont >= 1 ){
			_nuevos[contValores] = i;
			contValores++;
			for (int j = 0; j < cont; ++j){
				_vistasIngresadas[acum] = tmp[j];
				acum++;
			}
		}
		cont = 0;
	}
}

void llenarPaquetes( int tamPaquete, int totalPaquetes, Paquete** _paquetes ){
	int num = 0;
	int cont = 0;
	int tot = tamPaquete*totalPaquetes;
	bool usado[tot];
	int* package = new int[tot];
	int* mezcla = new int[tot];
	for (int i = 0; i < tot; ++i)
		usado[i] = false;
	for (int i = 0; i < 639; ++i)
		package[i] = (i+1);
	srand(time(NULL));
	for (int i = 639; i < tot; ++i)
		package[i] = rand()%638 + 1;
	int index = 0;
	for (int i = 0; i < tot; ++i){
		do{
			index = rand()%tot;
		}while( usado[index] );
		mezcla[i] = package[index];
		usado[index] = true;
	}

	for (int i = 0; i < totalPaquetes; ++i){
		for (int j = 0; j < tamPaquete; ++j){
			_paquetes[i]->agregarVista( mezcla[cont] );
			cont++;
		}
	}

	free( package );
	free( mezcla );
}

int main(){
	int tamPaquete = 0;
	int totalPaquetes = 0;

	do{
		cout << "ingrese cantidad total de paquetes:" << endl;
		cin >> totalPaquetes;
	}while( totalPaquetes <= 0);
	do{
		cout << "ingrese cantidad de vistas por paquete:" << endl;
		cin >> tamPaquete;
	}while( tamPaquete <= 0 );
	
	Paquete** _paquetes = new Paquete*[totalPaquetes];
	int* _seleccionados = new int[totalPaquetes];
	int* _vistasIngresadas = new int[totalPaquetes*tamPaquete];
	for (int i = 0; i < totalPaquetes; ++i){
		_seleccionados[i] = -1;
		_paquetes[i] = new Paquete( tamPaquete );	
	}
	for (int i = 0; i < (totalPaquetes*tamPaquete); ++i)
		_vistasIngresadas[i] = 0;
	llenarPaquetes( tamPaquete, totalPaquetes, _paquetes );
	
	cout << "---------------------------------------------- Paquetes ----------------------------------------------" << endl;
	for (int i = 0; i < totalPaquetes; ++i)
		cout << (i+1) << ") " << _paquetes[i]->toString() << endl;
	cout << "------------------------------------- Fin ---- Paquetes ----------------------------------------------" << endl;

	setCover( tamPaquete, totalPaquetes, _paquetes, _seleccionados, _vistasIngresadas );
	cout << "---------------------------------------------- Paquetes - Set Cover ----------------------------------" << endl;
	int cantSeleccionados = 0;
	int suma = 0;
	for (int i = 0; i < totalPaquetes; ++i){
		if( _seleccionados[i] != -1 ){
			cout << (i+1) << ") " << _paquetes[_seleccionados[i]]->toString() << endl;
			cantSeleccionados++;
		}
	}
	cout << "--------------------------------------- Fin -- Paquetes - Set Cover ----------------------------------" << endl;
	cout << "\nCantidad de paquetes seleccionados: " << cantSeleccionados << endl;

	cout << "---------------------------------------------- Vistas ------------------------------------------------" << endl;
	for (int i = 0; i < (totalPaquetes*tamPaquete); ++i){
		if( _vistasIngresadas[i] != 0 )
			cout << _vistasIngresadas[i] << " , ";
	}
	cout << endl;
	free( _paquetes );
	free( _seleccionados );
	free( _vistasIngresadas );

	return 0;
}