#include "EvaluacionExpresiones.h"
#include "../ListaSimple/ListaSimple.h"
#include "../Nodos/NodoOperador.h"
#include "../Nodos/NodoNumero.h"
#include <fstream>

#include "../ListaSimple/PilaDinamica.h"

std::string DIRECTORIO = "../Archivos";

void EvaluacionExpresiones::CargarArchivo(ColaEstatica& ColaArchivos, std::string NombreArchivo)
{
    std::ifstream Archivo;
    ListaSimple* ListaArchivo = new ListaSimple();
    const std::string Directorio = DIRECTORIO+NombreArchivo;
    
    Archivo.open(Directorio);
    for (std::string Linea; getline(Archivo, Linea); ) 
    {
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
    return PFP->GetPrioridad(true)> PDP->GetPrioridad(false);
}

ArbolBinario* EvaluacionExpresiones::CrearArbolExpresion(ListaSimple* ListaInfijo)
{
    ArbolBinario* ArbolExpresion = new ArbolBinario();
    PilaDinamica* PilaOps = new PilaDinamica();
    PilaDinamica* PilaNums = new PilaDinamica();
    ListaInfijo->IterarNodos([&PilaNums, &PilaOps, &ArbolExpresion](NodoBase* Nodo)
    {
        if (Nodo->TipoNodo == ETipoNodo::Numero)
        {
            PilaNums->AgregarNodo(Nodo);
        }
        else
        {
            if (PilaOps->ListaVacia())
            {
                PilaOps->AgregarNodo(Nodo);
                return;
            }
            if (dynamic_cast<NodoOperador*>(Nodo)->Operador == ETipoOperador::ParentesisCierra)
            {
                while(true)
                {
                    //Flush
                }
                return;
            }
            else
            {
                if (CompararNodos(dynamic_cast<NodoOperador*>(dynamic_cast<NodoOperador*>(Nodo)),dynamic_cast<NodoOperador*>(PilaOps->Pop())))
                {
                    //Crear arbol
                }else
                {
                    //Insertar a pila
                }
            }
        }
    });
}
