#include "../SistemaEvaluaciones/SistemaEvaluaciones.h"
#include "../PreguntaOpcionMultiple/PreguntaOpcionMultiple.h"
#include "../PreguntaVerdaderoFalso/PreguntaVerdaderoFalso.h"
#include <fstream>
#include <iostream>

using namespace std;

SistemaEvaluaciones::SistemaEvaluaciones()
{
    capacidad = 10;
    cantidadPreguntas = 0;
    contadorIdPreguntas = 1;
    bancoPreguntas = new Pregunta *[capacidad];
}

SistemaEvaluaciones::~SistemaEvaluaciones()
{
    for (int i = 0; i < cantidadPreguntas; i++)
    {
        delete bancoPreguntas[i];
    }
    delete[] bancoPreguntas;
}

void SistemaEvaluaciones::redimensionar()
{
    int nuevaCapacidad = capacidad * 2;
    Pregunta **nuevoArray = new Pregunta *[nuevaCapacidad];
    for (int i = 0; i < cantidadPreguntas; ++i)
    {
        nuevoArray[i] = bancoPreguntas[i];
    }
    delete[] bancoPreguntas;
    bancoPreguntas = nuevoArray;
    capacidad = nuevaCapacidad;
}

void SistemaEvaluaciones::crearPregunta()
{
    int tipo;
    cout << "\nSeleccione tipo de pregunta:\n1. Opción Múltiple\n2. Verdadero/Falso\n> ";
    cin >> tipo;
    cin.ignore();

    Pregunta *nueva = nullptr;

    if (tipo == 1)
    {
        nueva = new PreguntaOpcionMultiple();
    }
    else if (tipo == 2)
    {
        nueva = new PreguntaVerdaderoFalso();
    }
    else
    {
        cout << "Tipo inválido.\n";
        return;
    }

    nueva->setId(contadorIdPreguntas++);

    nueva->editar();

    if (cantidadPreguntas == capacidad)
    {
        redimensionar();
    }
    bancoPreguntas[cantidadPreguntas++] = nueva;
}

void SistemaEvaluaciones::mostrarPreguntas()
{
    cout << "\n--- Banco de Preguntas ---\n";
    if (cantidadPreguntas == 0)
    {
        cout << "⚠️ No hay preguntas registradas.\n";
        return;
    }
    for (int i = 0; i < cantidadPreguntas; i++)
    {
        cout << "\n[ID: " << bancoPreguntas[i]->getId()
             << "] [Último uso: " << (bancoPreguntas[i]->getUltimoAnoUso() == -1 ? "Nunca utilizada" : to_string(bancoPreguntas[i]->getUltimoAnoUso()))
             << "] ";
        bancoPreguntas[i]->mostrar();
    }
}

