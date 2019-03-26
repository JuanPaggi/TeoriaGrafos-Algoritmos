#ifndef ALGORITMOSVARIOS_H
#define ALGORITMOSVARIOS_H

#include "Grafo.h"

class AlgoritmosVarios
{
    public:
        AlgoritmosVarios();
        ~AlgoritmosVarios();

        void longitudCaminos(Grafo & g, int u);
        void mostrarLongitudes();

    private:
        int * estado, * descubierto;
        list<int> vertices;
        int time, n;

        void inicializar(Grafo & g)
        {
            n = g.size();
            time = 0;
            estado = new int[n];
            descubierto = new int [n];
            for(int i = 0; i < n; i++)
            {
                estado[i] = NO_VISITADO;
                descubierto[i] = -1;
            }
        }

        void caminos_dfs(Grafo & g, int u)
        {
        estado[u] = DESCUBIERTO;
        descubierto[u] = time;
        time++;
        list<Grafo::Arco> adyacentes = g.devolverAdyacentes(u);
        for(list<Grafo::Arco>::iterator it = adyacentes.begin(); it != adyacentes.end(); it++)
        {
            int v = it->devolverAdyacente();
            if(estado[v] == NO_VISITADO)
            {
                caminos_dfs(g, v);
            }
        }
        estado[u] = VISITADO;
        --time;
        }
};

#endif // ALGORITMOSVARIOS_H
