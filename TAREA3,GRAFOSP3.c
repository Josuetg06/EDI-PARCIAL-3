#include <stdio.h>
#include <string.h>
#include "cola.h"
#define GRAPH_CAPACITY 32
typedef struct graph{
    int edges[GRAPH_CAPACITY][GRAPH_CAPACITY];
    char vertices[GRAPH_CAPACITY][20];
    int flag[GRAPH_CAPACITY];
    int size;
}Graph;
int initGraph(Graph *g);
int AddVertice(Graph *g, char vertice[20]);
int AddEdge(Graph *g,char VerticeSource[20], char VerticeDestinity[20]);
int findVertice(Graph graph, char vertice[20]);
void FillGraph(Graph *g);
int IsFull (Graph g);
int RelationshipExists(Graph *graph, char verticeSource[20], char verticeDestinity[20]);
int removeEdge(Graph *g, char *v1, char *v2);
int removeVertice (Graph *g, char *vertice);
void printGraph(Graph graph);
void resetFlags(Graph *g);
void BFS(Graph *graph, char vertice[50]);

int main (){
    Graph graph;
    int relacion;
    initGraph(&graph);

    FillGraph(&graph);
    printGraph(graph);
    printf("\n");

    printf("Eliminar arista SLP - TAM:\n");
    removeEdge(&graph, "SLP", "TAM");
    printGraph(graph);

    printf("\n");
    printf("BFS:\n");
    BFS(&graph, "SLP");
    printf("\n");

    printf("Eliminar vertice NL:\n");
    removeVertice(&graph, "NL");
    printGraph(graph);

}
int initGraph(Graph *g){
    g->size=0;
    resetFlags(g);

}
void FillGraph(Graph *g){
    AddVertice(g, "SLP");
    AddVertice(g, "QRO");
    AddVertice(g, "TAM");
    AddVertice(g, "NL");
    AddVertice(g, "GDL");
    AddVertice(g, "TIJ");

    AddEdge(g, "SLP", "QRO");
    AddEdge(g, "SLP", "NL");
    AddEdge(g, "SLP", "GDL");
    AddEdge(g, "QRO", "TAM");
    AddEdge(g, "QRO", "GDL");
    AddEdge(g, "QRO", "TIJ");
    AddEdge(g, "NL", "TAM");

}


int removeEdge(Graph *g, char verticeSource[20], char VerticeDestinity [20])
{
    int posVerticeSource = findVertice(*g, verticeSource);
    int posVerticeDestinity = findVertice(*g, VerticeDestinity );
        if (g->edges[posVerticeSource][posVerticeSource] == 1) {
            g->edges[posVerticeSource][posVerticeDestinity] == 0;
            return 1;
        }else{
            return 0;
        }
    }

int removeVertice(Graph *g, char *vertice)
{
    {
    int VerticeIndex = findVertice(*g, vertice);
    if(VerticeIndex != -1)
    {
        --g->size;
        for(int i = VerticeIndex ; i < g->size ; i++)
            strcpy(g->vertices[i], g->vertices[i + 1]);

        for(int r = 0 ; r <= g->size ; r++)
            if(r >= VerticeIndex)
                for(int c = 0 ; c <= g->size ; c++)
                    g->edges[r][c] = g->edges[r+1][c];


        for(int r = 0 ; r <= g->size ; r++)
            for(int c = 0 ; c <= g->size ; c++)
                if(c >= VerticeIndex)
                    g->edges[r][c] = g->edges[r][c+1];

        return 1;
    }
    return 0;
}

}
int RelationshipExists (Graph *graph, char verticeSource[20], char  VerticeDestinity[20]) {
    int  posVerticeSource= findVertice(*graph, verticeSource);
    int posVerticeDestinity = findVertice(*graph, VerticeDestinity);
    for (int i = 0; i < graph->size; i++) {
        if (posVerticeSource != 1 && graph->edges[posVerticeSource][ posVerticeDestinity] == 1) {
            return 1;
        }else{
            return 0;
        }
    }
}

int findVertice(Graph graph, char vertice[20]){
    int i;
    int result= -1;

    for ( i = 0; i < graph.size && result == -1; i++) {
        if (strcmp(graph.vertices[i], vertice)==0)
            result = i;
    }
    return result;
}

int IsFull (Graph g){
    if (g.size==GRAPH_CAPACITY) {
        return -1;
    } else {
         return 0;
     }
}
int AddVertice(Graph *g, char vertice[20]) {
    if (g->size < GRAPH_CAPACITY) {
        if (findVertice(*g, vertice) == - 1 &&  (IsFull(*g)!= -1))
        strcpy(g->vertices[g->size], vertice);

        for (int r = 0; r < GRAPH_CAPACITY; r++) {
            g->edges[r][g->size] = 0;
        }

    for (int c = 0; c < GRAPH_CAPACITY; c++) {
        g->edges[g->size][c] = 0;
    }
        g->size++;

    }
    return 1;
}
int AddEdge(Graph *g,char VerticeSource[20], char VerticeDestinity[20]) {
    int posSource = findVertice(*g, VerticeSource);
    int posDestinity = findVertice(*g, VerticeDestinity);

    if (posSource !=-1 && posDestinity !=-1){
        g->edges[posSource][posDestinity]=1;
        g->edges[posDestinity][posSource]=1;
        return 1;
    }
    return -1;
}

void BFS(Graph *graph, char vertice[50]){
    Cola colavertice;
    int posVertice= findVertice(*graph, vertice);
    char verticeActual[50];
    inicializacion(&colavertice);

    graph->flag[posVertice]=1;
    insertar(&colavertice, vertice);
    while (!estaVacia(colavertice)){
       eliminar(&colavertice, verticeActual);
       posVertice= findVertice(*graph, verticeActual);
        printf("%s\t", verticeActual);

        for (int i = 0; i < graph->size; ++i) {
            if (posVertice!=1 && graph->edges[posVertice][i]==1 &&graph->flag[i]==0){
                graph->flag[i]=1;
                insertar(&colavertice, graph->vertices[i]);
            }

        }
    }
}
void resetFlags(Graph *g){
    for (int i = 0; i < GRAPH_CAPACITY; ++i) {
        g->flag[i]=0;
    }
}
void printGraph(Graph graph){
    printf("\t");
    for (int index = 0; index < graph.size; ++index) {
       printf("\t%s\t", graph.vertices[index]);
    }
    printf("\n");
    for (int r = 0; r < graph.size; r++) {
        printf("%s  ", graph.vertices[r]);

            for (int c = 0; c < graph.size; c++) {
                printf("\t\t%d", graph.edges[r][c]);

        }
        printf("\n");
    }

}
