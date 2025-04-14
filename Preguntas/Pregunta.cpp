#include "../Preguntas/Pregunta.h"
#include <iostream>

using namespace std;

// constructor
Pregunta::Pregunta() : ultimoAnoUso(-1) {} // -1 indica que nunca se ha usado

// destructor
Pregunta::~Pregunta() {}

// metodos
string Pregunta::getNivelBloom() const
{
    return nivelBloom;
}

int Pregunta::getTiempoEstimado() const
{
    return tiempoEstimado;
}

int Pregunta::getUltimoAnoUso() const
{
    return ultimoAnoUso;
}

void Pregunta::setUltimoAnoUso(int ano)
{
    ultimoAnoUso = ano;
}

void Pregunta::mostrar()
{
    cout << "Enunciado: " << enunciado << endl;
    cout << "Solucion Esperada: " << solucionEsperada << endl;
    cout << "Tiempo Estimado: " << tiempoEstimado << endl;
    cout << "Nivel Bloom: " << nivelBloom << endl;
    cout << "\nÚltimo año de uso: " << (ultimoAnoUso == -1 ? "Nunca utilizada" : to_string(ultimoAnoUso)) << "\n";
}

bool Pregunta::esNivelBloomValido(const string &nivel)
{
    const string nivelesValidos[] = {"Recordar", "Entender", "Aplicar", "Analizar", "Evaluar", "Crear"};
    for (const string &nivelValido : nivelesValidos)
    {
        if (nivel == nivelValido)
            return true;
    }
    return false;
}

void Pregunta::editar()
{
    cout << "\n=== Ingreso de Pregunta ===\n";
    cout << "Ingrese el enunciado: ";
    getline(cin, enunciado);

    cout << "Ingrese el tiempo estimado (en minutos): ";
    cin >> tiempoEstimado;
    cin.ignore();

    do
    {
        cout << "Ingrese el nivel de Bloom (Recordar/Entender/Aplicar/Analizar/Evaluar/Crear): ";
        getline(cin, nivelBloom);
        if (!esNivelBloomValido(nivelBloom))
            cout << "❌ Nivel de Bloom inválido. Por favor, ingrese uno de los valores permitidos.\n";
    } while (!esNivelBloomValido(nivelBloom));

    cout << "Ingrese el año de último uso: ";
    cin >> ultimoAnoUso;
    cin.ignore();
}

string Pregunta::getEnunciado() const
{
    return enunciado;
}

string Pregunta::getSolucionEsperada() const
{
    return solucionEsperada;
}

int Pregunta::getId() const { return id; }
void Pregunta::setId(int nuevoId) { id = nuevoId; }