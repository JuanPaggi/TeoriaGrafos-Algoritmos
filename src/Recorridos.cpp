#include "Recorridos.h"

Recorridos::Recorridos()
{
    //ctor
}

Recorridos::~Recorridos()
{
    //dtor
}

void Recorridos::bosque_DFS(Grafo & g, int u)
{
    inicializar(g);
    dfs(g, u);
    for(list<int>::iterator it = vertices.begin(); it != vertices.end(); it++)
    {
        int v = *it;
        if(estado[v] == NO_VISITADO)
        {
            dfs(g, v);
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
    cout <<"descubierto: ";
    for(int i = 1; i <= n; i++)
    {
        cout << descubierto[i]<< " ";
    }
    cout << endl;
    cout <<"fin: ";
    for(int i = 1; i <= n; i++)
    {
        cout << fin[i]<< " ";
    }
    cout << endl;
    cout <<"padre: ";
    for(int i = 1; i <= n; i++)
    {
        cout << padre[i]<< " ";
    }
}

int * Recorridos::devolverPostOrden()
{
    return fin;
}

void Recorridos::bosque_BFS(Grafo & g, int u)
{
    inicializar(g);
    bfs(g, u);
    for(list<int>::iterator it = vertices.begin(); it != vertices.end(); it++)
    {
        int v = *it;
        if(estado[v] == NO_VISITADO)
        {
            bfs(g, v);
        }
    }
}

void Recorridos::bosque_BFS_unico(Grafo & g, int u)
{
    inicializar(g);
    bfs(g, u);
}

void Recorridos::devolverDatos_bfs(int *&distancia, int * & padre)
{
    distancia = this->distancia;
    padre = this->padre;
}

void Recorridos::mostrarDatos_bfs()
{
    int n = vertices.size();
    cout <<"padre: ";
    for(int i = 1; i <= n; i++)
    {
        cout <<  padre[i]<< " ";
    }
    cout << endl;
    cout <<"distancia: ";
    for(int i = 1; i <= n; i++)
    {
        cout << distancia[i]<< " ";
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
