void multMatrices(int **&matriz1, int **&matriz2, int **&resultado);
void multMatrices2(int **&matriz1, int **&matriz2, int **&resultado);

void multMatrices(int **&matriz1, int **&matriz2, int **&resultado){
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
