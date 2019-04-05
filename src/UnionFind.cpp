#include "UnionFind.h"

UnionFind::UnionFind()
{
    //ctor
}

UnionFind::~UnionFind()
{
    //dtor
}

UnionFind::UnionFind(list<int> vertices)
{
    int n = vertices.size();
    id = new int[n];
    sz = new int[n];
    for (list<int>::iterator it = vertices.begin(); it != vertices.end(); it++)
    {
        int v = *it;
        id[v] = v;
        sz[v] = 1;
    }
}

void UnionFind::union_(int i, int j)
{
    if(sz[i] < sz[j])
    {
        id[i] = j;
        sz[j] += sz[i];
    }
    else
    {
        id[j] = i;
        sz[i] += sz[j];
    }
}

int UnionFind::find(int i)
{
    while(i != id[i])
    {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

