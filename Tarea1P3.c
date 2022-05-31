#include <stdio.h>
#include <string.h>
#include "pila.h"
#include "cola.h"

#define CIRCLE_SANDWICH 0
#define SQUARE_SANDWICH 1

void sell_sandwich(Cola *c, Stack *s);
int main(){

    Stack stack;
    Cola cola;
    Estudiante estudiante;


    inicializacion(&cola);
    setup(&stack);

    // SANDWICH
    push(&stack, CIRCLE_SANDWICH);
    push(&stack, SQUARE_SANDWICH);
    push(&stack, CIRCLE_SANDWICH);
    push(&stack, SQUARE_SANDWICH);

    //ESTUDIANTES


    estudiante.sandwich=CIRCLE_SANDWICH;
    insertar(&cola, estudiante);
    estudiante.sandwich=SQUARE_SANDWICH;
    insertar(&cola, estudiante);
    estudiante.sandwich=CIRCLE_SANDWICH;
    insertar(&cola, estudiante);
    estudiante.sandwich=SQUARE_SANDWICH;
    insertar(&cola, estudiante);


    sell_sandwich(&cola, &stack);


    return 0;
}
void sell_sandwich(Cola *c, Stack *s){
    Estudiante estudianteActual;
    int sandwichActual;

    while (!estaVacia(*c)) {

        eliminar(c, &estudianteActual);
        pop(s, &sandwichActual);

        printf("\n El estudiante  quiere sandwich: %d y en la pila hay: %d", estudianteActual.sandwich, sandwichActual);

        if (estudianteActual.sandwich!=sandwichActual) {
            printf("  No se pudo entregar, estudiante a cola, sandwich a pila");

        insertar(c, estudianteActual);
        push(s, sandwichActual);

        }
        else{
            printf("  El sandwich se entrego");
        }
    }
     printf("\n");
     if (estaVacia(*c)==1){


        printf("0");

    }

}
