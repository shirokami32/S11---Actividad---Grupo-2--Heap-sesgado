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


