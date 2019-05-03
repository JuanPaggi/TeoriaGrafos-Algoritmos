#ifndef GRAFONOORIENTADO_H
#define GRAFONOORIENTADO_H


#include <iostream>
#include <list>
#include <map>
#include <set>
#include "Arco.h"

#define NO_VISITADO -1
#define DESCUBIERTO 0
#define VISITADO 1

using namespace std;

class GrafoNoOrientado
{
public:

    GrafoNoOrientado();
    GrafoNoOrientado(list<int>);
    ~GrafoNoOrientado();
    GrafoNoOrientado & operator = (const GrafoNoOrientado &);
    void agregarVertice(int);
    void agregarArco(int,int,int);
    void borrarVertice(int);
    void borrarArco(int, int);
    bool existeVertice(int) const;
    bool existeArco(int, int) const;
    bool existeCamino(int, int);
    int devolverCosto(int, int);
    list<int> devolverVertices() const;
    list<Arco> devolverAdyacentes(int) const;
    list<Arco> devolverAristas() const;
    void clear();
    bool empty() const;
    int size() const;
    void mostrarGrafo();

private:
    map<int, map<int, int> > grafo;

    bool existeCamino(int origen, int adyacente, set<int> & visitados) const
    {
        if (existeArco(origen, adyacente))
            return true;
        else
        {
            visitados.insert(origen);
            list<Arco> adyacentes = devolverAdyacentes(origen);
            for (list<Arco>::iterator itA = adyacentes.begin(); itA != adyacentes.end(); itA++)
            {
                int u = itA->devolverAdyacente();
                if (visitados.find(u) == visitados.end())
                    return existeCamino(u, adyacente, visitados);
            }
        }
        return false;
    }

};

#endif // GRAFONOORIENTADO_H
