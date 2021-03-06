#include "Arco.h"


Arco::Arco()
{
    //ctor
}

Arco::~Arco()
{
    //dtor
}

Arco::Arco(int origen, int adyacente, int costo)
{
    this->origen = origen;
    this->adyacente = adyacente;
    this->costo = costo;
}

int Arco::devolverOrigen()
{
    return origen;
}

int Arco::devolverAdyacente()
{
    return adyacente;
}

int Arco::devolverCosto()
{
    return costo;
}

void Arco::agregarOrigen(int origen)
{
    this->origen = origen;
}

void Arco::agregarCosto(int costo)
{
    this->costo = costo;
}

void Arco::agregarAdyacente(int adyacente)
{
    this->adyacente = adyacente;
}

Arco &  Arco::operator=(Arco a)
{
    adyacente = a.devolverAdyacente();
    costo = a.devolverCosto();
    return *this;
}

bool  Arco::operator==(Arco a)
{
    return this->devolverAdyacente() == a.devolverAdyacente() && this->devolverCosto() == a.devolverCosto();
}

bool  Arco::operator<(Arco a)
{
    return this->devolverCosto() < a.devolverCosto();
}
