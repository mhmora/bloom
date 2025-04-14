#ifndef PREGUNTAVERDADEROFALSO_H
#define PREGUNTAVERDADEROFALSO_H

#include "../Preguntas/Pregunta.h"

class PreguntaVerdaderoFalso : public Pregunta
{
private:
    bool respuestaCorrecta;

public:
    PreguntaVerdaderoFalso();
    ~PreguntaVerdaderoFalso() override;

    void mostrar() override;
    void editar() override;

    void setRespuestaCorrecta(bool respuesta);
};

#endif