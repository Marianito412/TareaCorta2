#pragma once
#include "../ColaEstatica/ColaEstatica.h"
#include <string>

#include "../ArbolBinario/ArbolBinario.h"
#include "../Nodos/NodoOperador.h"

class EvaluacionExpresiones
{
public:
    static void CargarArchivo(ColaEstatica& ColaArchivos, std::string NombreArchivo);

    static bool CompararNodos(NodoOperador* PFP, NodoOperador* PDP);
    static ArbolBinario* CrearArbolExpresion(ListaSimple* ListaInfijo);
};
