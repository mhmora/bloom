#include "../PreguntaVerdaderoFalso/PreguntaVerdaderoFalso.h"
#include <iostream>
using namespace std;

PreguntaVerdaderoFalso::PreguntaVerdaderoFalso() {}

PreguntaVerdaderoFalso::~PreguntaVerdaderoFalso() {}

void PreguntaVerdaderoFalso::mostrar()
{
    cout << "\n[" << id << "] [Verdadero / Falso] " << enunciado << "\n";
    cout << "  Responder: Verdadero o Falso\n";
    cout << "\nSolución esperada: " << (respuestaCorrecta ? "Verdadero" : "Falso");
    cout << "\nNivel de Bloom: " << nivelBloom;
    cout << "\nTiempo estimado: " << tiempoEstimado << " minutos";
    cout << "\nÚltimo año de uso: " << ultimoAnoUso << "\n";
}

void PreguntaVerdaderoFalso::editar()
{
    Pregunta::editar();
    cout << "\n=== Respuesta Correcta ===\n";
    cout << "¿La respuesta es Verdadero? (1: Sí, 0: No): ";
    cin >> respuestaCorrecta;
    cin.ignore();
    solucionEsperada = respuestaCorrecta ? "Verdadero" : "Falso";
}

void PreguntaVerdaderoFalso::setRespuestaCorrecta(bool respuesta)
{
    respuestaCorrecta = respuesta;
}