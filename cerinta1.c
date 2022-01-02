#include "graph.h"
#include "heap.h"
/**
 * TODO:   Implementati o functie care citeste dintr-un fisier de intrare
 * nr-ul de varfuri, muchii, iar pe urmatoarele linii
 * nod u, nod v si distanta[u][v], pentru a putea reprezenta ulterior matricea de adiacenta
 * @param  input: fisierul de intrare
 * @note   -Atentie! Nu redeschideti fisierul de intrare
 * @retval - Graful in reprezentarea matrice de adiacenta
 */
Graph *createGraph(FILE *input)
{
    Graph *ret;
    ret = (Graph *)calloc(sizeof(Graph),1);
    fscanf(input,"%d", &ret->V);
    fscanf(input,"%d", &ret->E);
    ret->mat = (int **)calloc(sizeof(int *), ret->V);
    for (int i = 0; i < ret->V; i++)
    {
        ret->mat[i] = (int *)calloc(sizeof(int), ret->V);
    }
  int u,v,dist;


      while (fscanf(input,"%d %d %d",&u,&v,&dist)!=EOF)
      if( dist>0){
          ret->mat[u][v]=dist;
          ret->mat[v][u]=dist;
      }

  return ret;

}
/**
 * TODO: Implementati functia de afisare a matricei de adiacenta
 * @param  g: graful creat anterior
 * @note : Nice to have
 * @retval - None
 */
void printMat(Graph *g)
{
}
