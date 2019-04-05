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


    Grafo grafo(v);
    grafo.agregarArco(1,2,3);
    grafo.agregarArco(1,3,10);
    grafo.agregarArco(3,4,5);
    grafo.agregarArco(2,5,1);
    grafo.agregarArco(4,5,10);



    grafo.mostrarGrafo();

    cout << "------------------------" << endl;

    Recorridos bfs;

    bfs.bosque_BFS(grafo, 1);

    bfs.mostrarDatos_bfs();

}
