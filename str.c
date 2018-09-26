#include <stdio.h>
int strleng(char *cadena);
void strcopy(char *a, char *b);

int main(){
  char *cadena = "hola";
  printf("%s -> %d\n",cadena, strleng(cadena));
  char *cadena2;
  strcopy(cadena2,cadena);
  printf("Cadena nueva: %s\n",cadena2);
  return 0;
}
int strleng(char *cadena){
  int len =0;
  while(*cadena != '\0'){
    cadena++;
    len++;
  }
  return len;
}
void strcopy(char *a, char *b){
  while((*a++ = *b++) != '\0')
    ;
}
