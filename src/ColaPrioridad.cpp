#include "ColaPrioridad.h"

ColaPrioridad::ColaPrioridad(Grafo & g)
{
    agregarTodo(g);
}

ColaPrioridad::~ColaPrioridad()
{
    //dtor
}

bool ColaPrioridad::empty()
{
    return aristas.empty();
}

Arco ColaPrioridad::front()
{
    return aristas.front();
}

void ColaPrioridad::pop_front()
{
    aristas.pop_front();
}
