#include <iostream>
#include "Grafo.h"
#include "Recorridos.h"
#include "AlgoritmosVarios.h"
#include "ConjuntoArcos.h"
#include "Kruskal.h"
#include "Floyd.h"
#include "Dijkstra.h"

using namespace std;

int main()
{
    list<int> v;
    v.push_front(1);
    v.push_front(2);
    v.push_front(3);
    v.push_front(4);
    v.push_front(5);


    Grafo grafo(v);
    grafo.agregarArco(1,2,3);
    grafo.agregarArco(1,3,10);
    grafo.agregarArco(3,4,5);
    grafo.agregarArco(2,5,1);
    grafo.agregarArco(4,5,10);
    grafo.agregarArco(5,3,2);


    grafo.agregarArco(2,1,3);
    grafo.agregarArco(3,1,10);
    grafo.agregarArco(4,3,5);
    grafo.agregarArco(5,2,1);
    grafo.agregarArco(5,4,10);
    grafo.agregarArco(5,3,2);



    grafo.mostrarGrafo();

    cout << "------------------------" << endl;

}
