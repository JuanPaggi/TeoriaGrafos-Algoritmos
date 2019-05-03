#include "Floyd.h"

Floyd::Floyd(Grafo & g)
{
    n = g.size();
    A = new int*[n+1];
    C = new int*[n+1];
    for (int i = 1; i <= n; i++)
    {
        A[i] = new int[n+1];
        C[i] = new int[n+1];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i == j)
            {
                C[i][j] = 0;
            }
            else
            {
                C[i][j] = INT_MAX / 2;
            }
            //C[i][j] = 0;
        }
    }
    list<int> vertices = g.devolverVertices();
    for(list<int>::iterator it = vertices.begin(); it != vertices.end(); it++)
    {
        list<Arco> adyacentes = g.devolverAdyacentes(*it);
        for(list<Arco>::iterator itA = adyacentes.begin(); itA != adyacentes.end(); itA++)
        {
            C[*it][itA->devolverAdyacente()] = itA-> devolverCosto();
        }
    }
}

Floyd::~Floyd()
{
    //dtor
}

void Floyd::mostrarMatrizCostos()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(C[i][j] == INT_MAX / 2)
            {
                cout << "I " ;
            }
            else
            {
                cout << C[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void Floyd::caminosMinimos()
{
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
            A[i][j] = C[i][j];
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(A[i][k] + A[k][j] < A[i][j])
                    A[i][j] = A[i][k] + A[k][j];
} // Complejidad O(n^3)

void Floyd::mostrarCaminos()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(A[i][j] == INT_MAX / 2)
            {
                cout << "I " ;
            }
            else
            {
                cout << A[i][j] << " ";
            }
        }
        cout << endl;
    }
}
