#include <iostream>
#include "Grafo.h"
#include "Recorridos.h"
#include "AlgoritmosVarios.h"

using namespace std;

int main()
{
    list<int> v, rojo;
    v.push_front(1);
    v.push_front(2);
    v.push_front(3);
    v.push_front(4);
    v.push_front(5);
    v.push_front(6);
    v.push_front(7);
    v.push_front(8);

    rojo.push_front(2);
    rojo.push_front(5);
    rojo.push_front(6);

    Grafo grafo(v);
    grafo.agregarArco(1,2,20);
    grafo.agregarArco(1,3,20);
    grafo.agregarArco(2,4,20);
    grafo.agregarArco(2,5,20);
    grafo.agregarArco(3,4,20);
    grafo.agregarArco(3,5,20);
    grafo.agregarArco(4,6,20);
    grafo.agregarArco(4,7,20);
    grafo.agregarArco(5,6,20);
    grafo.agregarArco(5,7,20);
    grafo.agregarArco(6,8,20);
    grafo.agregarArco(7,8,20);


    grafo.mostrarGrafo();

    cout << "------------------------" << endl;

    AlgoritmosVarios camino;
    camino.camino_sinPasarPorRojo(grafo,1,8,rojo);

    cout << "------------------------" << endl;

}
