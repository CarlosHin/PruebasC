#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <omp.h>

int size =2000;
void multMatricesPar(int **&matriz1, int **&matriz2, int **&resultado);
void multMatricesSec(int **&matriz1, int **&matriz2, int **&resultado);

int main(int argc, char *argv[]){
    int imprimir = 0;
    int paralelo = 1;
    if(argc > 4){
      printf("Argumentos introducidos no validos\n" );
      printf("Formato:\n" );
      printf("programa [size][parelo/secuencial][imprimir resultado/no imprimir]\n" );


    }else{
      if(argc ==4){
        size = atoi( argv[1] );
        paralelo = atoi(argv[2]);
        imprimir = atoi(argv[3]);

      }else if(argc == 3){
        size = atoi( argv[1] );
        paralelo = atoi(argv[2]);



      }else if(argc == 2){
        size = atoi( argv[1] );

      }
      printf("Matrices de tamaño %d, %s\n",size , (paralelo) ? "Paralelo" : "Secuencial" );

      printf("%d\n", size);
      srand((unsigned)time(0));


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
              mat1[i][j] = 1;
              mat2[i][j] = 1;

          }
      }

      if(paralelo)
        multMatricesPar(mat1,mat2, matRes);
      else
        multMatricesSec(mat1,mat2, matRes);
      if(imprimir){
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
      }
    }
  }
	return 0;
}


void multMatricesPar(int **&matriz1, int **&matriz2, int **&resultado){
	int res = 0;
  int **matAux = (int **)malloc (size*sizeof(int *));
  for(int i = 0; i< size;i++){
      matAux[i] = (int *)malloc(size*sizeof(int));
  }
  for(int i= 0;i<size;i++){
      for(int j=0;j<size;j++){
          matAux[i][j] = matriz2[j][i];

      }
  }
  #pragma omp parallel num_threads(4)
    {
        #pragma omp for
	      for(int i = 0;i<size;i++){
          for(int j = 0;j<size;j++){
            for(int x =0; x<size;x++){
            resultado[i][j] += matriz1[i][x] * matAux[i][x];
            }

          }
        }
    }
}

void multMatricesSec(int **&matriz1, int **&matriz2, int **&resultado){
	int res = 0;
  int **matAux = (int **)malloc (size*sizeof(int *));
  for(int i = 0; i< size;i++){
      matAux[i] = (int *)malloc(size*sizeof(int));
  }
  for(int i= 0;i<size;i++){
      for(int j=0;j<size;j++){
          matAux[i][j] = matriz2[j][i];

      }
  }

	for(int i = 0;i<size;i++){

        for(int j = 0;j<size;j++){
          for(int x =0; x<size;x++){
            resultado[i][j] += matriz1[i][x] * matAux[i][x];
          }

        }
    }

}
