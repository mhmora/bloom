#ifndef REGISTROEXAMEN_H
#define REGISTROEXAMEN_H

#include "../Examen/Examen.h"

class RegistroExamen
{
private:
    Examen **examenes;
    int cantidadExamenes;
    int capacidad;
    int contadorIdExamenes;

    void redimensionar();

public:
    RegistroExamen();
    ~RegistroExamen();

    void agregarExamen(Examen *examen);
    void mostrarExamenes() const;
    bool estaVacio() const { return cantidadExamenes == 0; }
    Examen *buscarExamenPorId(int id) const;
    void editarExamen(int id);
};

#endif