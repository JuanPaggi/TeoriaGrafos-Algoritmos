#ifndef CONJUNTOARCOS_H
#define CONJUNTOARCOS_H

#include "Grafo.h"
#include <assert.h>

class ConjuntoArcos
{
    public:
        ConjuntoArcos();
        ConjuntoArcos(Grafo &);
        ~ConjuntoArcos();
        bool existeArco(Arco a);
        void agregarTodo(Grafo &);
        void borrarIncidentes(int);
        int size();
        bool empty();
        Arco front();
        void agregar(Arco);
        void erase(Arco a);
        Arco devolver(int);
        ConjuntoArcos & operator = (ConjuntoArcos);
        void mostrarConjunto();

    private:
        list<Arco> aristas;

        list<Arco>::iterator find(Arco a)
        {
            for (list<Arco>::iterator it = aristas.begin(); it != aristas.end(); it++)
                if (*it == a)
                    return it;
            return aristas.end();
        }
};

#endif // CONJUNTOARCOS_H
