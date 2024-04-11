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
       ArbolBinario* Arbol = EvaluacionExpresiones::CrearArbolExpresion(ColaArchivos.GetElemento(i));
        
        // Generar el nombre del archivo para cada expresión y evaluación
        std::string nombreArchivo = "Expresion" + std::to_string(i + 1) + ".txt";

        // Llamar a la función para guardar las expresiones y evaluaciones en el archivo correspondiente
        EvaluacionExpresiones::GuardarExpresionesYEvaluciones(Arbol, nombreArchivo);
    }

    return 0;
}
