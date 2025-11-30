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

// Mostrar todos los productos
void mostrarProductos(Producto* inventario, int tam) {
    cout << "\nInventario actual:\n";
    for (int i = 0; i < tam; i++) {
        cout << "ID: " << inventario[i].id
             << " | Nombre: " << inventario[i].nombre
             << " | Precio: " << inventario[i].precio
             << " | Cantidad: " << inventario[i].cantidad << endl;
    }
}

// Metodo burbuja para ordenar por precio
void ordenarBurbujaPrecio(Producto* inventario, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - 1 - i; j++) {
            if (inventario[j].precio > inventario[j + 1].precio) {
                Producto temp = inventario[j];
                inventario[j] = inventario[j + 1];
                inventario[j + 1] = temp;
            }
        }
    }
}

// Metodo burbuja para ordenar por cantidad
void ordenarBurbujaCantidad(Producto* inventario, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - 1 - i; j++) {
            if (inventario[j].cantidad > inventario[j + 1].cantidad) {
                Producto temp = inventario[j];
                inventario[j] = inventario[j + 1];
                inventario[j + 1] = temp;
            }
        }
    }
}

// Buscar por ID
Producto buscarPorID(Producto* inventario, int tam, int idBuscado) {
    for (int i = 0; i < tam; i++) {
        if (inventario[i].id == idBuscado) {
            return inventario[i];
        }
    }
    throw runtime_error("No se encontro producto con ese ID.");
}

// Buscar por nombre
Producto buscarPorNombre(Producto* inventario, int tam, string nombreBuscado) {
    for (int i = 0; i < tam; i++) {
        if (inventario[i].nombre == nombreBuscado) {
            return inventario[i];
        }
    }
    throw runtime_error("No se encontro producto con ese nombre.");
}

int main() {
    const int TAM = 10;

    Producto inventario[TAM] = {
        {1, "agua", 12.5, 30},
        {2, "leche", 18.0, 20},
        {3, "pan", 5.5, 50},
        {4, "azucar", 27.0, 15},
        {5, "sal", 10.0, 40},
        {6, "cereal", 35.0, 25},
        {7, "huevos", 45.0, 12},
        {8, "jabon", 22.0, 10},
        {9, "arroz", 16.0, 33},
        {10, "aceite", 50.0, 18}
    };

    int opcion;

    do {
        cout << "\nMenu principal:\n";
        cout << "1. Mostrar productos\n";
        cout << "2. Buscar producto por ID\n";
        cout << "3. Buscar producto por nombre\n";
        cout << "4. Ordenar por precio (burbuja)\n";
        cout << "5. Ordenar por cantidad (burbuja)\n";
        cout << "6. Salir\n";
        cout << "Selecciona opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            mostrarProductos(inventario, TAM);
        }

        else if (opcion == 2) {
            int idBuscado;
            cout << "Ingresa ID: ";
            cin >> idBuscado;

            try {
                Producto p = buscarPorID(inventario, TAM, idBuscado);
                cout << "\nProducto encontrado:\n";
                cout << "ID: " << p.id
                     << " Nombre: " << p.nombre
                     << " Precio: " << p.precio
                     << " Cantidad: " << p.cantidad << endl;
            }
            catch (exception& e) {
                cout << e.what() << endl;
            }
        }

        else if (opcion == 3) {
            string nombreBuscado;
            cout << "Ingresa nombre exacto: ";
            cin >> nombreBuscado;

            try {
                Producto p = buscarPorNombre(inventario, TAM, nombreBuscado);
                cout << "\nProducto encontrado:\n";
                cout << "ID: " << p.id
                     << " Nombre: " << p.nombre
                     << " Precio: " << p.precio
                     << " Cantidad: " << p.cantidad << endl;
            }
            catch (exception& e) {
                cout << e.what() << endl;
            }
        }

        else if (opcion == 4) {
            ordenarBurbujaPrecio(inventario, TAM);
            cout << "\nInventario ordenado por precio.\n";
        }

        else if (opcion == 5) {
            ordenarBurbujaCantidad(inventario, TAM);
            cout << "\nInventario ordenado por cantidad.\n";
        }

        else if (opcion != 6) {
            cout << "Opcion no valida.\n";
        }

    } while (opcion != 6);

    return 0;
}

