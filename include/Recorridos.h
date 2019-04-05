#ifndef RECORRIDOS_H
#define RECORRIDOS_H

#include "Grafo.h"


class Recorridos
{
public:
    Recorridos();
    ~Recorridos();

    void bosque_DFS(Grafo &, int);
    void devolverDatos_dfs(int * &, int * &, int * &);
    void mostrarDatos_dfs();
    int * devolverPostOrden();

    void bosque_BFS(Grafo &, int);
    void devolverDatos_bfs(int * &, int * &e);
    void mostrarDatos_bfs();
    void bosque_BFS_unico(Grafo & g, int u);

    void clasificarArcos(Grafo &);

private:
    int time;
    list<int> vertices;

    int * estado, * descubierto, * padre, * fin, * distancia;

    void inicializar(Grafo & g)
    {
        time = 0;
        int n = g.size();
        estado = new int[n+1];
        descubierto = new int[n+1];
        padre = new int[n+1];
        fin = new int[n+1];
        distancia = new int[n+1];
        vertices = g.devolverVertices();
        for(int i = 1; i <= n; i++)
        {
            estado[i] = NO_VISITADO;
            padre[i] = -1;
            distancia[i] = 0;
        }
    }

    void dfs(Grafo & g, int u)
    {
        estado[u] = DESCUBIERTO;
        descubierto[u] = ++time;
        list<Arco> adyacentes = g.devolverAdyacentes(u);
        for(list<Arco>::iterator it = adyacentes.begin(); it != adyacentes.end(); it++)
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
        cola.push_back(s);
        while(!cola.empty())
        {
            int u = cola.front();
            cola.pop_front();
            list<Arco> adyacentes = g.devolverAdyacentes(u);
            for(list<Arco>::iterator it = adyacentes.begin(); it != adyacentes.end(); it++)
            {
                int v = it-> devolverAdyacente();
                if(estado[v] == NO_VISITADO)
                {
                    estado[v] = VISITADO;
                    distancia[v] = distancia[u] + 1;
                    padre[v] = u;
                    cola.push_back(v);
                }
            }
        }
    }

    void clasificarArcos_dfs(Grafo & g, int u)
    {
        estado[u] = DESCUBIERTO;
        descubierto[u] = ++time;
        list<Arco> adyacentes = g.devolverAdyacentes(u);
        for(list<Arco>::iterator it = adyacentes.begin(); it != adyacentes.end(); it++)
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
