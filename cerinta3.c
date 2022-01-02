#include "graph.h"
#include "heap.h"
/**
 * TODO:   Implementati algoritmul Floyd-Warshall pentru un graf cu matricea de adiacenta data
 * @param  g: graful dat
 * @retval - Matricea costurilor pentru toate nodurile
 */
int **Floyd_Warshall(Graph *g)
{
    int **ret;
    int i, j;
    ret = (int **)calloc(sizeof(int *), g->V);
    for (i = 0; i < g->V; i++)
    {
     ret[i] = (int *)calloc(sizeof(int), g->V);
    }
    for (i = 0; i < g->V; i++)
    {
        for (j = 0; j < g->V; j++)
        {
            if (g->mat[i][j] == 0)
            {
                ret[i][j] = INF_MAX;
            }
            else
                ret[i][j] = g->mat[i][j];
        }
    }
    for (int k = 0; k < g->V; k++)
    {

        for (i = 0; i < g->V; i++)
        {

            for (j = 0; j < g->V; j++)
            {

                if (ret[i][k] + ret[k][j] > 0)
                    if (ret[i][k] + ret[k][j] < ret[i][j])
                        ret[i][j] = ret[i][k] + ret[k][j];
            }
        }
    }

    return ret;
}