#include "ListaSimple.h"

#include <iostream>

void ListaSimple::AgregarNodo(NodoBase* Nodo)
{
    if (!Primero)
    {
        Primero = Nodo;
        return;    
    }
    NodoBase* Aux = Primero;
    while (Aux->Siguiente)
    {
        Aux=Aux->Siguiente;
    }
    Aux->Siguiente = Nodo;
}

void ListaSimple::IterarNodos(std::function<void(NodoBase*)> func)
{
    NodoBase* Aux = Primero;
    while (Aux!=nullptr)
    {
        func(Aux);
        Aux=Aux->Siguiente;
    }
}

void ListaSimple::Mostrar()
{
    NodoBase* Aux = Primero;
    while (Aux!=nullptr)
    {
        Aux->Mostrar();
        //std::cout << " -> ";
        Aux=Aux->Siguiente;
    }
    std::cout << "\n";
}
