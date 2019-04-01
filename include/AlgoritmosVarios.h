#ifndef ALGORITMOSVARIOS_H
#define ALGORITMOSVARIOS_H

#include "Grafo.h"
#include "Recorridos.h"

class AlgoritmosVarios
{
    public:
        AlgoritmosVarios();
        ~AlgoritmosVarios();

        void longitudCaminos(Grafo &, int);
        void mostrarLongitudes();

        void bosque_topSort(Grafo &);
        void mostrarOrdenamiento();

        bool hayCiclo(Grafo &);

        void caminosMinimos_Vertice(Grafo &, int);

        void todosLosCaminos(Grafo &, int, int);

        void camino_sinPasarPorRojo(Grafo &, int, int, list<int>);

    private:
        int * estado, * descubierto, *padre, *distancia;
        list<int> vertices, aux;
        int time, n;
        bool * visitados;
        bool corte;

        void inicializar(Grafo & g)
        {
            vertices.clear();
            n = g.size();
            time = 0;
            estado = new int[n+1];
            descubierto = new int [n+1];
            for(int i = 1; i <= n; i++)
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
            list<Arco> adyacentes = g.devolverAdyacentes(u);
            for(list<Arco>::iterator it = adyacentes.begin(); it != adyacentes.end(); it++)
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

        void topSort(Grafo & g, int u)
        {
            visitados[u] = true;
            list<Arco> adyacentes = g.devolverAdyacentes(u);
            for(list<Arco>::iterator it = adyacentes.begin(); it != adyacentes.end(); it++)
            {
                int v = it->devolverAdyacente();
                if(!visitados[v])
                {
                    topSort(g, v);
                }

            }
            vertices.push_front(u);
        }

        void todosLosCaminos_dfs(Grafo & g, int origen, int destino)
        {
            if(origen == destino)
            {
                aux.push_back(destino);
                for(list<int>::iterator it = aux.begin(); it != aux.end(); it++)
                {
                    cout << " " << *it ;
                }
                cout << endl;
                aux.pop_back();
            }
            else
            {
                estado[origen] = VISITADO;
                aux.push_back(origen);
                list<Arco> adyacentes = g.devolverAdyacentes(origen);
                for(list<Arco>::iterator it = adyacentes.begin(); it != adyacentes.end(); it++)
                {
                    int v = it->devolverAdyacente();
                    if(estado[v] == NO_VISITADO)
                    {
                        todosLosCaminos_dfs(g, v, destino);
                    }
                }
                estado[origen] = NO_VISITADO;
                aux.pop_back();
            }
        }

        void camino_sinPasarPorRojo_dfs(Grafo & g, int origen, int destino, list<int> rojo)
        {
            if(origen == destino)
            {
                aux.push_back(destino);
                for(list<int>::iterator it = aux.begin(); it != aux.end(); it++)
                {
                    cout << " " << *it ;
                }
                cout << endl;
                corte = true;
            }
            else
            {
                if(!corte)
                {
                    estado[origen] = VISITADO;
                    aux.push_back(origen);
                    list<Arco> adyacentes = g.devolverAdyacentes(origen);
                    for(list<Arco>::iterator it = adyacentes.begin(); it != adyacentes.end(); it++)
                    {
                        int v = it->devolverAdyacente();
                        if((!esRojo(rojo, v)) && (estado[v] == NO_VISITADO))
                        {
                            camino_sinPasarPorRojo_dfs(g, v, destino, rojo);
                        }
                    }
                    estado[origen] = NO_VISITADO;
                    aux.pop_back();
                }
            }
        }

        bool esRojo(list<int> rojo, int v)
        {
            list<int>::iterator it = rojo.begin();
            while(it != rojo.end() && *it != v)
            {
                it++;
            }
            if(it == rojo.end())
            {
                return false;
            }
            else
            {
                return true;
            }
        }
};

#endif // ALGORITMOSVARIOS_H
