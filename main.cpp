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

    Grafo grafo(v);
    grafo.agregarArco(1,2,20);
    grafo.agregarArco(2,3,20);
    grafo.agregarArco(2,4,20);
    grafo.agregarArco(3,4,20);
    grafo.agregarArco(4,5,20);
    grafo.agregarArco(1,5,20);

    grafo.mostrarGrafo();

    cout << "------------------------" << endl;

    Recorridos dfs;
    dfs.bosque_DFS(grafo, 1);
    dfs.mostrarDatos_dfs();

}
