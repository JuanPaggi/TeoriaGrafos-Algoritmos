#ifndef RECORRIDOS_H
#define RECORRIDOS_H

#include "Grafo.h"


class Recorridos
{
public:
    Recorridos();
    ~Recorridos();

    void bosque_DFS(Grafo &);
    void devolverDatos_dfs(int * &, int * &, int * &);
    void mostrarDatos_dfs();

    void bosque_BFS(Grafo &);
    void devolverDatos_bfs(int * &, int * &e);
    void mostrarDatos_bfs();

    void clasificarArcos(Grafo &);

private:
    int time;
    list<int> vertices;

    int * estado, * descubierto, * padre, * fin, * distancia;

    void inicializar(Grafo & g)
    {
        time = 0;
        int n = g.size();
        estado = new int[n];
        descubierto = new int[n];
        padre = new int[n];
        fin = new int[n];
        distancia = new int[n];
        vertices = g.devolverVertices();
        for(int i = 0; i < n; i++)
        {
            estado[i] = NO_VISITADO;
            padre[i] = -1;
            distancia[i] = -1;
        }
    }

    void dfs(Grafo & g, int u)
    {
        estado[u] = DESCUBIERTO;
        descubierto[u] = ++time;
        list<Grafo::Arco> adyacentes = g.devolverAdyacentes(u);
        for(list<Grafo::Arco>::iterator it = adyacentes.begin(); it != adyacentes.end(); it++)
        {
            int v = it->devolverAdyacente();
            if(estado[v] == NO_VISITADO)
            {
                padre[v] = u;
                dfs(g, v);
            }
        }
        estado[u] = VISITADO;
        fin[u] = ++time;
    }

    void bfs(Grafo & g, int s)
    {
        estado[s] = VISITADO;
        distancia[s] = 0;
        list<int> cola;
        cola.push_front(s);
        while(!cola.empty())
        {
            int u = cola.front();
            cola.pop_front();
            list<Grafo::Arco> adyacentes = g.devolverAdyacentes(u);
            for(list<Grafo::Arco>::iterator it = adyacentes.begin(); it != adyacentes.end(); it++)
            {
                int v = it-> devolverAdyacente();
                if(estado[v] == NO_VISITADO)
                {
                    estado[v] = VISITADO;
                    distancia[v] = distancia[u] + 1;
                    padre[v] = u;
                    cola.push_front(v);
                }
            }
        }
    }

    void clasificarArcos_dfs(Grafo & g, int u)
    {
        estado[u] = DESCUBIERTO;
        descubierto[u] = ++time;
        list<Grafo::Arco> adyacentes = g.devolverAdyacentes(u);
        for(list<Grafo::Arco>::iterator it = adyacentes.begin(); it != adyacentes.end(); it++)
        {
            int v = it->devolverAdyacente();
            if(estado[v] == NO_VISITADO)
            {
                cout << u << "->" << v << " Arbol"<<endl;
                clasificarArcos_dfs(g, v);
            }
            else
                if(estado[v] == DESCUBIERTO)
                {
                    cout << u << "->" << v << " Retroceso"<<endl;
                }
                else
                    if(estado[v] == VISITADO)
                    {
                        if(descubierto[u] < descubierto[v])
                        {
                            cout << u << "->" << v << " Avance"<<endl;
                        }
                        if(descubierto[u] > descubierto[v])
                        {
                            cout << u << "->" << v << " Cruce"<<endl;
                        }
                    }
        }
        estado[u] = VISITADO;
    }
};



#endif // RECORRIDOS_H
