#include <stdio.h>
#include "constante.h"

typedef struct estudiante{

    int sandwich;

}Estudiante;

typedef struct cola{
    Estudiante datos [MAX+1];
    int inicio;
    int fin;

}Cola;

void inicializacion(Cola *c){
    c->inicio=0;
    c->fin=0;
}

int estaVacia (Cola cola){
    int r=0;
    if(cola.inicio==cola.fin)
        r=1;
    return r;
}

int estaLlena(Cola cola){
    if(cola.fin == cola.inicio-1 || (cola.inicio == 0 && cola.fin ==MAX))
        return 1;
    return 0;
}
int insertar(Cola *c, Estudiante valor){
    int r=0;

    if(estaLlena(*c)==0){ //Hay espacio para insertar
        c->datos[c->fin] = valor;//poner el valor dentro del arreglo en la pos fin
        c->fin++;//mover fin a la sig casilla libre, incremento el valor de fin

        if(c->fin == MAX+1)
            c->fin = 0;
        r=1;
    }
    return r;
}

int eliminar(Cola *c, Estudiante *v){
    int r=0;
    if (!estaVacia(*c)){
        *v= c->datos[c->inicio];

        c->inicio= (c->inicio+1)%(MAX+1);
        r=1;
    }
    return r;
}
