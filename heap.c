#include "heap.h"
/**
 * TODO: Implementati functia de creare MinHeap avand o capacitate data
 * @param  capacitate: capacitatea heap-ului
 * @retval - heap-ul creat
 */
MinHeap *create(int capacitate)
{
    MinHeap *h = (MinHeap *)malloc(sizeof(MinHeap));
    h->poz = (int *)malloc(sizeof(int) * capacitate);
    h->size = 0;
    for (int i = 0; i < capacitate; i++)
        h->poz[i] = -1;

    h->capacity = capacitate;

    h->arr = (HeapNode **)calloc(sizeof(HeapNode *), capacitate);

    return h;
}

/**
 * TODO: Implementati functia de creare HeapNode
 * @param  v:  varful care trebuie adaugat
 * @param dist: distanta rezultata in urma implementarii algoritmului Dijkstra
 * @retval - HeapNode-ul creat
 */
HeapNode *createHeapNode(int v, int dist)
{
    HeapNode *ret;
    ret = (HeapNode *)malloc(sizeof(HeapNode));
    ret->v = v;
    ret->distanta = dist;
    return ret;
}

/**
 * TODO: Implementati functia de returnare a index-ului
 * parintelui unui nod din MinHeap
 * @param  heap: MinHeap-ul
 * @param  i: index-ul copilului
 * @retval - parintele copilului i
 */

int parent(MinHeap *heap, int i)
{
    if (i > heap->size - 1 || i <= 0)
        return -1;
    return (i - 1) / 2;
}
/**
 * TODO:  Implementati functia de returnare a index-ului
 * copilului stang al unui nod
 * @param  heap: MinHeap-ul
 * @param  i: parintele i
 * @retval - copilul din stanga al parintelui i
 */

int leftChild(MinHeap *heap, int i)
{

    int poz = 2 * i + 1;
    if (poz > heap->size - 1 || i < 0)
        return -1;
    return poz;
}

/**
 * TODO:  Implementati functia de returnare a index-ului
 * copilului drept al unui nod
 * @param  heap: MinHeap-ul
 * @param  i: parintele i
 * @retval - copilul din dreapta al parintelui i
 */
int rightChild(MinHeap *heap, int i)
{
    int poz = 2 * i + 2;
    if (poz > heap->size - 1 || i < 0)
        return -1;
    return poz;
}

/**
 * TODO: Implementati functia de returnare a radacinii
 * unui heap
 * @param  heap: MinHeap-ul
 * @retval - HeapNode-ul in care este stocata radacina
 */
HeapNode *returnRoot(MinHeap *heap)
{
    return heap->arr[0];
}

void swap(HeapNode **a, HeapNode **b)
{
    HeapNode *aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
/**
 * TODO: Implementati functia heapify
 * @param  heap: MinHeap-ul
 * @param  i: pozitia de pe care se doreste
 * @retval None
 */
void heapify(MinHeap *heap, int i)
{   int min, l, r;
    min = i;
    l = leftChild(heap, i);
    r = rightChild(heap, i);

    if (l != -1 && heap->arr[l]->distanta < heap->arr[min]->distanta)
        min = l;

    if (r != -1 && heap->arr[r]->distanta < heap->arr[min]->distanta)
        min = r;

    if (min != i)
    {
        HeapNode *minNode, *xNode;
        minNode = heap->arr[min];
        xNode = heap->arr[i];
        heap->poz[minNode->v] = i;
        heap->poz[xNode->v] = min;
        swap(&heap->arr[i],&heap->arr[min]);
        heapify(heap, min);
    }
}
/**
 * TODO: Implementati functia de redimensionare a MinHeap-ului
 * @param  heap: MinHeap-ul
 * @retval None
 */
void resize(MinHeap *heap)
{
    heap->poz = (int *)realloc(heap->poz, heap->capacity * 2);
    for (int i = heap->size; i < heap->capacity; i++)
    {
        heap->poz[i] = -1;
    }
    heap->arr = (HeapNode **)realloc(heap->arr, heap->capacity * 2);
    heap->capacity *= 2;
}
/**
 * TODO: Implementati functia de inserare a unui nod in heap
 * @param  heap: MinHeap-ul
 * @param  x: HeapNode-ul care urmeaza a fi inserat
 * @retval None
 */

void insert(MinHeap *heap, HeapNode *x)
{

    if (heap->size == heap->capacity)
        resize(heap);

    if (heap->poz[x->v] == -1)
    {
        int i = heap->size;
        heap->size++;

        while (i > 0 && x->distanta < (heap->arr[parent(heap, i)])->distanta)
        {
            heap->arr[i] = heap->arr[parent(heap, i)];
            heap->poz[heap->arr[parent(heap, i)]->v] = i;
            i = parent(heap, i);
        }
        heap->arr[i] = x;
        heap->poz[heap->arr[i]->v] = i;
    }
    else
    {
        int i = heap->poz[x->v];
        while (i > 0 && x->distanta < (heap->arr[parent(heap, i)])->distanta)
        {
            heap->arr[i] = heap->arr[parent(heap, i)];
            heap->poz[heap->arr[parent(heap, i)]->v] = i;
            i = parent(heap, i);
        }

        heap->arr[i] = x;
        heap->poz[heap->arr[i]->v] = i;
    }
}

/**
 * TODO: Implementati functia stergere a unui heap
 * @param  h: MinHeap-ul
 * @retval None
 */
void deleteMinHeap(MinHeap **heap)
{
    free((*heap)->arr);
    free((*heap)->poz);
    free(heap);
}
/**
 * TODO: Implementati functia de afisare a unui heap
 * @param  heap: MinHeap-ul
 * @note : se va afisa si pozitia HeapNode-urilor, pe langa componentele HeapNode-ului
 * @retval None
 */
void printHeap(MinHeap *heap)
{
    //nice to have
}
/**
 * TODO: Implementati functia de stergere a radacinii
 * @param  heap: MinHeap-ul
 * @retval HeapNode-ul care s-a sters, fosta radacina
 */
HeapNode *deleteNode(MinHeap *heap)
{
    HeapNode *root, *lastNode;

    root = heap->arr[0];
    lastNode = heap->arr[heap->size - 1];
    heap->arr[0] = lastNode;
    heap->poz[root->v] = -1;
    heap->poz[lastNode->v] = 0;
    heap->size--;
    heapify(heap, 0);

    return root;
}