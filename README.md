 ## Descripcion y Explicacion del codigo en general
Este código en C++ implementa un sistema simple de gestión de empleados mediante una lista enlazada y utiliza el algoritmo de ordenamiento Quicksort para ordenar los empleados según su antigüedad en la empresa. La aplicación permite al usuario agregar nuevos empleados con información como:
<div align="center">
<img src="Icon(s)/icon.png" width= "10%" C >
</div>

- Nombre.
- Apellidos.
- Edad.
- Antigüedad (en meses).

Además, proporciona la opción de consultar la lista de empleados, la cual estará ordenada por antigüedad al seleccionar la opción correspondiente en el menú.



```cpp
#include <iostream>
#include <string>
struct Empleado {
    std::string nombre;
    std::string apellidos;
    int edad;
    int antiguedad;
    Empleado* next;
    Empleado* prev;
    Empleado() : next(nullptr), prev(nullptr) {}
};

```
Este codigo o estructura funciona a modo de nodos.
- Empleado* next;  // Puntero al siguiente nodo
- Empleado* prev;  // Puntero al nodo anterior

La estructura principal del programa incluye la definición de la clase `Empleado`, que actúa como un nodo en la lista enlazada. Cada empleado tiene campos para almacenar información personal y profesional, así como punteros al siguiente y anterior empleado en la lista. La clase `ListaEmpleados` gestiona la lista enlazada, permitiendo la adición de nuevos empleados y la visualización ordenada de la lista.

```cpp
// Implementación del método para agregar un nuevo empleado a la lista
void ListaEmpleados::agregarEmpleado() {
    Empleado* nuevoEmpleado = new Empleado;

    // Solicitar información al usuario
    std::cout << "Ingrese el nombre del empleado: ";
    std::getline(std::cin, nuevoEmpleado->nombre);

    std::cout << "Ingrese los apellidos del empleado: ";
    std::getline(std::cin, nuevoEmpleado->apellidos);

    std::cout << "Ingrese la edad del empleado: ";
    std::cin >> nuevoEmpleado->edad;

    std::cout << "Ingrese el tiempo en la empresa del empleado (en meses): ";
    std::cin >> nuevoEmpleado->antiguedad;

    nuevoEmpleado->next = inicio;
    inicio = nuevoEmpleado;

    std::cin.ignore(); // Limpiar el buffer de entrada
}
```


De esta manera se programo el menu de opciones que te recive.

```cpp
void mostrarMenu(ListaEmpleados& lista) {
    char opcion;
    do {
        std::cout << "---------- Menu ----------\n";
        std::cout << "1. Agregar un nuevo empleado\n";
        std::cout << "2. Consultar la lista de empleados\n";
        std::cout << "3. Salir\n";
        std::cout << "Ingrese la opción deseada (1-3): ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
            case '1':
                lista.agregarEmpleado();
                break;
            case '2':
                {
                    Empleado* end = getEnd(lista.inicio);
                    quickSort(lista.inicio, end);
                    lista.mostrarEmpleados();
                }
                break;
            case '3':
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opción no válida. Inténtelo de nuevo.\n";
        }
    } while (opcion != '3');
}
```

### Funcionalidad en Python:

1. **Recepción y Procesamiento de Comandos en Telegram:**
   - El script de Python utiliza la biblioteca `python-telegram-bot` para interactuar con Telegram.
   - Maneja comandos específicos como `/agregar` y `/consultar` recibidos de los usuarios en un chat de Telegram.

2. **Gestión de Datos en Memoria:**
   - Mantiene una lista de empleados en memoria usando una estructura de datos adecuada.
   - Responde a comandos como `/agregar` para almacenar información sobre un nuevo empleado.

3. **Ordenamiento de la Lista:**
   - Utiliza el algoritmo Quicksort para ordenar la lista de empleados por antigüedad de mayor a menor.
   - Proporciona la funcionalidad para consultar la lista ordenada.

4. **Interacción con el Script de C++:**
   - Después de procesar un comando como `/agregar`, envía un mensaje al script de C++ con información relevante, como el nuevo empleado añadido.

### Funcionalidad en C++:

