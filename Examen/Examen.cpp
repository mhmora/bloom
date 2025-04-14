#include "../Examen/Examen.h"
#include <iostream>
using namespace std;

Examen::Examen(int anioCreacion)
{
    capacidad = 10;
    cantidadPreguntas = 0;
    preguntas = new Pregunta *[capacidad];
    this->anioCreacion = anioCreacion;
    nivelBloomUltimo = "Recordar";
}

Examen::Examen(const Examen &otro)
{
    capacidad = otro.capacidad;
    cantidadPreguntas = otro.cantidadPreguntas;
    anioCreacion = otro.anioCreacion;
    nivelBloomUltimo = otro.nivelBloomUltimo;

    preguntas = new Pregunta *[capacidad];
    for (int i = 0; i < cantidadPreguntas; ++i)
    {
        preguntas[i] = otro.preguntas[i]; // Solo copiamos los punteros
    }
}

Examen::~Examen()
{
    delete[] preguntas;
}

void Examen::agregarPregunta(Pregunta *p)
{
    if (cantidadPreguntas == capacidad)
    {
        redimensionar();
    }
    // VALIDACION DE LOS NIVELES DE BLOOM
    if (!nivelBloomPermitido(p->getNivelBloom()))
    {
        cout << "❌ No se puede agregar la pregunta '" << p->getEnunciado()
             << "' porque su nivel de Bloom (" << p->getNivelBloom()
             << ") es inferior al nivel anterior (" << nivelBloomUltimo << ").\n";
        return; // No agregamos esta pregunta
    }
    preguntas[cantidadPreguntas++] = p;
    p->setUltimoAnoUso(anioCreacion);
    nivelBloomUltimo = p->getNivelBloom(); // se realiza la actualizacion del nivel bloom
}

void Examen::redimensionar()
{
    int nuevaCapacidad = capacidad * 2;
    Pregunta **nuevoArray = new Pregunta *[nuevaCapacidad];
    for (int i = 0; i < cantidadPreguntas; ++i)
    {
        nuevoArray[i] = preguntas[i];
    }
    delete[] preguntas;
    preguntas = nuevoArray;
    capacidad = nuevaCapacidad;
}

int Examen::calcularTiempoTotal() const
{
    int total = 0;
    for (int i = 0; i < cantidadPreguntas; i++)
    {
        total += preguntas[i]->getTiempoEstimado();
    }
    return total;
}

void Examen::mostrarExamen() const
{
    for (int i = 0; i < cantidadPreguntas; i++)
    {
        preguntas[i]->mostrar();
    }
}

int Examen::getAnioCreacion() const
{
    return anioCreacion;
}

void Examen::setAnioCreacion(int anio)
{
    anioCreacion = anio;
}

bool Examen::nivelBloomPermitido(const string &nuevoNivel) const
{
    const string niveles[] = {"Recordar", "Entender", "Aplicar", "Analizar", "Evaluar", "Crear"};
    int actual = -1, nuevo = -1;
    for (int i = 0; i < 6; ++i)
    {
        if (niveles[i] == nivelBloomUltimo)
            actual = i;
        if (niveles[i] == nuevoNivel)
            nuevo = i;
    }
    return (nuevo >= actual);
}

bool Examen::agregarPreguntaManual(Pregunta *p)
{
    if (!nivelBloomPermitido(p->getNivelBloom()))
    {
        cout << "❌ No se puede agregar la pregunta '" << p->getEnunciado()
             << "' porque su nivel de Bloom (" << p->getNivelBloom()
             << ") es inferior al nivel anterior (" << nivelBloomUltimo << ").\n";
        return false;
    }

    if (cantidadPreguntas == capacidad)
    {
        redimensionar();
    }

    preguntas[cantidadPreguntas++] = p;
    p->setUltimoAnoUso(anioCreacion);
    nivelBloomUltimo = p->getNivelBloom();

    cout << "✅ Pregunta agregada exitosamente.\n";
    return true;
}

bool Examen::eliminarPreguntaPorId(int id)
{
    for (int i = 0; i < cantidadPreguntas; i++)
    {
        if (preguntas[i]->getId() == id)
        {
            // Eliminamos moviendo todas las preguntas 1 lugar hacia atrás
            for (int j = i; j < cantidadPreguntas - 1; j++)
            {
                preguntas[j] = preguntas[j + 1];
            }
            cantidadPreguntas--;
            cout << "✅ Pregunta eliminada exitosamente.\n";
            return true;
        }
    }
    cout << "❌ No se encontró pregunta con ID " << id << ".\n";
    return false;
}

void Examen::mostrarPreguntasEnExamen() const
{
    cout << "\n--- Preguntas en el examen ---\n";
    if (cantidadPreguntas == 0)
    {
        cout << "⚠️ No hay preguntas en el examen.\n";
        return;
    }
    for (int i = 0; i < cantidadPreguntas; i++)
    {
        cout << "[" << preguntas[i]->getId() << "] ";
        preguntas[i]->mostrar();
    }
}