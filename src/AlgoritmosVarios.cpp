#include "AlgoritmosVarios.h"

AlgoritmosVarios::AlgoritmosVarios()
{
    //ctor
}

AlgoritmosVarios::~AlgoritmosVarios()
{
    //dtor
}

void AlgoritmosVarios::longitudCaminos(Grafo & g, int u)
{
    inicializar(g);
    caminos_dfs(g, u);
}

void AlgoritmosVarios::mostrarLongitudes()
{
    for(int i=0; i < n; i++)
    {
        cout << i << " Distancia: " << descubierto[i] << endl;
    }
}

void AlgoritmosVarios::bosque_topSort(Grafo & g)
{
    int n = g.size();
    visitados = new bool[n];
    for(int i=0; i<n; i++)
    {
        visitados[i] = false;
    }
    for(int i=0; i<n; i++)
    {
        if(!visitados[i])
        {
            topSort(g, i);
        }
    }
}

void AlgoritmosVarios::mostrarOrdenamiento()
{
    for(list<int>::iterator it = topsort.begin(); it != topsort.end(); it++)
    {
        cout << *it << " -> ";
    }
}
