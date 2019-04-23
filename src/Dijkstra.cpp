#include "Dijkstra.h"

Dijkstra::Dijkstra(Grafo & g)
{
    int n = g.size();
    distancia = new int [n+1];
    padre = new int[n+1];
}

Dijkstra::~Dijkstra()
{
    //dtor
}

void Dijkstra::caminosMinimos(Grafo & g, int u)
{
    list<int> solucion;
    solucion.push_back(u);
    list<int> vertices = g.devolverVertices();
    vertices.erase(find(vertices.begin(), vertices.end(), u));
    distancia[u] = 0;
    padre[u] = -1;
    for (list<int>::iterator it = vertices.begin(); it != vertices.end(); it++)
    {
        int v = *it;
        if (g.existeArco(u, v))
        {
            distancia[v] = g.devolverCosto(u,v);
        }
        else
        {
            distancia[v] = INT_MAX;
        }
        padre[v] = u;
    }

    while (!vertices.empty())
    {
        int w = extraer_min(distancia, vertices);
        solucion.push_back(w);
        vertices.erase(find(vertices.begin(), vertices.end(), w));
        list<Arco> adyacentes = g.devolverAdyacentes(w);
        for (list<Arco>::iterator itV = adyacentes.begin(); itV != adyacentes.end(); itV++)
        {
            int v = itV->devolverAdyacente();
            if (distancia[v] > distancia[w] + g.devolverCosto(w, v))
            {
                distancia[v] = distancia[w] + g.devolverCosto(w, v);
                padre[v] = w;
            }
        }
    }

    int n = g.size();
    cout << "Distancia: ";
    for (int i = 1; i <= n; i++)
    {
        cout << distancia[i] << " ";
    }
    cout << endl;
    cout << "Padre: ";
    for (int i = 1; i <= n; i++)
    {
        cout << padre[i] << " ";
    }
    cout << endl;

}

