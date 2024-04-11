#pragma once

enum ETipoNodo: int
{
    Numero,
    Operacion
};

class NodoBase
{
public:
    virtual ~NodoBase() = default;
    ETipoNodo TipoNodo = ETipoNodo::Numero;
    NodoBase* Siguiente = nullptr;
    NodoBase* Izquierda = nullptr;
    NodoBase* Derecha = nullptr;

    virtual void Mostrar();
    virtual float EvaluarArbol();
};
