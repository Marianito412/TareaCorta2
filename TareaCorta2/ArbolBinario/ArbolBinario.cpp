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

void ArbolBinario::RecorrerPrefijo(NodoBase* Nodo)
{
    if (!Nodo)
    {
        return;
    }
    Nodo->Mostrar();
    RecorrerPrefijo(Nodo->Izquierda);
    RecorrerPrefijo(Nodo->Derecha);
}

void ArbolBinario::RecorrerInfijo(NodoBase* Nodo)
{
    if (!Nodo)
    {
        return;
    }
    RecorrerInfijo(Nodo->Izquierda);
    Nodo->Mostrar();
    RecorrerInfijo(Nodo->Derecha);
}

void ArbolBinario::RecorrerPostfijo(NodoBase* Nodo)
{
    if (!Nodo)
    {
        return;
    }
    RecorrerPostfijo(Nodo->Izquierda);
    RecorrerPostfijo(Nodo->Derecha);
    Nodo->Mostrar();
}
