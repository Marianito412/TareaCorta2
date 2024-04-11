#include "EvaluacionExpresiones.h"
#include "../ListaSimple/ListaSimple.h"
#include "../Nodos/NodoOperador.h"
#include "../Nodos/NodoNumero.h"
#include <fstream>
#include <iostream>

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

ArbolBinario* EvaluacionExpresiones::CrearArbolExpresion(ListaSimple* ListaInfijo, int i)
{
    ArbolBinario* ArbolExpresion = new ArbolBinario();
    PilaDinamica* PilaOps = new PilaDinamica();
    PilaDinamica* PilaNums = new PilaDinamica();
    NodoBase* NodoInfijo = ListaInfijo->Primero;
    std::ofstream ArchivoPila;
    ArchivoPila.open(DIRECTORIO+"ArchivoPila"+std::to_string(i)+".txt");
    
    std::ofstream ArchivoComparaciones;
    ArchivoComparaciones.open(DIRECTORIO+"ArchivoComparaciones"+std::to_string(i)+".txt");
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
            ArchivoComparaciones<<MostrarPrioridad(dynamic_cast<NodoOperador*>(Nodo), false) + " - " +MostrarPrioridad(dynamic_cast<NodoOperador*>(PilaOps->Tope), true)+"\n";
            ArchivoPila<<PilaNums->ConseguirString()+"\n";
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

std::string EvaluacionExpresiones::MostrarPrioridad(NodoOperador* Operador, bool EnPila)
{
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
    return StrOp+std::to_string(Operador->GetPrioridad(EnPila));
}

void EvaluacionExpresiones::EvaluarArbolExpresion(ArbolBinario* Arbol)
{
    std::cout<<Arbol->Raiz->EvaluarArbol()<<std::endl;;
}
