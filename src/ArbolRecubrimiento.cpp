#include "ArbolRecubrimiento.h"

ArbolRecubrimiento::ArbolRecubrimiento(Grafo & g)
{
    n = g.size();
    costo = new int*[n+1];
    for (int i = 1; i <= n; i++)
    {
        costo[i] = new int[n+1];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            costo[i][j] = INT_MAX;
        }
    }

    vertices = g.devolverVertices();
    for(list<int>::iterator it = vertices.begin(); it != vertices.end(); it++)
    {
        list<Arco> adyacentes = g.devolverAdyacentes(*it);
        for(list<Arco>::iterator itA = adyacentes.begin(); itA != adyacentes.end(); itA++)
        {
           costo[*it][itA->devolverAdyacente()] = itA->devolverCosto();
        }
    }
}

ArbolRecubrimiento::~ArbolRecubrimiento()
{
    for (int i = 0; i <= n; i++) {
        delete [] costo[i];
    }
    delete [] costo;
}

void ArbolRecubrimiento::mostrarCosto()
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(costo[i][j] == INT_MAX)
            {
                cout << "I" << " ";
            }
            else
            {
                cout << costo[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void ArbolRecubrimiento::prim()
{
    menor_costo = new int[n+1];
    mas_cercano = new int[n+1];
    solucion = new int[n+1];
    solucion[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        menor_costo[i] = costo[1][i];
        mas_cercano[i] = 1;
        solucion[i] = 0;
    }
    for(int i = 2; i <= n; i++)
    {
        int w = menorCosto();
            solucion[w] = 1;
            for(int j = 2; j <= n; j++)
            {
                if((solucion[j] == 0) && (costo[w][j] < menor_costo[j]))
                {
                    menor_costo[j] = costo[w][j];
                    mas_cercano[j] = w;
                }
            }
    }

    cout << "------------------------" << endl;

    cout << "Menor Costo: " ;
    for(int j = 1; j <= n; j++)
    {
        cout << menor_costo[j] << " ";
    }
    cout << endl;
    cout << "Vertice mas cercano: " ;
    for(int j = 1; j <= n; j++)
    {
        cout << mas_cercano[j] << " ";
    }
    cout << endl;
    cout << "------------------------" << endl;
}
