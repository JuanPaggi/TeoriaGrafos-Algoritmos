#include <iostream>
#include "Grafo.h"
#include "Recorridos.h"
#include "AlgoritmosVarios.h"
#include "ConjuntoArcos.h"
#include "Kruskal.h"
#include "Floyd.h"
#include "Dijkstra.h"
#include "Prim.h"
#include "GrafoNoOrientado.h"

using namespace std;

int main()
{
    cout << "------------------------" << endl;
    cout << "GRAFO ORIENTADO:" << endl;

    list<int> v;
    v.push_front(1);
    v.push_front(2);
    v.push_front(3);
    v.push_front(4);
    v.push_front(5);
    v.push_front(6);
    v.push_front(7);
    v.push_front(8);
    v.push_front(9);
    v.push_front(10);


    Grafo grafo(v);
    grafo.agregarArco(1,8,14);
    grafo.agregarArco(2,8,20);
    grafo.agregarArco(2,10,5);
    grafo.agregarArco(3,5,12);
    grafo.agregarArco(3,7,10);
    grafo.agregarArco(3,9,5);
    grafo.agregarArco(4,6,10);
    grafo.agregarArco(5,8,10);
    grafo.agregarArco(5,9,13);
    grafo.agregarArco(6,7,8);
    grafo.agregarArco(6,9,20);
    grafo.agregarArco(6,10,2);
    grafo.agregarArco(7,9,7);
    grafo.agregarArco(8,9,5);

    grafo.mostrarGrafo();

    cout << "------------------------" << endl;

    list<int> puertos;
    puertos.push_front(7);
    puertos.push_front(4);
    puertos.push_front(2);

    Dijkstra caminos(grafo);




    cout << "------------------------" << endl;
    cout << "GRAFO NO ORIENTADO:" << endl;

    list<int> v2;
    v2.push_front(1);
    v2.push_front(2);
    v2.push_front(3);

    GrafoNoOrientado grafoN(v2);
    grafoN.agregarArco(1,2,8);
    grafoN.agregarArco(2,3,10);


    grafoN.mostrarGrafo();

    cout << "------------------------" << endl;


}
