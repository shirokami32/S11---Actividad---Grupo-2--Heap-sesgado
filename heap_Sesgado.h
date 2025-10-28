#include <iostream>
#include <string>
using namespace std;


struct Incidente {
    int prioridad;
    string descripcion;
    string ubicacion;

    Incidente(int p, string d, string u)
        : prioridad(p), descripcion(d), ubicacion(u) {}
};

struct Nodo {
    Incidente* incidente;
    Nodo* izq;
    Nodo* der;

    Nodo(Incidente* i)
        : incidente(i), izq(nullptr), der(nullptr) {}
};

Nodo* merge(Nodo* h1, Nodo* h2);

Nodo* insertar(Nodo* heap, Incidente incidente) {
    Nodo* nuevo = new Nodo(incidente);
    return merge(heap, nuevo);
}

Nodo* eliminarMin(Nodo* heap){
    if (!heap) {
        cout << "\nNo hay incidentes que atender.\n";
        return nullptr;
    }
    
    cout << "\nIncidente atendido:\n";
    cout << "   Descripcion: " << heap->incidente->descripcion << endl;
    cout << "   Ubicacion: " << heap->incidente->ubicacion << endl;
    cout << "   Prioridad: " << heap->incidente->prioridad << endl;
    
    Nodo *nuevoNodo = merge(head->izq, head->der);
    delete heap->incidente;
    delete heap;
    return nuevoHeap;
}

// Visualizar el incidente más urgente sin eliminarlo
void verMin(Nodo* heap) {
    if (!heap) {
        cout << "\nNo hay incidentes pendientes.\n";
        return;
    }
    cout << "\nIncidente mas urgente:\n";
    cout << "   Descripcion: " << heap->incidente->descripcion << endl;
    cout << "   Ubicacion: " << heap->incidente->ubicacion << endl;
    cout << "   Prioridad: " << heap->incidente->prioridad << endl;
}

Nodo* merge(Nodo* h1, Nodo* h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    if (h1->incidente->prioridad > h2->incidente->prioridad)
        swap(h1, h2);

    h1->der = merge(h1->der, h2);
    swap(h1->izq, h1->der);

    return h1;
}

void printHeap(Nodo* heap, int nivel = 0, string lado = "Raiz") {
    if (!heap) return;

    for (int i = 0; i < nivel; i++)
        cout << "   ";

    cout << "-> [" << lado << "] "
         << "(Prioridad: " << heap->incidente->prioridad << ") "
         << heap->incidente->descripcion
         << " | " << heap->incidente->ubicacion << endl;

    if (heap->izq)
        printHeap(heap->izq, nivel + 1, "Izq");
    if (heap->der)
        printHeap(heap->der, nivel + 1, "Der");
}

void mostrarMenu() {
    cout << "\n===== SISTEMA DE EMERGENCIAS=====\n";
    cout << "1. Insertar nuevo incidente\n";
    cout << "2. Atender incidente mas urgente\n";
    cout << "3. Ver incidente mas urgente\n";
    cout << "4. Fusionar zonas\n";
    cout << "5. Mostrar estructura del heap\n";
    cout << "6. Salir\n";
    cout << "Seleccione una opcion: ";
}

