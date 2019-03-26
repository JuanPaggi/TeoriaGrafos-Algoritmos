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
