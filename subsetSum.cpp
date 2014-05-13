#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

void limpiarArreglo(int* A, int tam){
	for (int i = 0; i < tam; ++i)
		A[i] = 0;
}

int Suma( int* N, int tam ){
	int suma = 0;
	for( int i = 0; i < tam; i++)
		suma += N[i];
	return suma;
}

bool subSet1( int* A, int* N, int k, int tam ){
	int j = 0;
	for( int init = 0; init < tam; init++){
		j = 1;
		limpiarArreglo( N, tam );
		N[0] = A[init];
		for (int i = 0; i < tam; ++i){
			if( i != init ){
				if( (Suma(N,j-1)+A[i]) < k ){
					N[j] = A[i];
					j++;
				}
				if( Suma(N, j) == k ){
					return true;
				}
			}
		}
	}
	return false;
}

bool subSet2( int* A, int* N, int k, int tam ){
	for( int init = 0; init < tam-1; init++){
		for (int i = init+1; i < tam; ++i){
			if( (A[i]+A[init]) == k ){
				N[0] = A[i];
				N[1] = A[init];
				return true;
			}
		}
	}
	return false;
}

bool subSet3( int* A, int* N, int k, int tam ){
	int j = 0;
	for( int init = 0; init < tam; init++){
		j = 1;
		limpiarArreglo( N, tam );
		N[0] = A[init];
		for (int i = 0; i < tam; ++i){
			if( i != init ){
				if( (Suma(N,j-1)+A[i]) > k ){
					N[j] = A[i];
					j++;
				}
				if( Suma(N, j) == k ){
					return true;
				}
			}
		}
	}
	return false;
}

void imprimirArreglo(int* A, int tam){
	for( int i = 0; i < tam; i++)
		cout << A[i] << " ";
	cout << "\n" << endl;
}

bool verificarNegativos(int* A, int tam){
	for (int i = 0; i < tam; ++i){
		if( A[i] >= 0 )
			return false;
	}
	return true;
}

int main(){
	int tam = 20;
	int* A = new int[tam];
	int* N = new int[tam];
	int k = 0;

	/*
	srand(time(NULL));
	for (int i = 0; i < tam; ++i)
		A[i] = rand()%1000-500;
	*/
	/*
	A[0] = 67;A[1] = 12;A[2] = 9;A[3] = 28;A[4] = 14;A[5] = 63;A[6] = 68;
	A[7] = 13;A[8] = 42;A[9] = 64;A[10] = 2;A[11] = 54;A[12] = 43;A[13] = 18;
	A[14] = 48;A[15] = 27;A[16] = 7;A[17] = 95;A[18] = 69;A[19] = 11;
	*/
	
	A[0] = -67;A[1] = -12;A[2] = -9;A[3] = -28;A[4] = -14;A[5] = -63;A[6] = -68;
	A[7] = -13;A[8] = -42;A[9] = -64;A[10] = -2;A[11] = -54;A[12] = -43;A[13] = -18;
	A[14] = -48;A[15] = -27;A[16] = -7;A[17] = -95;A[18] = -69;A[19] = -11;
	

	limpiarArreglo( N, tam );

	cout << "Arreglo original" << endl;
	imprimirArreglo(A, tam);

	cout << "Suma Total: " << Suma(A, tam) << endl;
	cout << "Ingrese el valor de 'k':" << endl;
	cin >> k;

	if( verificarNegativos(A, tam) == false ){
		if( subSet1(A, N, k, tam) ){
			cout << "Arreglo de suma" << endl;
			imprimirArreglo(N,tam);
		}else if( subSet2(A, N, k, tam) ){
			cout << "Arreglo de suma" << endl;
			imprimirArreglo(N,tam);
		}else
			cout << "\nNo se determino valores." << endl;
	}else{
		if( subSet3(A, N, k, tam) ){
			cout << "Arreglo de suma" << endl;
			imprimirArreglo(N,tam);
		}else if( subSet2(A, N, k, tam) ){
			cout << "Arreglo de suma" << endl;
			imprimirArreglo(N,tam);
		}else
			cout << "\nNo se determino valores." << endl;
	}

	free (A);
	free (N);

	return 0;
}