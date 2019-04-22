#include "Kruskal.h"

Kruskal::Kruskal()
{
    //ctor
}

Kruskal::~Kruskal()
{
    //dtor
}

void Kruskal::arbolSolucion(Grafo & g)
{
    ColaPrioridad aristas(g);
    UnionFind componentes(g.devolverVertices());

    while(!aristas.empty())
    {
        Arco a = aristas.front();
        aristas.pop_front();
        int u = a.devolverOrigen();
        int v = a.devolverAdyacente();
        int repU = componentes.find(u);
        int repV = componentes.find(v);
        if(repU != repV)
        {
            componentes.union_(repU, repV);
            T.agregar(a);
        }
    }
}

ConjuntoArcos Kruskal::devolverArbol()
{
    return T;
}

void Kruskal::mostrarSolucion()
{
    T.mostrarConjunto();
}

