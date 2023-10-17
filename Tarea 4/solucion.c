#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "pss.h"

int main(int argc, char *argv[]) {
  //caso cuando se ingresa una cantidad de argumentos no valida.
  if(argc != 4){
      fprintf(stderr, "Uso: %s <diccionario> <llave> <definicion>\n", "./definir");
      return -1;
    }

  FILE *f = fopen(argv[1], "r+");
  //caso en que no se puede abrir el archivo.
  if(f == NULL){
    perror(argv[1]);
    return -1;
  }

  //calculamos el numero de lineas del archivo.
  int len_linea = 81;
  fseek(f,0,SEEK_END);
  long file_size = ftell(f);
  int num_lineas = file_size / len_linea;

  //calculamos la linea sobre la que escribir.
  int linea_anadir = hash_string(argv[2]) % num_lineas;

  //nos movemos a la linea
  fseek(f, 81 * linea_anadir, SEEK_SET);

  //empezamos a leer.
  char linea[81];
  fread(linea, 1, 81, f);
  //caso cuando la linea está vacia.
  if(linea[0] == ' '){
    fseek(f, 81 * linea_anadir, SEEK_SET);
    fprintf(f, "%s:%s", argv[2], argv[3]);
  }
  else {
    //revisamos si la palabra está en el diccionario (a partir de la linea
    //que entrega el hash).
    char key[81];
    int j = linea_anadir;
    while(j<num_lineas){
      fseek(f, 81 * j, SEEK_SET);
      fread(key, 1, strlen(argv[2]), f);
      key[strlen(argv[2])] = '\0';
      if(strcmp(key, argv[2])==0){
        fprintf(stderr, "La llave %s ya se encuentra en el diccionario\n", argv[2]);
        return -1;
      }
      j++;
    }
    //empezamos a buscar la siguiente linea vacia.
    fseek(f, 81 * (linea_anadir+1), SEEK_SET);
    int i = 0;
    while(i < num_lineas){
      //caso cuando nos pasamos de las lineas, empezamos en el inicio de nuevo.
      if(linea_anadir + i >= num_lineas){
        fseek(f, 0, SEEK_SET);
      }
      //empezamos a leer e intentar escribir la linea
      fread(linea, 1, 81, f);
      if(linea[0] == ' '){
        fseek(f, -81, SEEK_CUR);
        fprintf(f, "%s:%s", argv[2], argv[3]);
        break;
      }
      //caso cuando el diccionario está lleno
      if( i == num_lineas - 1){
        fprintf(stderr, "%s: el diccionario esta lleno\n", argv[1]);
        return -1;
      }
      //pasamos a la siguiente linea
      i++;
    }
  }

  //cerramos el archivo
  fclose(f);
}
