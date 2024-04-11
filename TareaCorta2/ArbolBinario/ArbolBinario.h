#pragma once
#include "../Nodos/NodoBase.h"

class ArbolBinario
{
public:
    NodoBase* Raiz;

    void InsertarNodo(NodoBase* NuevaRaiz, NodoBase* NuevoNodo, bool EsIzquierda);

    void Insertar(NodoBase* Nodo, bool EsIzquierda);
    void RecorrerPrefijo(NodoBase* Nodo);
    void RecorrerInfijo(NodoBase* Nodo);
    void RecorrerPostfijo(NodoBase* Nodo);
};
