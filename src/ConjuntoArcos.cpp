#include "ConjuntoArcos.h"

ConjuntoArcos::ConjuntoArcos()
{
    //ctor
}

ConjuntoArcos::ConjuntoArcos(Grafo & g)
{
    agregarTodo(g);
}


ConjuntoArcos::~ConjuntoArcos()
{
    //dtor
}

bool ConjuntoArcos::existeArco(Arco a)
{
    return find(a) != aristas.end();
}

void ConjuntoArcos::agregarTodo(Grafo & g)
{
    list<int> vertices = g.devolverVertices();
    for (list<int>::iterator it = vertices.begin(); it != vertices.end(); it++)
    {
        int u = *it;
        list<Arco> adyacentes = g.devolverAdyacentes(u);
        for(list<Arco>::iterator itA = adyacentes.begin(); itA != adyacentes.end(); itA++)
        {
            int v = itA->devolverAdyacente();
            Arco a = Arco(u, v, itA->devolverCosto());
            if (!existeArco(a))
                aristas.push_back(a);
        }
    }
}

void ConjuntoArcos::borrarIncidentes(int u)
{
    for (list<Arco>::iterator itL = aristas.begin(); itL != aristas.end(); )
    {
        list<Arco>::iterator borrar = itL;
        itL++;
        if (borrar->devolverOrigen() == u || borrar->devolverAdyacente() == u)
            aristas.erase(borrar);
    }
}

int ConjuntoArcos::size()
{
    return aristas.size();
}

bool ConjuntoArcos::empty()
{
    return aristas.empty();
}

Arco ConjuntoArcos::front()
{
    return aristas.front();
}


void ConjuntoArcos::agregar(Arco a)
{
    if (!existeArco(a))
        aristas.push_front(a);
}

void ConjuntoArcos::erase(Arco a)
{
    aristas.erase(find(a));
}

Arco ConjuntoArcos::devolver(int i)
{
    assert(0 < i && i <= size());
    int j = 0;
    list<Arco>::iterator it;
    for (it = aristas.begin(); it != aristas.end(); it++)
    {
        j++;
        if (j == i)
            break;
    }
    return *it;
}

ConjuntoArcos & ConjuntoArcos::operator = (ConjuntoArcos c)
{
    int n = c.size();
    for (int i = 1; i <= n; i++)
        agregar(c.devolver(i));
    return *this;
}

void ConjuntoArcos::mostrarConjunto()
{
    for (list<Arco>::iterator it = aristas.begin(); it != aristas.end(); it++)
    {
       cout << "Origen:" << it->devolverOrigen() <<  " Destino:" << it->devolverAdyacente() << " Costo:" << it->devolverCosto() << endl;
    }
}

