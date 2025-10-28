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

    if (h1->dato.prioridad > h2->dato.prioridad)
        swap(h1, h2);

    h1->der = merge(h1->der, h2);
    swap(h1->izq, h1->der);
    return h1;
}



void printHeap(Nodo* heap, int padre){
    if(!heap) return;

    cout << endl << "Valor actual: " << heap->dato;
    cout << ", Padre: " << padre;

    cout << endl << "Hijo Izquierdo: ";
    printHeap(heap->izq, heap->dato);
    cout << endl << "Hijo Derecho: ";
    printHeap(heap->der, heap->dato);
}

int main() {
    Nodo* heap = nullptr;

    heap = insertar(heap, 10);
    heap = insertar(heap, 5);
    heap = insertar(heap, 20);
    heap = insertar(heap, 3);
    heap = insertar(heap, 11);
    heap = insertar(heap, 16);
    heap = insertar(heap, 30);
    heap = insertar(heap, 42);

    cout << endl << endl << "Recorrido Preorden: ";
    printHeap(heap, -1);

    heap = eliminarMin(heap);
    heap = eliminarMin(heap);

    cout << endl << endl << "Recorrido Preorden después de eliminar: ";
    printHeap(heap, -1);

    return 0;
}
