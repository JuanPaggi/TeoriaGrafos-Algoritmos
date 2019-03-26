#include "Recorridos.h"

Recorridos::Recorridos()
{
    //ctor
}

Recorridos::~Recorridos()
{
    //dtor
}

void Recorridos::bosque_DFS(Grafo & g)
{
    inicializar(g);
    for(list<int>::iterator it = vertices.begin(); it != vertices.end(); it++)
    {
        int u = *it;
        if(estado[u] == NO_VISITADO)
        {
            dfs(g, u);
        }
    }
}

void Recorridos::devolverDatos_dfs(int *&descubierto, int * & fin, int * & padre)
{
    descubierto = this->descubierto;
    fin = this->fin;
    padre = this->padre;
}

void Recorridos::mostrarDatos_dfs()
{
    int n = vertices.size();
    for(int i = 0; i < n; i++)
    {
        cout << descubierto[i]<< " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        cout << fin[i]<< " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        cout << padre[i]<< " ";
    }
}

void Recorridos::bosque_BFS(Grafo & g)
{
    inicializar(g);
    bfs(g, 0);
}

void Recorridos::devolverDatos_bfs(int *&distancia, int * & padre)
{
    distancia = this->distancia;
    padre = this->padre;
}

void Recorridos::mostrarDatos_bfs()
{
    int n = vertices.size();
    for(int i = 0; i < n; i++)
    {
        cout << distancia[i]<< " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        cout << padre[i]<< " ";
    }
}

void Recorridos::clasificarArcos(Grafo & g)
{
    inicializar(g);
    for(list<int>::iterator it = vertices.begin(); it != vertices.end(); it++)
    {
        int u = *it;
        if(estado[u] == NO_VISITADO)
        {
            clasificarArcos_dfs(g, u);
        }
    }
}

