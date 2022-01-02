#include "graph.h"
#include "heap.h"
#include "utils.h"
void AUX(MinHeap *minHeap, int v, int dist)
{
    int i = minHeap->poz[v];
    minHeap->arr[i]->distanta = dist;

    while (i != -1 && minHeap->arr[i]->distanta < minHeap->arr[parent(minHeap, i)]->distanta)
    {

        minHeap->poz[minHeap->arr[i]->v] = parent(minHeap, i);
        minHeap->poz[minHeap->arr[parent(minHeap, i)]->v] = i;
      //  swap(&minHeap->arr[i], &minHeap->arr[parent(minHeap, i)]);

        i = parent(minHeap, i);
    }
}

/**
 * TODO:   Implementati Algoritmul Dijkstra folosindu-va de MinHeap-ul creat in fisierul heap.c
 * @param  g: graful dat
 * @param source : varful sursa pentru care se aplica algoritmul
 * @retval None
 */

DijkstraPath *Dijkstra(Graph *g, int source)
{
    DijkstraPath *ret;
    ret = (DijkstraPath *)malloc(sizeof(DijkstraPath));
    int V = g->V;
    int *dist;
    dist = (int *)malloc(sizeof(int) * g->V);
    MinHeap *minHeap;
    minHeap = create(V);
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF_MAX;
        minHeap->arr[i] = createHeapNode(i, dist[i]);
        minHeap->poz[i] = i;
    }
    minHeap->arr[source] = createHeapNode(source, dist[source]);
    minHeap->poz[source] = source;
    dist[source] = 0;
    AUX(minHeap,source,dist[source]);
     minHeap->size=V;
     while(minHeap->size > 0){
         HeapNode* n;
         n=deleteNode(minHeap);
         //de aici nu mai stiu =(((
     }

}

/**
 * TODO:   Implementati Algoritmul Dijkstra folosindu-va de MinHeap-ul creat in fisierul heap.c
 * @param vectorPath : vectorul cailor
 * @param index : [optional pentru recursivitate]
 * @param vector_precedesori : vectorul de predecesori 
 * @param destinatie : varful destinatie pentru care se cauta path-ul
 * @param output : fisierul in care se face scrierea vectorului de predecesori (path.txt)
 * @note : se poate implementa atat recursiv, cat si iterativ
 *         nu mai trebuie facute alocari pentru vectorPath, vector_predecesori
 *         fisierul de output este deschis 
 * @retval None
 */
void printPath(int *vectorPath, int index, int *vector_precedesori, int destinatie, FILE *output)
{
}
