#include "../RegistroExamen/RegistroExamen.h"
#include <iostream>
using namespace std;

RegistroExamen::RegistroExamen()
{
    capacidad = 10;
    cantidadExamenes = 0;
    contadorIdExamenes = 1;
    examenes = new Examen *[capacidad];
}

RegistroExamen::~RegistroExamen()
{
    for (int i = 0; i < cantidadExamenes; i++)
    {
        delete examenes[i];
    }
    delete[] examenes;
}

void RegistroExamen::redimensionar()
{
    int nuevaCapacidad = capacidad * 2;
    Examen **nuevoArray = new Examen *[nuevaCapacidad];
    for (int i = 0; i < cantidadExamenes; i++)
    {
        nuevoArray[i] = examenes[i];
    }
    delete[] examenes;
    examenes = nuevoArray;
    capacidad = nuevaCapacidad;
}

void RegistroExamen::agregarExamen(Examen *examen)
{
    if (cantidadExamenes == capacidad)
    {
        redimensionar();
    }
    examen->setId(contadorIdExamenes++);
    examenes[cantidadExamenes++] = examen;
}

void RegistroExamen::mostrarExamenes() const
{
    if (cantidadExamenes == 0)
    {
        cout << "\n⚠️ No hay exámenes registrados.\n";
        return;
    }

    for (int i = 0; i < cantidadExamenes; i++)
    {
        cout << "\n--- Examen " << (i + 1) << " (Año: " << examenes[i]->getAnioCreacion() << ") ---\n";
        examenes[i]->mostrarExamen();
        cout << "Tiempo total: " << examenes[i]->calcularTiempoTotal() << " minutos\n";
    }
}

Examen *RegistroExamen::buscarExamenPorId(int id) const
{
    for (int i = 0; i < cantidadExamenes; i++)
    {
        if (examenes[i]->getId() == id)
        {
            return examenes[i];
        }
    }
    return nullptr;
}

void RegistroExamen::editarExamen(int id)
{
    Examen *examen = buscarExamenPorId(id);
    if (!examen)
    {
        cout << "❌ No se encontró el examen con ID " << id << ".\n";
        return;
    }

    int opcion;
    do
    {
        cout << "\n=== Editar Examen " << id << " ===\n";
        cout << "1. Agregar pregunta\n";
        cout << "2. Eliminar pregunta\n";
        cout << "3. Mostrar preguntas actuales\n";
        cout << "4. Volver\n";
        cout << "Ingrese opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            cout << "⚠️ Funcionalidad no disponible en esta versión.\n";
            break;
        case 2:
        {
            int idPregunta;
            cout << "Ingrese ID de la pregunta a eliminar: ";
            cin >> idPregunta;
            cin.ignore();
            examen->eliminarPreguntaPorId(idPregunta);
            break;
        }
        case 3:
            examen->mostrarPreguntasEnExamen();
            break;
        case 4:
            cout << "Volviendo...\n";
            break;
        default:
            cout << "❌ Opción inválida.\n";
            break;
        }
    } while (opcion != 4);
}