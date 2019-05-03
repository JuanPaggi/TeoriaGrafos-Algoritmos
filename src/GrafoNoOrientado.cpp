#include "GrafoNoOrientado.h"

GrafoNoOrientado::GrafoNoOrientado()
{
    //ctor
}

GrafoNoOrientado::~GrafoNoOrientado()
{
    //dtor
}

GrafoNoOrientado::GrafoNoOrientado(list<int> vertices)
{
    for(list<int>::iterator it = vertices.begin(); it != vertices.end(); it++)
    {
        this -> agregarVertice(*it);
    }
}

GrafoNoOrientado & GrafoNoOrientado::operator = (const GrafoNoOrientado & otroGrafo)
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

void GrafoNoOrientado::agregarVertice(int vertice)
{
    if(!existeVertice(vertice))
    {
        map<int, int> adyacentes;
        grafo[vertice]= adyacentes;
    }
}

void GrafoNoOrientado::agregarArco(int origen, int destino, int costo)
{
    if(existeVertice(origen) && existeVertice(destino))
    {
        grafo.find(origen)->second[destino] = costo;
        grafo.find(destino)->second[origen] = costo;
    }
}

void GrafoNoOrientado::borrarVertice(int vertice)
{
    grafo.erase(vertice);
    for(map<int, map<int, int> >::iterator it = grafo.begin(); it != grafo.end(); it++)
    {
        it->second.erase(vertice);
    }
}

void GrafoNoOrientado::borrarArco(int origen, int destino)
{
    map<int, map<int, int> >::iterator it = grafo.find(origen);
    if(it != grafo.end())
    {
        it->second.erase(destino);
    }
    it = grafo.find(destino);
    if(it != grafo.end())
    {
        it->second.erase(origen);
    }
}

bool GrafoNoOrientado::existeVertice(int vertice) const
{
    return (grafo.find(vertice) != grafo.end());
}

bool GrafoNoOrientado::existeArco(int origen, int destino) const
{
    map<int, map<int, int> >::const_iterator it = grafo.find(origen);
    return ((it != grafo.end()) && (it->second.find(destino) != it->second.end()));
}

list<int> GrafoNoOrientado::devolverVertices() const
{
    list<int> vertices;
    for(map<int, map <int,int> >::const_iterator it = grafo.begin(); it != grafo.end(); it++)
    {
        vertices.push_back(it->first);
    }
    return vertices;
}

list<Arco> GrafoNoOrientado::devolverAdyacentes(int origen) const
{
    list<Arco> adyacentes;
    map<int, map<int, int> >::const_iterator it = grafo.find(origen);
    if(it != grafo.end())
    {
        for(map<int, int>::const_iterator itA = it->second.begin(); itA != it->second.end(); itA++)
        {
            adyacentes.push_back(Arco(origen, itA->first,itA->second));
        }
    }
    return adyacentes;
}

list<Arco> GrafoNoOrientado::devolverAristas() const
{
    list<Arco> aristas;
    for(map<int, map<int, int> >::const_iterator it = grafo.begin(); it != grafo.end(); it++)
    {
        for(map<int, int>::const_iterator itA = it->second.begin(); itA != it->second.end(); itA++)
        {
            aristas.push_back(Arco(it->first , itA->first, itA->second));
        }
    }
    return aristas;
}

void GrafoNoOrientado::clear()
{
    grafo.clear();
}

bool GrafoNoOrientado::empty() const
{
    return grafo.empty();
}

int GrafoNoOrientado::size() const
{
    return grafo.size();
}

bool GrafoNoOrientado::existeCamino(int origen, int destino)
{
    set<int> visitados;
    return existeCamino(origen, destino, visitados);
}

void GrafoNoOrientado::mostrarGrafo()
{
    list<int> vertices = devolverVertices();
    for(list<int>::iterator it = vertices.begin(); it != vertices.end(); it++)
    {
        cout << *it << "->";
        list<Arco> adyacentes = devolverAdyacentes(*it);
        for(list<Arco>::iterator itA = adyacentes.begin(); itA != adyacentes.end(); itA++)
        {
            cout << itA->devolverAdyacente() << " " ;
        }
        cout << endl;
    }
}

int GrafoNoOrientado::devolverCosto(int u, int v)
{
    map<int, map<int, int> >::iterator it = grafo.find(u);
    map<int, int>::iterator itA = it->second.find(v);
    return itA->second;
}
