#include "conjuntos.h"

int main()
{
    int start=0;
    int end =SET_CAPACITY;


    Set setA;
    Set setB;
    Set setC;

    init_set(&setA);
    add(&setA, 23);
    add(&setA, 16);
    add(&setA, 11);
    add(&setA, 7);
    add(&setA, 5);

    init_set(&setB);
    add(&setB, 10);
    add(&setB, 5);
    add(&setB, 11);
    add(&setB, 21);

    init_set(&setC);

    printSets(setA,setB);

    printf(" Interseccion:\n");
    intersect(setA, setB, &setC);
    printSet(setC);

    init_set(&setC);
    printf(" Union:\n");
    unionSet(setA, setB, &setC);
    printSet(setC);

    init_set(&setC);
    printf(" Complemento:\n");
    complementSet(setA, setB, &setC);
    printSet(setC);


    init_set(&setC);
    printf(" Diferencia :\n");
    diferenceSet(setA, setB, &setC);
    printSet(setC);


}
