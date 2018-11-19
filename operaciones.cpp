#include <stdio.h>
#include <stdlib.h>
#include <ctime>


int main(int argc, char *argv[]){
  if(argc != 2){
    printf("NOPP\n" );
  }else{
    int n= atoi(argv[1]);
    int op1 = 13;
    int op2 = 14;
    int op3 = 12;
    time_t start = time(0);

    for(int i = 0;i<n*n;i++){
      for(int j =0; j<n;j++){
        op3 = op1*op2;
        op3 = op1+op2;
      }
    }
    double seconds_since_start = difftime( time(0), start);
    printf("Segundos: %f\n", seconds_since_start);
  }

  return 0;
}
