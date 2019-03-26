#include <iostream>
#include "Grafo.h"
#include "Recorridos.h"

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
    grafo.agregarArco(0,2,20);
    grafo.agregarArco(0,3,20);
    grafo.agregarArco(1,0,20);
    grafo.agregarArco(2,1,20);
    grafo.agregarArco(2,3,20);
    grafo.agregarArco(3,4,20);

    grafo.mostrarGrafo();

    cout << "------------------------" << endl;

}
