#ifndef PRIM_H
#define PRIM_H
#include "Grafo.h"


class Prim
{
    public:
        Prim(Grafo &);
        ~Prim();
        void mostrarCosto();
        void prim();

    private:

        int n;
        int ** costo;
        int * menor_costo, *mas_cercano, *solucion;
        list<int> vertices;

        int menorCosto()
        {
            int aux = INT_MAX;
            int aux2;
            for(int i = 2; i <= n; i++)
            {
                if(aux > menor_costo[i] && solucion[i] == 0)
                {
                    aux = menor_costo[i];
                    aux2 = i;
                }
            }
            return aux2;
        }
};

#endif // PRIM_H
