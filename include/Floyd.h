#ifndef FLOYD_H
#define FLOYD_H

#include "Grafo.h"

class Floyd
{
    public:
        Floyd(Grafo &);
        ~Floyd();
        void mostrarMatrizCostos();
        void caminosMinimos();
        void mostrarCaminos();

    private:
        int ** A;
        int ** C;
        int n;
};

#endif // FLOYD_H
