#include "NodoNumero.h"

#include <iostream>

float NodoNumero::EvaluarArbol()
{
    return Valor;
    return NodoBase::EvaluarArbol();
}

void NodoNumero::Mostrar()
{
    std::cout<<Valor;
}
