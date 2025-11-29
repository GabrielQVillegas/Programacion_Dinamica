
#include <iostream>
#include <stdexcept>
using namespace std;

struct Cuenta {
    int id;
    double saldo;
};

Cuenta* buscarCuenta(Cuenta *lista, int tam, int id) {
    for (int i = 0; i < tam; i++) {
        if (lista[i].id == id)
            return &lista[i];
    }
    throw invalid_argument("Cuenta no encontrada");
}

void consultarSaldo(Cuenta *c) {
    cout << "Saldo: " << c->saldo << endl;
}

void depositar(Cuenta *c, double m) {
    if (m <= 0) throw invalid_argument("Monto invalido");
    c->saldo += m;
    cout << "Deposito listo.\n";
}

void retirar(Cuenta *c, double m) {
    if (m <= 0) throw invalid_argument("Monto invalido");
    if (m > c->saldo) throw runtime_error("Saldo insuficiente");
    c->saldo -= m;
    cout << "Retiro listo.\n";
}

void transferir(Cuenta *o, Cuenta *d, double m) {
    if (m <= 0) throw invalid_argument("Monto invalido");
    if (m > o->saldo) throw runtime_error("Saldo insuficiente");
    o->saldo -= m;
    d->saldo += m;
    cout << "Transferencia lista.\n";
}

int main() {
    Cuenta cuentas[3] = {
        {1, 1500},
        {2, 3000},
        {3, 500}
    };

    int id;
    cout << "Cuenta (1-3): ";
    cin >> id;

    if (!cin.good()) {
        cout << "Entrada invalida.\n";
        return 0;
    }

    Cuenta *actual;
    try {
        actual = buscarCuenta(cuentas, 3, id);
    } catch (exception &e) {
        cout << e.what() << endl;
        return 0;
    }

    bool salir = false;
    while (!salir) {
        int op;
        cout << "\n1 Consultar\n";
        cout << "2 Depositar\n";
        cout << "3 Retirar\n";
        cout << "4 Transferir\n";
        cout << "5 Salir\n";
        cout << "Opcion: ";
        cin >> op;

        if (!cin.good()) {
            cout << "Entrada invalida.\n";
            break;
        }

        try {
            if (op == 1) {
                consultarSaldo(actual);
            }
            else if (op == 2) {
                double m;
                cout << "Monto: ";
                cin >> m;
                depositar(actual, m);
            }
            else if (op == 3) {
                double m;
                cout << "Monto: ";
                cin >> m;
                retirar(actual, m);
            }
            else if (op == 4) {
                int dest;
                double m;
                cout << "Cuenta destino: ";
                cin >> dest;

                Cuenta *cd = buscarCuenta(cuentas, 3, dest);

                cout << "Monto: ";
                cin >> m;

                transferir(actual, cd, m);
            }
            else if (op == 5) {
                salir = true;
            }
            else {
                cout << "Opcion no valida.\n";
            }
        }
        catch (exception &e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    cout << "Gracias por usar el sistema.\n";
    return 0;
}


