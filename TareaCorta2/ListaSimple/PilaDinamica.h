#pragma once


#include "ListaSimple.h"

class PilaDinamica : public ListaSimple
{
public:
    NodoBase* Tope = nullptr;
    void AgregarNodo(NodoBase* Nodo) override;
    
    NodoBase* Pop();
};
