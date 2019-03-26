#ifndef GRAFOMAP_H
#define GRAFOMAP_H
#include <iostream>
#include <list>
#include <map>
#include <set>

#define NO_VISITADO -1
#define DESCUBIERTO 0
#define VISITADO 1

using namespace std;

class Grafo
{
public:

    class Arco
    {
    private:
        int adyacente;
        int costo;
    public:
        Arco(int adyacente, int costo)
        {
            this->adyacente = adyacente;
            this->costo = costo;
        }

        int devolverAdyacente() const
        {
            return adyacente;
        }

        int devolverCosto() const
        {
            return costo;
        }
    };

    Grafo();
    Grafo(list<int> vertices);
    ~Grafo();
    Grafo & operator = (const Grafo & otroGrafo);
    void agregarVertice(int vertice);
    void agregarArco(int origen, int destino, int costo);
    void borrarVertice(int vertice);
    void borrarArco(int origen, int destino);
    bool existeVertice(int vertice) const;
    bool existeArco(int origen, int destino) const;
    bool existeCamino(int origen, int destino);
    list<int> devolverVertices() const;
    list<Arco> devolverAdyacentes(int origen) const;
    list<Arco> devolverAristas() const;
    void clear();
    bool empty() const;
    int size() const;
    void mostrarGrafo();

private:
    map<int, map<int, int> > grafo;

    bool existeCamino(int origen, int destino, set<int> & visitados) const
    {
        if (existeArco(origen, destino))
            return true;
        else
        {
            visitados.insert(origen);
            list<Arco> adyacentes = devolverAdyacentes(origen);
            for (list<Arco>::iterator itA = adyacentes.begin(); itA != adyacentes.end(); itA++)
            {
                int u = itA->devolverAdyacente();
                if (visitados.find(u) == visitados.end())
                    return existeCamino(u, destino, visitados);
            }
        }
        return false;
    }

};

#endif // GRAFOMAP_H
