#pragma once
#include "../Nodos/NodoBase.h"

class ArbolBinario
{
public:
    NodoBase* Raiz;

    void InsertarNodo(NodoBase* NuevaRaiz, NodoBase* NuevoNodo, bool EsIzquierda);

    void Insertar(NodoBase* Nodo, bool EsIzquierda);
};
