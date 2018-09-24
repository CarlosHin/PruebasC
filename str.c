#include <stdio.h>
int strlen(char *cadena);
int main(){
  char *cadena = "hoa";
  printf("Hola -> %d", strlen(cadena));
  return 0;
}
int strlen(char *cadena){
  int len =0;
  while(*cadena != '\0' && len<1){
    cadena++;
    printf("ey %c\n", *cadena);
    len++;
  }
  return len;
}