void SistemaEvaluaciones::consultarPreguntas()
{
    if (cantidadPreguntas == 0)
    {
        cout << "\n⚠️ No existen preguntas para consultar.\n";
        return;
    }

    int subopcion;
    do
    {
        cout << "\n=== CONSULTAR PREGUNTAS ===\n";
        cout << "1. Mostrar todas las preguntas\n";
        cout << "2. Buscar preguntas por nivel Bloom\n";
        cout << "3. Editar pregunta por ID\n";
        cout << "4. Volver al menú principal\n";
        cout << "Ingrese opción: ";
        cin >> subopcion;
        cin.ignore();

        switch (subopcion)
        {
        case 1:
            cout << "\n--- Listado completo de preguntas ---\n";
            for (int i = 0; i < cantidadPreguntas; i++)
            {
                bancoPreguntas[i]->mostrar();
                cout << "Nivel Bloom: " << bancoPreguntas[i]->getNivelBloom() << "\n";
                cout << "Último año de uso: " << bancoPreguntas[i]->getUltimoAnoUso() << "\n\n";
            }
            break;

        case 2:
        {
            string nivel;
            cout << "Ingrese el nivel de Bloom a buscar: ";
            getline(cin, nivel);

            bool encontrado = false;
            for (int i = 0; i < cantidadPreguntas; i++)
            {
                if (bancoPreguntas[i]->getNivelBloom() == nivel)
                {
                    bancoPreguntas[i]->mostrar();
                    cout << "Nivel Bloom: " << bancoPreguntas[i]->getNivelBloom() << "\n";
                    cout << "Último año de uso: " << bancoPreguntas[i]->getUltimoAnoUso() << "\n\n";
                    encontrado = true;
                }
            }

            if (!encontrado)
            {
                cout << "\n⚠️ No se encontraron preguntas para el nivel Bloom ingresado.\n";
            }
            break;
        }

        case 3:
        {
            mostrarPreguntas();
            int id;
            cout << "Ingrese ID de la pregunta a editar: ";
            cin >> id;
            cin.ignore();

            Pregunta *p = buscarPreguntaPorId(id);
            if (p)
            {
                cout << "\nPregunta actual:\n";
                p->mostrar();
                cout << "\nIngrese los nuevos datos:\n";
                p->editar();
                cout << "✅ Pregunta actualizada exitosamente.\n";
            }
            else
            {
                cout << "❌ No se encontró pregunta con ID " << id << ".\n";
            }
            break;
        }

        case 4:
            cout << "Volviendo al menú principal...\n";
            break;

        default:
            cout << "Opción inválida. Intente de nuevo.\n";
            break;
        }
    } while (subopcion != 4);
}

Examen *SistemaEvaluaciones::crearExamen(int anioActual, int cantidadPreguntasDeseadas)
{
    Examen *examen = new Examen(anioActual);
    int preguntasAgregadas = 0;

    for (int i = 0; i < cantidadPreguntas && preguntasAgregadas < cantidadPreguntasDeseadas; i++)
    {
        if (bancoPreguntas[i]->getUltimoAnoUso() != anioActual &&
            bancoPreguntas[i]->getUltimoAnoUso() != anioActual - 1)
        {
            examen->agregarPregunta(bancoPreguntas[i]);
            bancoPreguntas[i]->setUltimoAnoUso(anioActual);
            preguntasAgregadas++;
        }
    }

    if (preguntasAgregadas == 0)
    {
        cout << "\n⚠️ No hay preguntas disponibles para crear el examen bajo las restricciones.\n";
        delete examen;
        return nullptr;
    }
    else
    {
        cout << "\n✅ Examen creado con " << preguntasAgregadas << " preguntas.\n";
        registroExamen.agregarExamen(examen);
        return examen;
    }
}

void SistemaEvaluaciones::poblarPreguntasDesdeArchivo(const string &nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open())
    {
        cout << "⚠️ No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea))
    {
        if (linea.empty())
            continue; // saltar líneas vacías

        size_t pos = 0;
        string token;
        string campos[10]; // máximo 10 campos por pregunta
        int i = 0;

        while ((pos = linea.find('|')) != string::npos)
        {
            campos[i++] = linea.substr(0, pos);
            linea.erase(0, pos + 1);
        }
        campos[i] = linea; // último campo

        if (campos[0] == "MULTIPLE")
        {
            PreguntaOpcionMultiple *nueva = new PreguntaOpcionMultiple();
            nueva->setEnunciado(campos[1]);
            nueva->setNivelBloom(campos[2]);
            nueva->setTiempoEstimado(stoi(campos[3]));
            nueva->setId(contadorIdPreguntas++);

            for (int j = 0; j < 4; j++)
            {
                nueva->setOpcion(j, campos[4 + j]);
            }
            nueva->setIndiceCorrecto(stoi(campos[8]));

            if (cantidadPreguntas == capacidad)
                redimensionar();
            bancoPreguntas[cantidadPreguntas++] = nueva;
        }
        else if (campos[0] == "VF")
        {
            PreguntaVerdaderoFalso *nueva = new PreguntaVerdaderoFalso();
            nueva->setEnunciado(campos[1]);
            nueva->setNivelBloom(campos[2]);
            nueva->setTiempoEstimado(stoi(campos[3]));
            nueva->setRespuestaCorrecta(campos[4] == "true");
            nueva->setId(contadorIdPreguntas++);

            if (cantidadPreguntas == capacidad)
                redimensionar();
            bancoPreguntas[cantidadPreguntas++] = nueva;
        }
    }

    archivo.close();
    cout << "✅ Preguntas cargadas exitosamente desde el archivo.\n";
}

