/*
Nombre: César Daniel Aguilar Kuri
Matricula: A01712823
Nombre del Proyecto: Steal a Brainrot!
Materia: Programación de estructuras de datos y algoritmos fundamentales
Profesor: Eduardo Daniel Juárez Pineda
*/

#ifndef DLIST_H
#define DLIST_H

#include <string>   // O(1)
#include <iostream> // O(1)

using namespace std; // O(1)

// Lista doblemente ligada para manejar "brainrots favoritos"
template <class T>
class DListFavoritos {
private:
    // Nodo interno de la lista
    struct Node {
        T     data;   // guarda el elemento completo (por ejemplo: Row) // O(1)
        Node* prev;   // O(1)
        Node* next;   // O(1)

        Node(const T& value)        // O(1)
            : data(value),          // O(1)
              prev(NULL),           // O(1)
              next(NULL) {}         // O(1)
    };

    Node* head;    // Inicio de la lista // O(1)
    Node* tail;    // Final de la lista  // O(1)
    Node* current; // Nodo "actual" para navegar favoritos // O(1)

public:
    DListFavoritos() : head(NULL), tail(NULL), current(NULL) { // O(1)
        // Constructor: lista vacía // O(1)
    }

    ~DListFavoritos() { // O(n)
        clear();        // O(n) libera toda la lista nodo por nodo
    }

    bool empty() const {    // O(1)
        return head == NULL; // O(1)
    }

    // Elimina todos los nodos de la lista
    void clear() {      // O(n)
        Node* p = head; // O(1)
        while (p != NULL) {   // O(n)
            Node* nxt = p->next; // O(1)
            delete p;            // O(1)
            p = nxt;             // O(1)
        }
        head    = NULL; // O(1)
        tail    = NULL; // O(1)
        current = NULL; // O(1)
    }

    // Agregar un favorito al FINAL de la lista
    void addFavorite(const T& value) { // O(1)
        Node* nodo = new Node(value);  // O(1)

        if (empty()) {         // O(1)
            head    = nodo;    // O(1)
            tail    = nodo;    // O(1)
            current = head;    // O(1)
        } else {
            nodo->prev = tail; // O(1)
            tail->next = nodo; // O(1)
            tail       = nodo; // O(1)
        }
    }

    // Eliminar un favorito por nombre (primera coincidencia)
    // Recorrido O(n) para encontrarlo
    bool removeFavorite(const string& nombre) { // O(n)
        if (empty()) return false; // O(1)

        Node* p = head;            // O(1)
        while (p != NULL) {        // O(n)
            if (p->data.nombre == nombre) { // comparación de nombre // O(1)
                // Reenlazar prev/next
                if (p->prev != NULL) {           // O(1)
                    p->prev->next = p->next;     // O(1)
                } else {
                    head = p->next;              // O(1) quitamos head
                }

                if (p->next != NULL) {           // O(1)
                    p->next->prev = p->prev;     // O(1)
                } else {
                    tail = p->prev;              // O(1) quitamos tail
                }

                // Si el nodo borrado era el actual, mover current
                if (current == p) {              // O(1)
                    if (p->next != NULL) {       // O(1)
                        current = p->next;       // O(1)
                    } else {
                        current = p->prev;       // O(1)
                    }
                }

                delete p;    // O(1)
                return true; // O(1)
            }
            p = p->next;     // O(1)
        }
        return false; // no se encontró // O(1)
    }

    // Mover "current" al primer favorito
    bool moveToFirst() { // O(1)
        if (empty()) return false; // O(1)
        current = head;            // O(1)
        return true;               // O(1)
    }

    // Mover "current" al último favorito
    bool moveToLast() { // O(1)
        if (empty()) return false; // O(1)
        current = tail;            // O(1)
        return true;               // O(1)
    }

    // Mover "current" al siguiente favorito
    bool moveNext() { // O(1)
        if (current == NULL)        return false; // O(1)
        if (current->next == NULL)  return false; // O(1)
        current = current->next;                 // O(1)
        return true;                             // O(1)
    }

    // Mover "current" al favorito anterior
    bool movePrev() { // O(1)
        if (current == NULL)        return false; // O(1)
        if (current->prev == NULL)  return false; // O(1)
        current = current->prev;                 // O(1)
        return true;                             // O(1)
    }

    // Obtener el elemento completo del favorito actual
    bool getCurrent(T& value) const { // O(1)
        if (current == NULL) return false; // O(1)
        value = current->data;            // O(1)
        return true;                      // O(1)
    }

    // Imprimir favoritos de inicio a fin
    void printForward() const { // O(n)
        if (empty()) {                         // O(1)
            cout << "No hay favoritos.\n";     // O(1)
            return;                            // O(1)
        }
        Node* p = head;                        // O(1)
        int idx = 1;                           // O(1)
        while (p != NULL) {                    // O(n)
            // Se asume que T tiene: nombre, rareza, costo
            cout << idx << ") "                // O(1)
                 << p->data.nombre << " | "    // O(1)
                 << p->data.rareza << " | "    // O(1)
                 << p->data.costo  << "\n";    // O(1)
            p = p->next;                       // O(1)
            idx++;                             // O(1)
        }
    }

    // Imprimir favoritos de fin a inicio (usando la lista doblemente ligada)
    void printBackward() const { // O(n)
        if (empty()) {                         // O(1)
            cout << "No hay favoritos.\n";     // O(1)
            return;                            // O(1)
        }
        Node* p = tail;                        // O(1)
        int idx = 1;                           // O(1)
        while (p != NULL) {                    // O(n)
            cout << idx << ") "                // O(1)
                 << p->data.nombre << " | "    // O(1)
                 << p->data.rareza << " | "    // O(1)
                 << p->data.costo  << "\n";    // O(1)
            p = p->prev;                       // O(1)
            idx++;                             // O(1)
        }
    }
};

#endif // DLIST_H
