#ifndef PREGUNTA_H
#define PREGUNTA_H

#include <string>
using namespace std;

class Pregunta
{
protected:
    // campos definidos como protegidos para que puedan ser accedidos por las clases derivadas y fueron definidos de acuerdo a los requerimientos del enunciado
    int id;
    string enunciado;
    string solucionEsperada;
    int tiempoEstimado;
    string nivelBloom;
    int ultimoAnoUso;
    bool esNivelBloomValido(const string &nivel);

public:
    // constructor y destructor
    Pregunta();
    virtual ~Pregunta();

    // metodos
    virtual void mostrar() = 0;
    virtual void editar();

    string getNivelBloom() const;
    int getTiempoEstimado() const;
    int getUltimoAnoUso() const;
    void setUltimoAnoUso(int ano);
    string getEnunciado() const;
    string getSolucionEsperada() const;

    // Agregar setters
    void setEnunciado(const string &e) { enunciado = e; }
    void setNivelBloom(const string &n) { nivelBloom = n; }
    void setTiempoEstimado(int t) { tiempoEstimado = t; }
    void setSolucionEsperada(const string &s) { solucionEsperada = s; }

    int getId() const;
    void setId(int nuevoId);
};

#endif