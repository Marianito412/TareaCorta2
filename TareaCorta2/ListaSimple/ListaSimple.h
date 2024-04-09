#pragma once
#include <functional>

#include "../Nodos/NodoBase.h"

class ListaSimple
{
public:
    NodoBase* Primero = nullptr;
    bool ListaVacia(){return Primero==nullptr;}
    virtual void AgregarNodo(NodoBase* Nodo);
    void IterarNodos(std::function<void(NodoBase*)> func);

    void Mostrar();
};
