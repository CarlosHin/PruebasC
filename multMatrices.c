#include <stdio.h>
#include <stdlib.h>

int main(){
  int filas1,filas2,col1,col2;
  printf("Filas matriz 1:");
  scanf("%d",&filas1);
  printf("Columnas matriz 1: ");
  scanf("%d",&col1);
  printf("Filas matriz 2: ");
  scanf("%d",&filas2);
  printf("Columnas matriz 2: ");
  scanf("%d",&col2);
  printf("\nMatriz 1: %dx%d\n", filas1,col1);
  printf("\nMatriz 2: %dx%d\n", filas2,col2);
  if(col1 != filas2){
    printf("Las columnas de la matriz 1 no coinciden con las filas de la 2\n");

  }else{
    int matriz1[filas1][col1];
    int matriz2[filas2][col2];
    printf("Matriz 1: \n");
    for(int i= 0;i<filas1;i++){
        for(int j=0;j<col1;j++){
            printf("%d x %d:", i,j);
            scanf("%d",&matriz1[i][j]);

        }
    }
    printf("Matriz 2: \n");
    for(int i= 0;i<filas2;i++){
        for(int j=0;j<col2;j++){
            printf("%d x %d:", i,j);
            scanf("%d",&matriz2[i][j]);

        }
    }


    printf("\n");
    for(int i= 0;i<filas1;i++){
        for(int j=0;j<col1;j++){
            printf("%4d %s",matriz1[i][j],(j==col1-1) ? "\n" : " ");
        }
    }
    printf("X  \n");
    for(int i= 0;i<filas2;i++){
        for(int j=0;j<col2;j++){
            printf("%4d %s",matriz2[i][j],(j==col2-1) ? "\n" : " ");
        }
    }
    int matrizResultado[filas1][col2];
    for(int col = 0;col<col2;col++){
        for(int i = 0;i<filas1;i++){
          int res = 0;
          for(int x =0; x<col1;x++){
            res += matriz1[i][x] * matriz2[x][col];
          }
          matrizResultado[i][col] = res;

        }
    }

    printf("\n");
    for(int i= 0;i<filas2;i++){
        for(int j=0;j<col2;j++){
            printf("%4d %s",matrizResultado[i][j],(j==col2-1) ? "\n" : " ");
        }
    }

  }
  return 0;
}
