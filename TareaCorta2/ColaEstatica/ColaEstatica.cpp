#include "ColaEstatica.h"
#include <fstream>
#include <iostream>
using namespace std;

ColaEstatica::ColaEstatica()
{
    Frente = 0;
    Fondo = -1;
    for (auto& i : Cola)
    {
        i = nullptr;        
    }
}

void ColaEstatica::Insertar(ListaSimple* Lista)
{
    if(Fondo <=TAMANO-1){
        Fondo++;
        Cola[Fondo]= Lista;
        //cout<<"ColaEstatica::Insertar Nuevo Fondo:"<<Fondo<<endl;

        CompararPrioridadOperador("comparaciones.txt", dynamic_cast<NodoOperador*>(Lista->Primero));
    }
    else{
        cout<<"La cola esta llena";  
    }
}

void ColaEstatica::Eliminar()
{
    if(!EstaVacia()){
        Frente++;
    }
    else{
        cout<<"La cola esta vacia";  
    }
}

ListaSimple* ColaEstatica::GetElemento(int Pos)
{
    return Cola[Pos];
}

void ColaEstatica::Mostrar()
{
    for (const auto cola : Cola)
    {
        cola->Mostrar();
    }
}

void ColaEstatica::CompararPrioridadOperador(const std::string& nombreArchivo, NodoOperador* nuevoOperador) {
    if (Fondo < Frente) {
        std::cerr << "La cola está vacía." << std::endl;
        return;
    }

    // Abrir el archivo de salida en modo adición
    std::ofstream archivo("comparacionOperadores.txt", std::ios_base::app);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de salida." << std::endl;
        return;
    }

    NodoBase* nodoBase = Cola[Frente];
    NodoOperador* operadorCola = dynamic_cast<NodoOperador*>(nodoBase);

    int prioridadCola = operadorCola->GetPrioridad(true); // Prioridad fuera de la pila
    int prioridadNuevo = nuevoOperador->GetPrioridad(false); // Prioridad dentro de la pila

    // Escribir la comparación en el archivo
    archivo << "Comparación de prioridad entre operador (" << operadorCola->Operador <<"," << prioridadCola << 
                ",) y nuevo operador ("<< operadorCola->Operador << ","<< prioridadNuevo << ")" << std::endl;

    // Cerrar el archivo
    archivo.close();
}
