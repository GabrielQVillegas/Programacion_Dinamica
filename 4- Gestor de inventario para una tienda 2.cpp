#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

struct Producto {
    int id;
    string nombre;
    float precio;
    int cantidad;
};

void imprimirInventario(Producto productos[], int tam) {
    cout << "\nInventario:\n";
    for (int i = 0; i < tam; i++) {
        cout << "ID: " << productos[i].id
             << "  Nombre: " << productos[i].nombre
             << "  Precio: " << productos[i].precio
             << "  Cantidad: " << productos[i].cantidad << endl;
    }
}

Producto* buscarPorID(Producto productos[], int tam, int idBuscado) {
    for (int i = 0; i < tam; i++) {
        if (productos[i].id == idBuscado) {
            return &productos[i];
        }
    }
    throw invalid_argument("Error: producto no encontrado por ID.");
}

Producto* buscarPorNombre(Producto productos[], int tam, string nombreBuscado) {
    for (int i = 0; i < tam; i++) {
        if (productos[i].nombre == nombreBuscado) {
            return &productos[i];
        }
    }
    throw invalid_argument("Error: producto no encontrado por nombre.");
}

int main() {
    const int TAM = 10;

    Producto productos[TAM] = {
        {1, "Manzana", 10.5, 30},
        {2, "Naranja", 12.0, 25},
        {3, "Agua", 8.0, 50},
        {4, "Pan", 15.0, 20},
        {5, "Leche", 18.0, 15},
        {6, "Cafe", 55.0, 10},
        {7, "Azucar", 20.0, 18},
        {8, "Sal", 5.0, 40},
        {9, "Queso", 47.0, 12},
        {10, "Mantequilla", 49.0, 16}
    };

    imprimirInventario(productos, TAM);

    try {
        Producto* p = buscarPorID(productos, TAM, 4);
        cout << "\nEncontrado por ID: " << p->nombre << endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    try {
        Producto* p2 = buscarPorNombre(productos, TAM, "Leche");
        cout << "Encontrado por nombre: " << p2->nombre << endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}

