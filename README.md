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



