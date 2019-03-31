#include <iostream>
#include "Grafo.h"
#include "Recorridos.h"
#include "AlgoritmosVarios.h"

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
    grafo.agregarArco(2,1,20);
    grafo.agregarArco(1,3,20);
    grafo.agregarArco(3,5,20);
    grafo.agregarArco(5,6,20);
    grafo.agregarArco(5,4,20);
    grafo.agregarArco(4,2,20);
    grafo.agregarArco(4,3,20);
    grafo.agregarArco(6,1,20);
    grafo.agregarArco(6,3,20);

    grafo.mostrarGrafo();

    cout << "------------------------" << endl;

    AlgoritmosVarios caminos;
    caminos.todosLosCaminos(grafo,5,1);

}
