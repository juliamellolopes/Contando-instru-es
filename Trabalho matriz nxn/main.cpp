#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main(){
	int N;
	int intervalo = 99;
	
	//criar matriz com o tamanho informado pelo usuario
	cout << "Informe N para o tamanho da matriz NxN: ";
	cin >> N;
	int matriz[N][N];
	
	//preencher a matriz com valores aleatórios de 0 a 99
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			matriz[N][N] = rand()%intervalo+0;
		}
	}
	
	//mostrar a matriz
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << " " << matriz[N][N];
		}
		cout << endl;
	}
	
		
	return 0;
}
