#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;

    Nodo(int dx) : dato(dx), izq(nullptr), der(nullptr) {} 
};

Nodo* merge(Nodo* h1, Nodo* h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    if (h1->dato > h2->dato)
        swap(h1, h2);

    h1->der = merge(h1->der, h2);

    swap(h1->izq, h1->der);

    return h1;
}

Nodo* insertar(Nodo* heap, int dx){
    Nodo* nuevoNodo = new Nodo(dx);
    return merge(heap, nuevoNodo);
}

Nodo* eliminarMin(Nodo* head){
    if(!head) return nullptr;
    Nodo *nuevoNodo = merge(head->izq, head->der);
    delete head;
    return nuevoNodo;
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
