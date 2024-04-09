#pragma once
#include <string>
#include "ColaEstatica/ColaEstatica.h"
#include "EvaluacionExpresiones/EvaluacionExpresiones.h"
using namespace std;

int main()
{
    ColaEstatica ColaArchivos;
    EvaluacionExpresiones::CargarArchivo(ColaArchivos, "Archivo1.txt");
    EvaluacionExpresiones::CargarArchivo(ColaArchivos, "Archivo2.txt");
    EvaluacionExpresiones::CargarArchivo(ColaArchivos, "Archivo3.txt");
    EvaluacionExpresiones::CargarArchivo(ColaArchivos, "Archivo4.txt");
    EvaluacionExpresiones::CargarArchivo(ColaArchivos, "Archivo5.txt");
    
    return 0;
}
