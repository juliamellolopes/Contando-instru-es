#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//using namespace std;

int main(){
	int N = 7;
	int somador = 0;
	srand(time(0));
	int i = 0;
	int j = 0;
	
	//criar matriz com o tamanho informado pelo usuario
//	cout << "Informe N para o tamanho da matriz NxN: ";
//	cin >> N;
	int matriz[N][N];
	int vetor[] = {6, 18, 7, 8, 9, 3, 1, 27, 45, 50, 6, 5, 1, 2, 21, 32, 44, 35, 0, 9, 22,
			15, 11, 7, 45, 4, 18, 7, 4, 9, 19, 10, 6, 89, 11, 23, 23, 27, 1, 91, 77, 6, 33, 28, 
			34, 18, 19, 96, 1};
	
	//preencher a matriz com valores aleatórios de 0 a 99
	for(i = 0; i < N; i++){
		for( j = 0; j < N; j++){
			matriz[N][N] = rand()%100;
		}
	}
	
	int cont = 0;
//	for(i = 0; i < N; i++){
//		for(j = 0; j < N; j++){
//			matriz[i][j] = vetor[cont];
//			cont++;
//		}
//	}
	
	for(i = 0; i < N; i++){
		for( j = 0; j < N; j++){
			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}
	
	i = j= 0;
	somador += matriz[0][0];
	matriz[0][0] = -1;
	
	while(i < N){
		while(j < N){
			if(i == N-1){
				if(matriz[i][j] >= 0){
					somador += matriz[i][j];
					matriz[i][j] = -1;
				}
				j++;
			}else if(j == 0){
				//se o da direita ou de baixo é maior
				if(matriz[i+1][j] >= matriz[i][j+1]){
					i++;
					somador += matriz[i][j];
					matriz[i][j] = -1;
				}else{
					j++;
					somador += matriz[i][j];
					matriz[i][j] = -1;
				}
			}else if(j == N-1){
				//se o da esquerda ou de baixo é maior 
				if(matriz[i+1][j] >= matriz[i][j-1]){
					i++;
					somador += matriz[i][j];
					matriz[i][j] = -1;
				}else{
					j--;
					somador += matriz[i][j];
					matriz[i][j] = -1;
				}	
			}else{
				if(matriz[i+1][j] >= matriz[i][j+1] && matriz[i+1][j] >= matriz[i][j-1]){
					i++;
					somador += matriz[i][j];
					matriz[i][j] = -1;
				}else if(matriz[i][j+1] >= matriz[i+1][j] && matriz[i][j+1] >= matriz[i][j-1]){
					j++;
					somador += matriz[i][j];
					matriz[i][j] = -1;
				}else if(matriz[i][j-1] >= matriz[i+1][j] && matriz[i][j-1] >= matriz[i][j+1]){
					j--;
					somador += matriz[i][j];
					matriz[i][j] = -1;
				}
			}
		}
		i++;
	}
	
	for(i = 0; i < N; i++){
		for( j = 0; j < N; j++){
			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}
	
//	//mostrar a matriz
//	for(int i = 0; i < N; i++){
//		for(int j = 0; j < N; j++){
//			cout << "\t" << matriz[i][j];
//		}
//		cout << endl;
//	}
	
	printf("%d\n",somador);

	return 0;
}
