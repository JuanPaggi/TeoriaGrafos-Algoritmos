#ifndef COLAPRIORIDAD_H
#define COLAPRIORIDAD_H

#include "Grafo.h"

class ColaPrioridad
{
    public:
        ColaPrioridad(Grafo &);
        ~ColaPrioridad();
        bool empty();
        Arco front();
        void pop_front();

    private:
        list<Arco> aristas;

        list<Arco>::iterator find(Arco a)
        {
            for (list<Arco>::iterator it = aristas.begin(); it != aristas.end(); it++)
                if (a < *it)
                    return it;
            return aristas.end();
        }

        void agregarTodo(Grafo & g)
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
                    aristas.insert(find(a), a);
                }
            }
        }
};

#endif // COLAPRIORIDAD_H
