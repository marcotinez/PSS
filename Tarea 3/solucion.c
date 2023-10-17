#include <stddef.h>
#include "prev.h"

//Los nodos son de la forma struct nodo *izq, *der, *prev, *prox;
void asignarPrev(Nodo *t, Nodo **pprev) {
    Nodo *p = *pprev;

    if (t == NULL) {
        // Caso donde estamos en el ultimo nodo
        if (p != NULL) {
            p->prox = NULL;
        }
        return;
    }

    // por el orden visitamos el subarbol izq
    asignarPrev(t->izq, &p);

    // asignamos el nodo previo
    t->prev = p;

    // Si el nodo previo existe, asignamos el nodo actual como próximo del nodo previo
    if (p != NULL) {
        p->prox = t;
    }

    // Actualizamos el nodo previo
    p = t;

    // Ahora visitamos el subarbol derecho
    asignarPrev(t->der, &p);

    *pprev = p;
}