1. **Interfaz de Usuario en Consola:**
   - El programa en C++ proporciona una interfaz de usuario en la consola donde los usuarios pueden interactuar a través de un menú.

2. **Comunicación entre C++ y Python:**
   - Se utiliza una conexión mediante sockets para enviar información del script en C++ al script de Python.
   - Después de agregar un nuevo empleado en la interfaz de consola, se envía un mensaje al script de Python con los detalles del empleado.

3. **Gestión Coordinada de la Lista de Empleados:**
   - Ambos scripts mantienen una lista de empleados en memoria, utilizando estructuras de datos adecuadas en sus respectivos lenguajes (Python y C++).
   - El script en C++ puede solicitar la lista de empleados al script de Python, asegurando que ambas instancias estén sincronizadas con la misma información.
   - La información de la lista puede ser ordenada por antigüedad en Python y enviada al script en C++ para su visualización en la interfaz de consola.

### Integración y Flujo de Trabajo:

1. **Agregar un Nuevo Empleado:**
   - El usuario utiliza el comando `/agregar` en Telegram.
   - El script de Python solicita la información del nuevo empleado y la almacena en su lista interna.
   - Después, envía un mensaje al script de C++ para informar sobre el nuevo empleado.
   - El script de C++ recibe el mensaje, actualiza su propia lista de empleados y muestra el último empleado añadido.

2. **Consultar la Lista de Empleados:**
   - El usuario utiliza el comando `/consultar` en Telegram.
   - El script de Python ordena la lista de empleados por antigüedad y responde con la información al usuario.
   - Simultáneamente, el script de C++ solicita la lista ordenada al script de Python y la muestra en la interfaz de consola.

3. **Salida del Programa:**
   - Cuando el usuario elige salir del programa desde la interfaz de consola (C++), se envía un mensaje al script de Python indicando la finalización del programa.

Esta colaboración entre los scripts de Python y C++ permite una gestión eficiente y colaborativa de la lista de empleados, ofreciendo una experiencia interactiva y organizada tanto en Telegram como en la consola.

### Token y Usuario de Telegram
Almacena el token de acceso al bot de Telegram y el nombre de usuario del bot.

```python
token = "..."  # Token de acceso al bot de Telegram
user_name = "..."  # Nombre de usuario del bot
```
### Clase ListaEmpleados
Gestiona una lista de empleados y proporciona métodos para agregar, ordenar y obtener información sobre ellos.

```python
class ListaEmpleados:
    def __init__(self):
        # Inicializa la lista de empleados
        self.empleados = []

    def agregar_empleado(self, nombre, apellidos, numero_empleado, antiguedad):
        # Agrega un nuevo empleado a la lista
        ...

    def obtener_ultimo_empleado_como_string(self):
        # Devuelve una representación en cadena del último empleado agregado
        ...

    def obtener_lista_como_string(self):
        # Devuelve una representación en cadena de todos los empleados
        ...
```

### Funciones Principales de Telegram
Responde a comandos de Telegram y realiza acciones correspondientes.

```python
async def start(update: Update, context: ContextTypes):
    # Responde al comando /start saludando al usuario
    ...

async def agregar(update: Update, context: ContextTypes):
    # Responde al comando /agregar indicando al usuario cómo ingresar información del empleado
    ...

async def procesar_info(update: Update, context: ContextTypes):
    # Procesa la información ingresada por el usuario para agregar un empleado
    ...

async def consultar(update: Update, context: ContextTypes):
    # Responde al comando /consultar mostrando la lista de empleados ordenada por antigüedad
    ...

async def salir(update: Update, context: ContextTypes):
    # Responde al comando /salir despidiendo al usuario
    ...

async def error(update: Update, context: ContextTypes):
    # Maneja comandos no reconocidos enviando un mensaje de error
    ...
```

### Punto de Entrada Principal.
Configura y ejecuta la aplicación de Telegram.

```python
if __name__ == "__main__":
    # Construye la aplicación de Telegram
    ...

    # Agrega manejadores de comandos y mensajes
    ...

    # Manejo de comandos no reconocidos
    ...

    # Ejecuta la aplicación
    ...
```






