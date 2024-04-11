#include "EvaluacionExpresiones.h"
#include "../ListaSimple/ListaSimple.h"
#include "../Nodos/NodoOperador.h"
#include "../Nodos/NodoNumero.h"
#include <fstream>

#include "../ListaSimple/PilaDinamica.h"

std::string DIRECTORIO = "../Archivos/";

void EvaluacionExpresiones::CargarArchivo(ColaEstatica& ColaArchivos, std::string NombreArchivo)
{
    std::ifstream Archivo;
    ListaSimple* ListaArchivo = new ListaSimple();
    const std::string Directorio = DIRECTORIO+NombreArchivo;
    
    Archivo.open(Directorio);
    for (std::string Linea; getline(Archivo, Linea); ) 
    {
        //std::cout<<Linea<<std::endl;
        //Dios perdonalos, porque no saben lo que hacen
        bool EsOperador = Linea=="+" || Linea=="-" || Linea=="*" || Linea=="/" || Linea=="^" || Linea=="(" || Linea==")";
        
        if (EsOperador)
        {
            ListaArchivo->AgregarNodo(new NodoOperador(Linea));    
        }else
        {
            ListaArchivo->AgregarNodo(new NodoNumero(stof(Linea)));
        }
    }
    ColaArchivos.Insertar(ListaArchivo);
}

bool EvaluacionExpresiones::CompararNodos(NodoOperador* PFP, NodoOperador* PDP)
{
    return PFP->GetPrioridad(false) > PDP->GetPrioridad(true);
}

ArbolBinario* EvaluacionExpresiones::CrearArbolExpresion(ListaSimple* ListaInfijo)
{
    ArbolBinario* ArbolExpresion = new ArbolBinario();
    PilaDinamica* PilaOps = new PilaDinamica();
    PilaDinamica* PilaNums = new PilaDinamica();
    NodoBase* NodoInfijo = ListaInfijo->Primero;
    while (NodoInfijo)
    {
        NodoBase* Nodo = nullptr;
        if (NodoInfijo->TipoNodo == ETipoNodo::Numero)
        {
            Nodo = new NodoNumero(dynamic_cast<NodoNumero*>(NodoInfijo)->Valor);
        }
        else
        {
            Nodo = new NodoOperador(dynamic_cast<NodoOperador*>(NodoInfijo)->Operador);
        }
        Nodo->Mostrar();
        if (Nodo->TipoNodo == ETipoNodo::Numero)
        {
            PilaNums->AgregarNodo(Nodo);
            NodoInfijo = NodoInfijo->Siguiente;
            continue;
        }
        if (PilaOps->ListaVacia() && dynamic_cast<NodoOperador*>(Nodo)->Operador != ETipoOperador::ParentesisCierra)
        {
            PilaOps->AgregarNodo(Nodo);
            NodoInfijo = NodoInfijo->Siguiente;
            continue;
        }
        if (dynamic_cast<NodoOperador*>(Nodo)->Operador == ETipoOperador::ParentesisCierra)
        {
            //Flush
            while (!PilaOps->ListaVacia() && dynamic_cast<NodoOperador*>(PilaOps->Tope)->Operador !=
                ETipoOperador::ParentesisAbre)
            {
                NodoBase* NodoFlush = PilaOps->Pop();
                NodoFlush->Derecha = PilaNums->Pop();
                NodoFlush->Izquierda = PilaNums->Pop();
                PilaNums->AgregarNodo(NodoFlush);
            }
            if (!PilaOps->ListaVacia())
            {
                PilaOps->Pop();
            }
        }
        else
        {
            if (dynamic_cast<NodoOperador*>(Nodo)->GetPrioridad(false) > dynamic_cast<NodoOperador*>(PilaOps->Tope)->
                GetPrioridad(true))
            {
                //Insertar a pila
                PilaOps->AgregarNodo(Nodo);
            }
            else
            {
                //Crear arbol
                NodoBase* NodoNuevo = PilaOps->Pop();
                PilaOps->AgregarNodo(Nodo);
                NodoNuevo->Derecha = PilaNums->Pop();
                NodoNuevo->Izquierda = PilaNums->Pop();
                PilaNums->AgregarNodo(NodoNuevo);
            }
        }
        NodoInfijo = NodoInfijo->Siguiente;
    }
    /*
    std::cout<<"PilaNums"<<std::endl;
    PilaNums->Mostrar();
    std::cout<<"PilaOps"<<std::endl;
    PilaOps->Mostrar();
    */
    if (!PilaOps->ListaVacia())
    {
        NodoBase* Ultimo = PilaOps->Pop();
        Ultimo->Derecha = PilaNums->Pop();
        Ultimo->Izquierda = PilaNums->Pop();
        PilaNums->AgregarNodo(Ultimo);
    }
    ArbolExpresion->Raiz = PilaNums->Pop();
    return ArbolExpresion;
}

void EvaluacionExpresiones::EvaluarArbolExpresion(ArbolBinario* Arbol)
{
    std::cout<<Arbol->Raiz->EvaluarArbol()<<std::endl;;
}
