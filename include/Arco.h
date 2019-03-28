#ifndef ARCO_H
#define ARCO_H


class Arco
{
private:
    int origen;
    int adyacente;
    int costo;

public:
    Arco();
    ~Arco();
    Arco(int, int, int);
    int devolverOrigen();
    int devolverAdyacente();
    int devolverCosto();
    void agregarCosto(int);
    void agregarAdyacente(int);
    void agregarOrigen(int);
    Arco & operator=(Arco);
    bool operator==(Arco);
    bool operator<(Arco);
};

#endif // ARCO_H
