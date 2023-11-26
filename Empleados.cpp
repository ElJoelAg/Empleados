#include <iostream>
#include <string>

/* Esta estructura funciona a modo de nodo */
struct Empleado {
    std::string nombre;
    std::string apellidos;
    int edad;
    int antiguedad;
    Empleado* next;
    Empleado* prev;
    Empleado() : next(nullptr), prev(nullptr) {}
};

// Función para obtener el último nodo de la lista
Empleado* getEnd(Empleado* head) {
    while (head != nullptr && head->next != nullptr) {
        head = head->next;
    }
    return head;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Función para dividir la lista enlazada en dos partes y devolver el nodo medio
Empleado* partition(Empleado* low, Empleado* high) {
    int pivot = high->antiguedad;
    Empleado* i = low->prev;

    for (Empleado* j = low; j != high; j = j->next) {
        if (j->antiguedad < pivot) {
            i = (i == nullptr) ? low : i->next;
            swap(i->antiguedad, j->antiguedad);
        }
    }

    i = (i == nullptr) ? low : i->next;
    swap(i->antiguedad, high->antiguedad);
    return i;
}

// Función principal para implementar Quicksort en una lista enlazada
void quickSort(Empleado* start, Empleado* end) {
    if (start && end && start != end && start != end->next) {
        Empleado* pivot = partition(start, end);
        quickSort(start, pivot->prev);
        quickSort(pivot->next, end);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

class ListaEmpleados {
public:
    Empleado* inicio;
    ListaEmpleados() : inicio(nullptr) {}

    void agregarEmpleado() {
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

    void mostrarEmpleados() const {
        Empleado* actual = inicio;

        std::cout << "Lista de empleados:\n";

        while (actual) {
            std::cout << "Nombre: " << actual->nombre << " " << actual->apellidos << "\n";
            std::cout << "Edad: " << actual->edad << " años\n";
            std::cout << "Tiempo en la empresa: " << actual->antiguedad << " meses\n\n";
            actual = actual->next;
        }
    }

    ~ListaEmpleados() {
        // Liberar la memoria al finalizar el programa
        while (inicio) {
            Empleado* temp = inicio;
            inicio = inicio->next;
            delete temp;
        }
    }
};

void mostrarMenu(ListaEmpleados& lista) {
    char opcion;
    do {
        std::cout << "---------- Menu ----------\n";
        std::cout << "1. Agregar un nuevo empleado\n";
        std::cout << "2. Consultar la lista de empleados\n";
        std::cout << "3. Salir\n";
        std::cout << "Ingrese la opción deseada (1-3): ";
        std::cin >> opcion;
        std::cin.ignore(); // Limpiar el buffer de entrada

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

int main() {
    ListaEmpleados lista;

    mostrarMenu(lista);

    return 0;
}  