Pregunta *SistemaEvaluaciones::buscarPreguntaPorId(int id) const
{
    for (int i = 0; i < cantidadPreguntas; i++)
    {
        if (bancoPreguntas[i]->getId() == id)
        {
            return bancoPreguntas[i];
        }
    }
    return nullptr;
}

void SistemaEvaluaciones::crearNuevoExamen()
{
    int anio;
    cout << "Ingrese el año actual: ";
    cin >> anio;
    cin.ignore();

    Examen examen(anio);
    int opcion;

    do
    {
        cout << "\n=== Crear Examen ===\n";
        cout << "1. Agregar pregunta por ID\n";
        cout << "2. Mostrar preguntas del examen\n";
        cout << "3. Eliminar pregunta del examen\n";
        cout << "4. Finalizar y guardar examen\n";
        cout << "5. Cancelar creación\n";
        cout << "Ingrese opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
        {
            mostrarPreguntas();
            int id;
            cout << "Ingrese ID de pregunta a agregar: ";
            cin >> id;
            cin.ignore();
            Pregunta *p = buscarPreguntaPorId(id);
            if (p)
            {
                if (p->getUltimoAnoUso() == -1)
                {
                    examen.agregarPreguntaManual(p);
                    p->setUltimoAnoUso(anio);
                }
                else if (p->getUltimoAnoUso() == anio || p->getUltimoAnoUso() == anio - 1)
                {
                    cout << "❌ No puede usar esta pregunta: fue usada en " << p->getUltimoAnoUso()
                         << " (debe esperar al menos 2 años).\n";
                }
                else
                {
                    examen.agregarPreguntaManual(p);
                    p->setUltimoAnoUso(anio);
                }
            }
            else
            {
                cout << "❌ Pregunta no encontrada.\n";
            }
            break;
        }
        case 2:
            examen.mostrarPreguntasEnExamen();
            break;
        case 3:
        {
            int id;
            cout << "Ingrese ID de pregunta a eliminar: ";
            cin >> id;
            cin.ignore();
            examen.eliminarPreguntaPorId(id);
            break;
        }
        case 4:
            cout << "✅ Examen finalizado. Tiempo total: " << examen.calcularTiempoTotal() << " minutos.\n";
            registroExamen.agregarExamen(new Examen(examen)); // Pasamos la dirección del examen existente
            break;
        case 5:
            cout << "⚠️ Cancelando creación del examen.\n";
            break;
        default:
            cout << "❌ Opción inválida.\n";
            break;
        }
    } while (opcion != 4 && opcion != 5);
}

void SistemaEvaluaciones::mostrarExamenesAntiguos()
{
    if (registroExamen.estaVacio())
    {
        cout << "\n⚠️ No hay exámenes registrados.\n";
        return;
    }

    int opcion;
    do
    {
        cout << "\n=== EXÁMENES REGISTRADOS ===\n";
        cout << "1. Mostrar todos los exámenes\n";
        cout << "2. Editar examen por ID\n";
        cout << "3. Volver\n";
        cout << "Ingrese opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            registroExamen.mostrarExamenes();
            break;
        case 2:
        {
            registroExamen.mostrarExamenes();
            int id;
            cout << "Ingrese ID del examen a editar: ";
            cin >> id;
            cin.ignore();
            registroExamen.editarExamen(id);
            break;
        }
        case 3:
            cout << "Volviendo al menú principal...\n";
            break;
        default:
            cout << "❌ Opción inválida.\n";
            break;
        }
    } while (opcion != 3);
}