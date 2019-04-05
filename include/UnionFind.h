#ifndef UNIONFIND_H
#define UNIONFIND_H
#include <list>

using namespace std;

class UnionFind
{
    public:
        UnionFind();
        ~UnionFind();
        UnionFind(list<int>);
        void union_(int, int);
        int find(int);

    private:
        int *id, *sz;
};

#endif // UNIONFIND_H
