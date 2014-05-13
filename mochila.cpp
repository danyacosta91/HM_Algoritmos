#include <iostream>
#include <stdlib.h>
using namespace std;

struct Objeto
{
	int precio;
	int peso;
};

void llenarArreglo( Objeto** obj, int n, int k ){
	srand (time(NULL));
	for (int i = 0; i < n; ++i){
		obj[i] = new Objeto();
		obj[i]->precio =  rand()%1000 + 1;
		obj[i]->peso =  rand()%k + 1;
	}
}

bool cabeEnMochila( Objeto** moch, int n, int k, int cant ){
	int suma = 0;
	for (int i = 0; i < n; ++i){
		if( moch[i] != 0 )
			suma += moch[i]->peso;
	}
	if( (suma+cant) <= k )
		return true;
	return false;
}

void llenarMochila( Objeto** obj, Objeto** moch, int n, int k ){
	int contM = 0;
	for (int i = 0; i < n; ++i){
		if( cabeEnMochila(moch, n, k, obj[i]->peso ) && (obj[i]->peso/obj[i]->precio) < 1 ){
			moch[contM] = obj[i];
			contM++;
		}
	}
}

int main(){
	int k = 0;
	int n = 0;

	do{
		cout << "Ingrese n: " << endl;
		cin >> n;
	}while(n <= 0);

	do{
		cout << "Ingrese k: " << endl;
		cin >> k;
	}while(k <= 0);

	Objeto** _objetos = new Objeto*[n];
	Objeto** _mochila = new Objeto*[n];
	for (int i = 0; i < n; ++i)
		_mochila[i] = 0;
	llenarArreglo( _objetos, n, k );	
	for (int i = 0; i < n; ++i)
		cout << "Precio: " << _objetos[i]->precio << " Peso: " << _objetos[i]->peso << endl;

	llenarMochila( _objetos, _mochila, n, k );

	cout << "--------------------------------- Mochila ----------------------------------" << endl;
	for (int i = 0; i < n; ++i){
		if( _mochila[i] != 0 )
			cout << "Precio: " << _mochila[i]->precio << " Peso: " << _mochila[i]->peso << endl;
	}

	free( _objetos );
	free( _mochila );
	return 0;
}