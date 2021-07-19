#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(){
	int N = 7;
	int somador = 0;
	srand(time(0));
	int i = 0;
	int j = 0;
	
	//criar matriz com o tamanho informado pelo usuario
	print("Informe N para o tamanho da matriz NxN: ");
	scanf("%d", &N);
	int matriz[N][N];
	
	//preencher a matriz com valores aleatórios de 0 a 99
	for(i = 0; i < N; i++){
		for( j = 0; j < N; j++){
			matriz[i][j] = rand()%100;
		}
	}

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
	
	printf("%d\n",somador);

	return 0;
}
