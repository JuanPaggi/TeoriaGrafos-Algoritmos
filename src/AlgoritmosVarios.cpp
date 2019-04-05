#include "AlgoritmosVarios.h"

AlgoritmosVarios::AlgoritmosVarios()
{
    //ctor
}

AlgoritmosVarios::~AlgoritmosVarios()
{
    //dtor
}

void AlgoritmosVarios::longitudCaminos(Grafo & g, int u)
{
    inicializar(g);
    caminos_dfs(g, u);
}

void AlgoritmosVarios::mostrarLongitudes()
{
    for(int i=1; i <= n; i++)
    {
        cout << i << " Distancia: " << descubierto[i] << endl;
    }
}

void AlgoritmosVarios::bosque_topSort(Grafo & g)
{
    vertices.clear();
    if(!hayCiclo(g))
    {
        int n = g.size();
        visitados = new bool[n];
        for(int i=0; i<n; i++)
        {
            visitados[i] = false;
        }
        for(int i=0; i<n; i++)
        {
            if(!visitados[i])
            {
                topSort(g, i);
            }
        }
    }
}

void AlgoritmosVarios::mostrarOrdenamiento()
{
    for(list<int>::iterator it = vertices.begin(); it != vertices.end(); it++)
    {
        cout << *it << " -> ";
    }
    cout << endl;
}

bool AlgoritmosVarios::hayCiclo(Grafo & g)
{
    bool hayciclo = false;
    Recorridos post;
    post.bosque_DFS(g, 1);
    int n = g.size();
    int * postOrden = new int[n];
    postOrden = post.devolverPostOrden();
    vertices.clear();
    vertices = g.devolverVertices();
    for(list<int>::iterator it = vertices.begin(); it != vertices.end(); it++)
    {
        list<Arco> adyacentes = g.devolverAdyacentes(*it);
        for(list<Arco>::iterator itA = adyacentes.begin(); itA != adyacentes.end(); itA++)
        {
            if(!hayciclo)
            {
                if(postOrden[itA->devolverAdyacente()] >= postOrden[*it])
                {
                    hayciclo = true;
                }
            }
        }
    }
    vertices.clear();
    return hayciclo;
}

void AlgoritmosVarios::caminosMinimos_Vertice(Grafo & g, int u)
{
    Recorridos bfs;
    bfs.bosque_BFS_unico(g, u);
    bfs.devolverDatos_bfs(distancia, padre);
    vertices.clear();
    vertices = g.devolverVertices();
    for(list<int>::iterator it = vertices.begin(); it != vertices.end(); it++)
    {
        int v = *it;
        cout << "Camino hasta: " << v << endl;
        while(padre[v] != -1)
        {
            cout <<" " << v;
            v = padre[v];
        }

        cout <<endl;
        cout << "Distancia: " << distancia[*it] << endl;
        cout << "------------" << endl;
    }
}

void AlgoritmosVarios::todosLosCaminos(Grafo & g, int origen, int destino)
{
    aux.clear();
    inicializar(g);
    todosLosCaminos_dfs(g, origen, destino);
}

void AlgoritmosVarios::camino_sinPasarPorRojo(Grafo & g, int origen, int destino, list<int> rojo)
{
    aux.clear();
    inicializar(g);
    corte = false;
    camino_sinPasarPorRojo_dfs(g, origen, destino, rojo);
}
