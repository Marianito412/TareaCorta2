#include "ArbolBinario.h"

void ArbolBinario::InsertarNodo(NodoBase* NuevaRaiz, NodoBase* NuevoNodo, bool EsIzquierda)
{
    if (!NuevaRaiz)
    {
        NuevaRaiz = NuevoNodo;
        return;
    }
    if (EsIzquierda)
    {
        
    }

    if (NuevaRaiz->Derecha)
    {
        //InsertarNodo(NuevaRaiz->Izquierda, NuevoNodo, TODO);
    }else
    {
        //InsertarNodo(NuevaRaiz->Izquierda, NuevoNodo, TODO);
    }
}

void ArbolBinario::Insertar(NodoBase* Nodo, bool EsIzquierda)
{
    if (EsIzquierda)
    {
        Raiz->Izquierda = Nodo;
    }
    else
    {
        Raiz->Derecha = Nodo;
    }
}
