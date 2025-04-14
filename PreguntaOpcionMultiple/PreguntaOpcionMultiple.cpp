#include "../PreguntaOpcionMultiple/PreguntaOpcionMultiple.h"
#include <iostream>
using namespace std;

PreguntaOpcionMultiple::PreguntaOpcionMultiple()
{
    cantidadOpciones = 4;
    opciones = new string[cantidadOpciones];
}

PreguntaOpcionMultiple::~PreguntaOpcionMultiple()
{
    delete[] opciones;
}

void PreguntaOpcionMultiple::mostrar()
{
    cout << "\n[" << id << "] [Opción Múltiple] " << enunciado << "\n";
    for (int i = 0; i < cantidadOpciones; ++i)
    {
        cout << "  " << (i + 1) << ". " << opciones[i] << "\n";
    }
    cout << "\nSolución esperada: Opción " << indiceCorrecto;
    cout << "\nNivel de Bloom: " << nivelBloom;
    cout << "\nTiempo estimado: " << tiempoEstimado << " minutos";
    cout << "\nÚltimo año de uso: " << ultimoAnoUso << "\n";
}

void PreguntaOpcionMultiple::editar()
{
    Pregunta::editar();
    cout << "\n=== Opciones de Respuesta ===\n";
    setOpciones();
}

void PreguntaOpcionMultiple::setOpciones()
{
    cout << "Ingrese las 4 opciones:\n";
    for (int i = 0; i < cantidadOpciones; i++)
    {
        cout << "\nOpción " << (i + 1) << ": ";
        getline(cin, opciones[i]);
    }

    do
    {
        cout << "\nIndique el número de la respuesta correcta (1-4): ";
        cin >> indiceCorrecto;
        if (indiceCorrecto < 1 || indiceCorrecto > 4)
            cout << "❌ Número inválido. Debe ser entre 1 y 4.\n";
    } while (indiceCorrecto < 1 || indiceCorrecto > 4);

    cin.ignore();
    solucionEsperada = "Opción " + to_string(indiceCorrecto);
}

void PreguntaOpcionMultiple::setOpcion(int index, const string &opcion)
{
    if (index >= 0 && index < cantidadOpciones)
    {
        opciones[index] = opcion;
    }
}

void PreguntaOpcionMultiple::setIndiceCorrecto(int indice)
{
    indiceCorrecto = indice;
}