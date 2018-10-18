#include <stdio.h>
#include <stdlib.h>
#include <ctime> 
#include <omp.h>

int size =1000;
int **multMatrices(int **&matriz1, int **&matriz2, int **&resultado);

int main(){
    
    srand((unsigned)time(0));

    printf("Inicio \n");
    int **mat1 = (int **)malloc (size*sizeof(int *));
    int **mat2 = (int **)malloc (size*sizeof(int *));
    int **matRes = (int **)malloc (size*sizeof(int *));
    for(int i = 0; i< size;i++){ 
        mat1[i] = (int *)malloc(size*sizeof(int));
        mat2[i] = (int *)malloc(size*sizeof(int));
        matRes[i] = (int *)malloc(size*sizeof(int));
    }	
	
    for(int i= 0;i<size;i++){
        for(int j=0;j<size;j++){
            mat1[i][j] = rand () % (5-0+1) + 5;
            mat2[i][j] = rand () % (5-0+1) + 5;
        }
    }
    
	
    multMatrices(mat1,mat2, matRes);
    /*
    printf("Matriz 1: \n");
    for(int i= 0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%4d %s",mat1[i][j],(j==size-1) ? "\n" : " ");

        }
    }
    printf("Matriz 2: \n");
    for(int i= 0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%4d %s",mat2[i][j],(j==size-1) ? "\n" : " ");

        }
    }
    

	for(int i= 0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%4d %s",matRes[i][j],(j==size-1) ? "\n" : " ");
        }
    }*/
    
	return 0;
}

int **multMatrices(int **&matriz1, int **&matriz2, int **&resultado){
	int res = 0;
        #pragma omp parallel
        {
	for(int col = 0;col<size;col++){
        #pragma omp for
        for(int i = 0;i<size;i++){
          res = 0;
          for(int x =0; x<size;x++){
            res += matriz1[i][x] * matriz2[x][col];
          }
          resultado[i][col] = res;
        }
        }
    }
    return resultado;
}
