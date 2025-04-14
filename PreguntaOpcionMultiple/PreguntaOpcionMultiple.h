#ifndef PREGUNTAOPCIONMULTIPLE_H
#define PREGUNTAOPCIONMULTIPLE_H

#include "../Preguntas/Pregunta.h"
#include <string>

class PreguntaOpcionMultiple : public Pregunta
{
private:
    string *opciones;
    int cantidadOpciones;
    int indiceCorrecto;

public:
    PreguntaOpcionMultiple();
    ~PreguntaOpcionMultiple() override;

    void mostrar() override;
    void editar() override;

    void setOpciones();
    void setOpcion(int index, const string &opcion);
    void setIndiceCorrecto(int indice);
};

#endif