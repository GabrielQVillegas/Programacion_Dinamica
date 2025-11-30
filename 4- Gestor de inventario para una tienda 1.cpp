#include <iostream>
#include <string>
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

    return 0;
}

