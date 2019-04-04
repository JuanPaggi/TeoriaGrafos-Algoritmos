#ifndef ARBOLRECUBRIMIENTO_H
#define ARBOLRECUBRIMIENTO_H
#include "Grafo.h"
#include <iostream>

using namespace std;

class ArbolRecubrimiento
{
    public:
        ArbolRecubrimiento(Grafo &);
        ~ArbolRecubrimiento();
        void mostrarCosto();
        void mostrarDatos();
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

#endif // ARBOLRECUBRIMIENTO_H
