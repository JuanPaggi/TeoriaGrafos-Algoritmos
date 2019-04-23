#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Grafo.h"
#include <map>
#include <algorithm>

class Dijkstra
{
    public:
        Dijkstra(Grafo &);
        ~Dijkstra();
        void caminosMinimos(Grafo &, int);

    private:
        int *distancia, *padre;

        int extraer_min(int* distancia, list<int> vertices)
        {
            int minimo = INT_MAX;
            int w = 0;
            for (list<int>::iterator itV = vertices.begin(); itV != vertices.end(); itV++)
            {
                int v = *itV;
                if (distancia[v] < minimo)
                {
                    minimo = distancia[v];
                    w = v;
                }
            }
            return w;
        }
};

#endif // DIJKSTRA_H
