#include <stdio.h>

#define SetCapacity 10


typedef struct
{
    int data[SetCapacity];
    int size;
} Set;



void init_set(Set *s);
int add(Set *s, int value);


int find(Set s, int value,int start,int end);
int removeSet(Set *s, int value);
int exist(Set set, int value);

void intersect(Set setA, Set setB, Set *sC);
void printSet(Set set);
void unionSet(Set setA, Set setB, Set *sC);
void complementSet(Set setA, Set setB, Set *sC);
void diferenceSet(Set setA, Set setB, Set *sC);

void init_set(Set *s)
{
    s->size = 0;
}

int add(Set *s, int value)
{
     int exists = 0;
     if(s->size < SetCapacity && find(*s, value) == -1)
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

int RemoveSet(Set *s, int value)
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

int find(Set set, int value,int start,int end) //Busqueda binaria recursiva
{


   int half = start (end + start) / 2;
   if(fin<inicio)
   {
       for(int i=0;i<MAX;i++)
          if(set.data[half]>objetivo){

            return half;
          }
          else if(objetivo>set.data[half+1]){

            return SetCapacity;
          }

       }



   if (set.data[half]]==objetivo)
   {
       return half;
   }

  if(set.data[half] > objetivo ){

    return find(set, value, start, half - 1);

}

  else if(set.data[half] < objetivo){

    return find(set, value, half+ 1, end);

  }
  else

    return -1;
}





int exist(Set set, int value)
{
    if(find(set, value) == -1)
        return 0;
    return 1;
}

void intersect(Set setA, Set setB, Set *sC)
{
    for(int i = 0 ; i < setA.size ; i++)
        if(exist(setB, setA.data[i]))
            add(sC, setA.data[i]);
}

void printSet(Set set)
{
    printf("[ ");
    for(int i = 0 ; i < set.size ; i++)
        printf("%d ", set.data[i]);
    printf("]\n");
}

void unionSet(Set setA, Set setB, Set *sC)
{
    for(int i = 0 ; i < setA.size ; i++)
        add(sC, setA.data[i]);

    for(int i = 0 ; i < setB.size ; i++)
        if(!exist(*sC, setB.data[i]))
            add(sC, setB.data[i]);
}

void complementSet(Set setA, Set setB, Set *sC)
{
    for(int i = 0 ; i < setB.size ; i++)
        if(!exist(setA, setB.data[i]))
            add(sC, setB.data[i]);
}

void diferenceSet(Set setA, Set setB, Set *sC)
{
    for(int i = 0 ; i < setA.size ; i++)
        if(!exist(setB, setA.data[i]))
            add(sC, setA.data[i]);
}
