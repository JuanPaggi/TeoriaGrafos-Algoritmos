#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "Grafo.h"
#include "ConjuntoArcos.h"
#include "ColaPrioridad.h"
#include "UnionFind.h"

class Kruskal
{
    public:
        Kruskal();
        ~Kruskal();
        void arbolSolucion(Grafo &);
        ConjuntoArcos devolverArbol();
        void mostrarSolucion();

    private:
        ConjuntoArcos T;
};

#endif // KRUSKAL_H
