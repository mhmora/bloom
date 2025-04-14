#include "SistemaEvaluaciones/SistemaEvaluaciones.h"
#include <iostream>
using namespace std;

int main()
{
    SistemaEvaluaciones sistema;
    int opcion;

    do
    {
        cout << "\n=== SISTEMA DE EVALUACIONES ===\n";
        cout << "1. Crear nueva pregunta\n";
        cout << "2. Consultar preguntas\n";
        cout << "3. Crear nuevo examen\n";
        cout << "4. Consultar exámenes antiguos\n";
        cout << "5. Poblar preguntas desde archivo\n";
        cout << "6. Salir\n";
        cout << "Ingrese opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            sistema.crearPregunta();
            break;
        case 2:
            sistema.consultarPreguntas();
            break;
        case 3:
            sistema.crearNuevoExamen();
            break;
        case 4:
            sistema.mostrarExamenesAntiguos();
            break;
        case 5:
            sistema.poblarPreguntasDesdeArchivo("preguntas.txt");
            break;
        case 6:
            cout << "¡Hasta luego!\n";
            break;
        default:
            cout << "Opción inválida.\n";
            break;
        }
    } while (opcion != 6);

    return 0;
}