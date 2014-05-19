#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

struct pesoCiudades{
	string _nombre1, _nombre2;
	int _peso;
};

struct Equipo{
	string _equipo;
	string _ciudad;
};

string crearCalendario( pesoCiudades** _ciudades, Equipo** _equipos, int m, int n, int i, int j ){
	string tmp = "";
	int cont = 0;
	for( int k = 0; k < n; k++ ){
		if( k != j && (_ciudades[cont]->_peso < _ciudades[m-1]->_peso) )
	}
	tmp += "\n";
}

void obtenerCalendario( pesoCiudades** _ciudades, Equipo** _equipos, int m, int n ){
	for( int i = m-1; i >= 0; i-- ){
		for( int j = 0; j <= i-1; j++ ){
			if( _ciudades[j]->_peso > _ciudades[j+1]->_peso ){
				pesoCiudades* tmp = _ciudades[j];
				_ciudades[j] = _ciudades[j+1];
				_ciudades[j+1] = tmp;
			}
		}
	}

	cout << "Ciudades ordenadas!" << endl;
	for( int i = 0; i < m; i++ ){
		cout << "Ciudad 1: " << _ciudades[i]->_nombre1 << " Ciudad 2: " << _ciudades[i]->_nombre2 <<
		" peso: " << _ciudades[i]->_peso << endl;
	}

	cout << "Equipos!" << endl;
	for( int i = 0; i < n; i++ ){
		cout << "Equipo: " << _equipos[i]->_equipo << " Ciudad: " << _equipos[i]->_ciudad << endl;
	}

	string calendario = "";
	cout << "\n" << endl;
	for( int i = 0; i < m; i++ ){
		if( i != (m-1) ){
			for( int j = 0; j < n; j++ ){
				if( _ciudades[i]->_nombre1 == _equipos[j]->_ciudad ){
					cout << "Ciudad: " << _ciudades[i]->_nombre1 << " Equipo: " << _equipos[j]->_equipo << endl;
					calendario += crearCalendario( _ciudades, _equipos, m, n, i, j );
				}
			}
		}
	}
}

int main(){
	pesoCiudades** _ciudades = new pesoCiudades*[6];
	for( int i = 0; i < 6; i++ )
		_ciudades[i] = new pesoCiudades();
	_ciudades[0]->_nombre1 = "Tocoa";_ciudades[0]->_nombre2 = "Ceiba";_ciudades[0]->_peso = 200;
	_ciudades[1]->_nombre1 = "Ceiba";_ciudades[1]->_nombre2 = "Tela";_ciudades[1]->_peso = 100;
	_ciudades[2]->_nombre1 = "SPS";_ciudades[2]->_nombre2 = "Tela";_ciudades[2]->_peso = 250;
	_ciudades[3]->_nombre1 = "SPS";_ciudades[3]->_nombre2 = "Puerto Cortez";_ciudades[3]->_peso = 100;
	_ciudades[4]->_nombre1 = "SPS";_ciudades[4]->_nombre2 = "Tegucigalpa";_ciudades[4]->_peso = 500;
	_ciudades[5]->_nombre1 = "SPS";_ciudades[5]->_nombre2 = "Copan";_ciudades[5]->_peso = 200;

	Equipo** _equipos = new Equipo*[10];
	for( int i = 0; i < 10; i++ )
		_equipos[i] = new Equipo();
	_equipos[0]->_equipo = "Olimpia";_equipos[0]->_ciudad = "Tegucigalpa";
	_equipos[1]->_equipo = "Motagua";_equipos[1]->_ciudad = "Tegucigalpa";
	_equipos[2]->_equipo = "Savio";_equipos[2]->_ciudad = "Copan";
	_equipos[3]->_equipo = "Maraton";_equipos[3]->_ciudad = "SPS";
	_equipos[4]->_equipo = "Real España";_equipos[4]->_ciudad = "SPS";
	_equipos[5]->_equipo = "Platense";_equipos[5]->_ciudad = "Puerto Cortez";
	_equipos[6]->_equipo = "Parrillas";_equipos[6]->_ciudad = "Tela";
	_equipos[7]->_equipo = "Vida";_equipos[7]->_ciudad = "Ceiba";
	_equipos[8]->_equipo = "Victoria";_equipos[8]->_ciudad = "Ceiba";
	_equipos[9]->_equipo = "Sociedad";_equipos[9]->_ciudad = "Tocoa";

	obtenerCalendario( _ciudades, _equipos, 6, 10 );

	free( _ciudades );
	free( _equipos );
	return 0;
}