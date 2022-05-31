#include <stdio.h>

#define SET_CAPACITY 10

typedef struct
{
    int data[SET_CAPACITY];
    int size;
} Set;

void init_set(Set *s);
int add(Set *s, int value);
void printSets(Set setA,Set setB);
int find(Set s, int value);
int removeSet(Set *s, int value);
int removefirst(Set *s, int value);
int removelast(Set *s, int value);
int exist(Set set, int value);

void intersect(Set setA, Set setB, Set *setC);
void printSet(Set set);
void unionSet(Set setA, Set setB, Set *setC);
void complementSet(Set setA, Set setB, Set *setC);
void diferenceSet(Set setA, Set setB, Set *setC);

void init_set(Set *s)
{
    s->size = 0;
}

int add(Set *s, int value)
{
     int exists = 0;
     if(s->size < SET_CAPACITY && find(*s, value) == -1)
     {
        int index;
        for(index = s->size - 1 ; index >= 0 && s->data[index] > value ; index--)
            s->data[index + 1] = s->data[index];

        s->data[index + 1] = value;
        s->size++;
        return 1;
     }
     return 0;
}
void printSets(Set setA,Set setB){

    printf("Set A:\n");
    printSet(setA);
    printf("\n");
    printf("Set B:\n");
    printSet(setB);
    printf("\n");

}
int removeSet(Set *s, int value)
{
    int index = find(*s, value);
    if(index != -1)
    {
        s->size--;
        for( ; index < s->size ; index++)
            s->data[index] = s->data[index + 1];
        return 1;
    }
    return 0;
}
int removefirst(Set *set, int value){

 int index= find(*s, value);

    if (index==0){
        s->size--;
        for (; index <= s->size-1 ; ++index) {
            s->data[index]=s->data[index+1];
        }
        return 1;
    }
    return -1;



}

int find(Set set, int value)
{
    int left = 0;
    int right = set.size - 1;
    while(left <= right)
    {
        int half = (left + right) / 2;
        if(value == set.data[half])
            return half;

        if(value < set.data[half])
            right = half - 1;
        else
            left = half + 1;
    }
    return -1;
}

int exist(Set set, int value)
{
    if(find(set, value) == -1)
        return 0;
    return 1;
}

void intersect(Set setA, Set setB, Set *setC)
{
    for(int i = 0 ; i < setA.size ; i++)
        if(exist(setB, setA.data[i]))
            add(setC, setA.data[i]);
}

void printSet(Set set)
{
    printf("[ ");
    for(int i = 0 ; i < set.size ; i++)
        printf("%d ", set.data[i]);
    printf("]\n");
}

void unionSet(Set setA, Set setB, Set *setC)
{
    for(int i = 0 ; i < setA.size ; i++)
        add(setC, setA.data[i]);

    for(int i = 0 ; i < setB.size ; i++)
        if(!exist(*setC, setB.data[i]))
            add(setC, setB.data[i]);
}

void complementSet(Set setA, Set setB, Set *setC)
{
 int r;
    for (int index = 0; index < setA.size; index++) {

        r= exist(setA, setB.data[index]);
        if (r!=1)
        {

            add(setC, setA.data[index]);
        }
    }
}


void diferenceSet(Set setA, Set setB, Set *setC)
{
    for(int i = 0 ; i < setA.size ; i++)
        if(!exist(setB, setA.data[i]))
            add(setC, setA.data[i]);
}
