#include <iostream>
#include "Grafo.h"
#include "Recorridos.h"
#include "AlgoritmosVarios.h"
#include "ArbolRecubrimiento.h"

using namespace std;

int main()
{
    list<int> v;
    v.push_front(1);
    v.push_front(2);
    v.push_front(3);
    v.push_front(4);
    v.push_front(5);
    v.push_front(6);


    Grafo grafo(v);
    grafo.agregarArco(1,2,3);
    grafo.agregarArco(1,5,10);
    grafo.agregarArco(2,3,5);
    grafo.agregarArco(2,5,1);
    grafo.agregarArco(3,6,10);
    grafo.agregarArco(3,4,2);
    grafo.agregarArco(5,6,20);
    grafo.agregarArco(5,4,8);
    grafo.agregarArco(6,4,4);

    grafo.agregarArco(2,1,3);
    grafo.agregarArco(5,1,10);
    grafo.agregarArco(3,2,5);
    grafo.agregarArco(5,2,1);
    grafo.agregarArco(6,3,10);
    grafo.agregarArco(4,3,2);
    grafo.agregarArco(6,5,20);
    grafo.agregarArco(4,5,8);
    grafo.agregarArco(4,6,4);



    grafo.mostrarGrafo();

    cout << "------------------------" << endl;


    ArbolRecubrimiento arbol(grafo);

    arbol.mostrarCosto();

    cout << "------------------------" << endl;

    arbol.prim();
    arbol.mostrarDatos();
}
