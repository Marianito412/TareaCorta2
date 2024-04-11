#pragma once
#include <string>
#include "ColaEstatica/ColaEstatica.h"
#include "EvaluacionExpresiones/EvaluacionExpresiones.h"
using namespace std;

int main()
{
    ColaEstatica ColaArchivos;
    EvaluacionExpresiones::CargarArchivo(ColaArchivos, "Arch1.txt");
    EvaluacionExpresiones::CargarArchivo(ColaArchivos, "Arch2.txt");
    EvaluacionExpresiones::CargarArchivo(ColaArchivos, "Arch3.txt");
    EvaluacionExpresiones::CargarArchivo(ColaArchivos, "Arch4.txt");
    EvaluacionExpresiones::CargarArchivo(ColaArchivos, "Arch5.txt");
    for (int i = 0; i<5;i++)
    {
        cout<<"_________________________"<<endl;
        ArbolBinario* Arbol = EvaluacionExpresiones::CrearArbolExpresion(ColaArchivos.GetElemento(i), i);
        cout<<endl;
        cout<<"Prefijo: ";
        Arbol->RecorrerPrefijo(Arbol->Raiz);
        cout<<endl;
        
        cout<<"Infijo: ";
        Arbol->RecorrerInfijo(Arbol->Raiz);
        cout<<endl;
        
        cout<<"Postfijo: ";
        Arbol->RecorrerPostfijo(Arbol->Raiz);
        cout<<endl;
        EvaluacionExpresiones::EvaluarArbolExpresion(Arbol);    
    }
    
    return 0;
}
