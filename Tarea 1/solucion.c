//Autor: Marco Martínez

#include <stdio.h>
#include "suma.h"

Bcd sumaBcd(Bcd x, Bcd y) {
  Bcd suma = 0;
  Bcd carry = 0;
  Bcd resultado = 0;

  for(int i=0 ; i < 64; i+=4) {
    //mascara que va dejando 4 bits de 1.
    Bcd mask = 0xF;

    //apagamos todos los bits menos los que vamos a sumar.
    Bcd temp_bcd1 = (x>>i) & mask;
    Bcd temp_bcd2 = (y>>i) & mask;

    //suma de 4 bits.
    suma = temp_bcd1 + temp_bcd2 + carry;

    //cuando la suma de bits es mayor a 9, caso especial.
    if(suma > 9) {
      carry = 1; //este carry se debe usar en la siguiente suma.
      suma -= 10; //guardamos solo la segunda cifra de la suma.
    }
    else {
      carry = 0;
    }

    //añademos los bits a su posicion correspondiente.
    resultado |= (suma << i);
    }

    if(carry){
      return 0xffffffffffffffff;
    }
    else
      return resultado;

  }
