#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

//No se puede usar [], ni *(p+i).
//Usar ++ -- p+i o p-i
//No se puede usar malloc o declarar un arreglo para pedir memoria adicional.
void eliminar(char *str, char *pat) {
    int len = strlen(pat);
    char *temp_1 = str;
    char *temp_2 = str;

    while (*temp_1) { //Mientras no se llegue al final del string.
        char *p1 = temp_1;
        char *p2 = pat;

        while (*p1 && *p2 && *p1 == *p2) { //Recorremos mientras p1,p2 no sean nulos, y los caracteres a comparar sean iguales.
            p1++;
            p2++;
        }
        if (!*p2) { //En este caso encontramos una aparicion completa de pat.
            temp_1 += len; //Nos saltamos la aparición (omitimos la aparición).
            continue;
        }
        *temp_2 = *temp_1; //vamos guardando el string resultante y seguimos revisando.
        temp_2++;
        temp_1++;

    }
    *temp_2 = '\0'; //Concluimos el string resultante.
}

//Usar aritmetica de punteros
//Usar malloc para pedir memoria
//Debe pedir la memoria exacta para el string resultante.
char *eliminados(char *str, char *pat) {
    int len = strlen(pat);
    char *temp_1 = str;
    int cnt = 0;

    while (*temp_1) { //Mientras no se llegue al final del string.
        char *p1 = temp_1;
        char *p2 = pat;

        while (*p1 && *p2 && *p1 == *p2) { //Recorremos mientras p1,p2 no sean nulos, y los caracteres a comparar sean iguales.
            p1++;
            p2++;
        }
        if (!*p2) { //En este caso encontramos una aparicion completa de pat.
            temp_1 += len; //Nos saltamos la aparición (omitimos la aparición).
            cnt ++;
            continue;
        }
        temp_1++;

    }
    int memoria_ped = strlen(str) - (cnt*len);
    char *final = malloc(memoria_ped + 1);
    char *temp_2 = final;

    temp_1 = str;

    while (*temp_1) { //Mientras no se llegue al final del string.
        char *p1 = temp_1;
        char *p2 = pat;

        while (*p1 && *p2 && *p1 == *p2) { //Recorremos mientras p1,p2 no sean nulos, y los caracteres a comparar sean iguales.
            p1++;
            p2++;
        }
        if (!*p2) { //En este caso encontramos una aparicion completa de pat.
            temp_1 += len; //Nos saltamos la aparición (omitimos la aparición).
            continue;
        }
        *temp_2 = *temp_1; //vamos guardando el string resultante y seguimos revisando.
        temp_2++;
        temp_1++;

    }
    *temp_2 = '\0'; //Concluimos el string resultante.
    return final;
}
