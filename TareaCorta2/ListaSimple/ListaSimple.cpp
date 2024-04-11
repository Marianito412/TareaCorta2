#include "ListaSimple.h"

#include <iostream>

#include "../Nodos/NodoNumero.h"
#include "../Nodos/NodoOperador.h"

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

std::string ListaSimple::ConseguirString()
{
    std::string Resultado;
    NodoBase* Aux = Primero;
    while (Aux!=nullptr)
    {
        if (Aux->TipoNodo == ETipoNodo::Numero)
        {
            Resultado = Resultado+std::to_string(dynamic_cast<NodoNumero*>(Aux)->Valor)+"->";
        }else
        {
            NodoOperador* Operador = dynamic_cast<NodoOperador*>(Aux);
            std::string StrOp;
            switch (Operador->Operador)
            {
            case ETipoOperador::Suma:
                StrOp = "+";
                break;
            case ETipoOperador::Resta:
                StrOp = "-";
                break;
            case ETipoOperador::Multiplicacion:
                StrOp = "*";
                break;
            case ETipoOperador::Division:
                StrOp = "/";
                break;
            case ETipoOperador::Potencia:
                StrOp = "^";
                break;
            case ETipoOperador::ParentesisAbre:
                StrOp = "(";
                break;
            case ETipoOperador::ParentesisCierra:
                StrOp = ")";
                break;
            }
            Resultado = Resultado+StrOp+"->";
        }
        Aux=Aux->Siguiente;
    }
    return Resultado;
    std::cout << "\n";
}
