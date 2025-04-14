#ifndef EXAMEN_H
#define EXAMEN_H

#include "../Preguntas/Pregunta.h"

class Examen
{
private:
    Pregunta **preguntas;
    int cantidadPreguntas;
    int capacidad;
    int anioCreacion;
    string nivelBloomUltimo;
    int id;

    void redimensionar();
    bool nivelBloomPermitido(const string &nuevoNivel) const;

public:
    Examen(int anioCreacion);
    Examen(const Examen &otro);
    ~Examen();

    void agregarPregunta(Pregunta *p);
    int calcularTiempoTotal() const;
    void mostrarExamen() const;
    int getAnioCreacion() const;
    void setAnioCreacion(int anio);
    bool agregarPreguntaManual(Pregunta *p);
    bool eliminarPreguntaPorId(int id);
    void mostrarPreguntasEnExamen() const;
    int getId() const { return id; }
    void setId(int nuevoId) { id = nuevoId; }
};

#endif