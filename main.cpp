#include <iostream>
#include "Grafo.h"
#include "Recorridos.h"
#include "AlgoritmosVarios.h"

using namespace std;

int main()
{
    list<int> v;
    v.push_front(0);
    v.push_front(1);
    v.push_front(2);
    v.push_front(3);
    v.push_front(4);

    Grafo grafo(v);
    grafo.agregarArco(0,1,20);
    grafo.agregarArco(0,2,20);
    grafo.agregarArco(1,2,20);
    grafo.agregarArco(2,3,20);
    grafo.agregarArco(4,3,20);

    grafo.mostrarGrafo();

    cout << "------------------------" << endl;

    AlgoritmosVarios top;

    top.bosque_topSort(grafo);

    top.mostrarOrdenamiento();

}
