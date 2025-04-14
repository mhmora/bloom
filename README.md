# Definiciones

- **Pregunta**: Es una clase abstracta que representa una pregunta. Tiene como parámetros el enunciado, el nivel de Bloom, el tiempo estimado, el último año de aplicación y la respuesta correcta.
- **PreguntaOpcionMultiple**: Es una clase que hereda de Pregunta y representa una pregunta de opción múltiple. Tiene como parámetros el enunciado, el nivel de Bloom, el tiempo estimado, las opciones y la respuesta correcta.
- **PreguntaVerdaderoFalso**: Es una clase que hereda de Pregunta y representa una pregunta de verdadero o falso. Tiene como parámetros el enunciado, el nivel de Bloom, el tiempo estimado y la respuesta correcta.
- **SistemaEvaluaciones**: Es una clase que representa el sistema de evaluaciones. Tiene como parámetros el nombre del archivo de preguntas y el nombre del archivo de exámenes.
- **Examen**: Es una clase que representa un examen. Tiene como parámetros el nombre del examen, el número de preguntas, el número de preguntas de opción múltiple, el número de preguntas de verdadero o falso y el número de preguntas de desarrollo.
- **RegistroExamen**: Es una clase que representa el registro de un examen. Tiene como parámetros el nombre del examen, el número de preguntas, el número de preguntas de opción múltiple, el número de preguntas de verdadero o falso y el número de preguntas de desarrollo.

- **preguntas.txt**: Es un archivo de texto que contiene las preguntas del sistema. Cada línea representa una pregunta y tiene el siguiente formato:
  - **MULTIPLE**: Indica que la pregunta es de opción múltiple.
  - **VF**: Indica que la pregunta es de verdadero o falso.
  - **Recordar**: Indica el nivel de Bloom de la pregunta.
  - **Entender**: Indica el nivel de Bloom de la pregunta.
  - **Aplicar**: Indica el nivel de Bloom de la pregunta.
  - **Analizar**: Indica el nivel de Bloom de la pregunta.
  - **Evaluar**: Indica el nivel de Bloom de la pregunta.
  - **Crear**: Indica el nivel de Bloom de la pregunta.
  - **Tiempo**: Indica el tiempo estimado de la pregunta.
