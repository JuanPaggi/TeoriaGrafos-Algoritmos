#include "Grafo.h"

Grafo::Grafo()
{
    //ctor
}

Grafo::~Grafo()
{
    //dtor
}

Grafo::Grafo(list<int> vertices)
{
    for(list<int>::iterator it = vertices.begin(); it != vertices.end(); it++)
    {
        this -> agregarVertice(*it);
    }
}

Grafo & Grafo::operator = (const Grafo & otroGrafo)
{
    list<int> vertices = otroGrafo.devolverVertices();
    for(list<int>::iterator it = vertices.begin(); it != vertices.end(); it++)
    {
        agregarVertice(*it);
        list<Arco> adyacentes = otroGrafo.devolverAdyacentes(*it);
        for(list<Arco>::iterator itA = adyacentes.begin(); itA != adyacentes.end(); itA++)
        {
            agregarArco(*it, itA->devolverAdyacente(), itA-> devolverCosto());
        }
    }
    return *this;
}

void Grafo::agregarVertice(int vertice)
{
    if(!existeVertice(vertice))
    {
        map<int, int> adyacentes;
        grafo[vertice]= adyacentes;
    }
}

void Grafo::agregarArco(int origen, int destino, int costo)
{
    if(existeVertice(origen) && existeVertice(destino))
    {
        grafo.find(origen)->second[destino] = costo;
    }
}

void Grafo::borrarVertice(int vertice)
{
    grafo.erase(vertice);
    for(map<int, map<int, int> >::iterator it = grafo.begin(); it != grafo.end(); it++)
    {
        it->second.erase(vertice);
    }
}

void Grafo::borrarArco(int origen, int destino)
{
    map<int, map<int, int> >::iterator it = grafo.find(origen);
    if(it != grafo.end())
    {
        it->second.erase(destino);
    }
}

bool Grafo::existeVertice(int vertice) const
{
    return (grafo.find(vertice) != grafo.end());
}

bool Grafo::existeArco(int origen, int destino) const
{
    map<int, map<int, int> >::const_iterator it = grafo.find(origen);
    return ((it != grafo.end()) && (it->second.find(destino) != it->second.end()));
}

list<int> Grafo::devolverVertices() const
{
    list<int> vertices;
    for(map<int, map <int,int> >::const_iterator it = grafo.begin(); it != grafo.end(); it++)
    {
        vertices.push_back(it->first);
    }
    return vertices;
}

list<typename Grafo::Arco> Grafo::devolverAdyacentes(int origen) const
{
    list<Arco> adyacentes;
    map<int, map<int, int> >::const_iterator it = grafo.find(origen);
    if(it != grafo.end())
    {
        for(map<int, int>::const_iterator itA = it->second.begin(); itA != it->second.end(); itA++)
        {
            adyacentes.push_back(Arco(itA->first,itA->second));
        }
    }
    return adyacentes;
}

list<typename Grafo::Arco> Grafo::devolverAristas() const
{
    list<Arco> aristas;
    for(map<int, map<int, int> >::const_iterator it = grafo.begin(); it != grafo.end(); it++)
    {
        for(map<int, int>::const_iterator itA = it->second.begin(); itA != it->second.end(); itA++)
        {
            aristas.push_back(Arco(itA->first, itA->second));
        }
    }
    return aristas;
}

void Grafo::clear()
{
    grafo.clear();
}

bool Grafo::empty() const
{
    return grafo.size();
}

int Grafo::size() const
{
    return grafo.size();
}

bool Grafo::existeCamino(int origen, int destino)
{
    set<int> visitados;
    return existeCamino(origen, destino, visitados);
}

void Grafo::mostrarGrafo()
{
    list<int> vertices = devolverVertices();
    for(list<int>::iterator it = vertices.begin(); it != vertices.end(); it++)
    {
        cout << *it << "->";
        list<typename Grafo::Arco > adyacentes = devolverAdyacentes(*it);
        for(list<typename Grafo::Arco>::iterator itA = adyacentes.begin(); itA != adyacentes.end(); itA++)
        {
            cout << itA->devolverAdyacente() << " " ;
        }
        cout << endl;
    }
}
