#ifndef SISTEMAEVALUACIONES_H
#define SISTEMAEVALUACIONES_H

#include "../Preguntas/Pregunta.h"
#include "../Examen/Examen.h"
#include "../RegistroExamen/RegistroExamen.h"
class SistemaEvaluaciones
{
private:
    Pregunta **bancoPreguntas;
    int cantidadPreguntas;
    int capacidad;
    int contadorIdPreguntas;
    RegistroExamen registroExamen;
    void redimensionar();

public:
    SistemaEvaluaciones();
    ~SistemaEvaluaciones();

    void crearPregunta();
    void mostrarPreguntas();
    void consultarPreguntas();
    Examen *crearExamen(int anioActual, int cantidadPreguntasDeseadas);
    void poblarPreguntasDesdeArchivo(const string &nombreArchivo);
    void crearNuevoExamen();
    void mostrarExamenesAntiguos();
    Pregunta *buscarPreguntaPorId(int id) const;
};

#endif