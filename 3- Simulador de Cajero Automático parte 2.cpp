
#include <iostream>
#include <stdexcept>
using namespace std;

struct Cuenta {
    int id;
    double saldo;
};

void consultarSaldo(Cuenta *cuenta) {
    cout << "Saldo actual: " << cuenta->saldo << endl;
}

void depositar(Cuenta *cuenta, double monto) {
    if (monto <= 0) throw invalid_argument("Monto invalido");
    cuenta->saldo += monto;
    cout << "Deposito realizado.\n";
}

void retirar(Cuenta *cuenta, double monto) {
    if (monto <= 0) throw invalid_argument("Monto invalido");
    if (monto > cuenta->saldo) throw runtime_error("Saldo insuficiente");
    cuenta->saldo -= monto;
    cout << "Retiro realizado.\n";
}

int main() {
    Cuenta cuentas[3] = {
        {1, 1500},
        {2, 3000},
        {3, 500}
    };

    int id;
    cout << "ID de cuenta: ";
    cin >> id;

    if (id < 1 || id > 3) {
        cout << "Cuenta invalida.\n";
        return 0;
    }

    Cuenta *actual = &cuentas[id - 1];

    bool salir = false;
    while (!salir) {
        int op;
        cout << "\n1. Consultar saldo\n";
        cout << "2. Depositar\n";
        cout << "3. Retirar\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> op;

        try {
            switch(op) {
                case 1: consultarSaldo(actual); break;
                case 2: {
                    double m;
                    cout << "Monto: ";
                    cin >> m;
                    depositar(actual, m);
                    break;
                }
                case 3: {
                    double m;
                    cout << "Monto: ";
                    cin >> m;
                    retirar(actual, m);
                    break;
                }
                case 4: salir = true; break;
                default: cout << "Opcion invalida.\n";
            }
        } catch (exception &e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}

