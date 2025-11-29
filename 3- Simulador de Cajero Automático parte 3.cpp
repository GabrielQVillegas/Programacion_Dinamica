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

void transferir(Cuenta *origen, Cuenta *destino, double monto) {
    if (monto <= 0) throw invalid_argument("Monto invalido");
    if (monto > origen->saldo) throw runtime_error("Saldo insuficiente");
    origen->saldo -= monto;
    destino->saldo += monto;
    cout << "Transferencia realizada.\n";
}

int main() {
    Cuenta cuentas[3] = {
        {1, 1500},
        {2, 3000},
        {3, 500}
    };

    Cuenta *lista[3] = { &cuentas[0], &cuentas[1], &cuentas[2] };

    int id;
    cout << "ID de cuenta: ";
    cin >> id;

    if (id < 1 || id > 3) {
        cout << "Cuenta invalida.\n";
        return 0;
    }

    Cuenta *actual = lista[id - 1];

    bool salir = false;
    while (!salir) {
        int op;
        cout << "\n1. Consultar saldo\n";
        cout << "2. Depositar\n";
        cout << "3. Retirar\n";
        cout << "4. Transferir\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cin >> op;

        try {
            switch(op) {
                case 1:
                    consultarSaldo(actual);
                    break;

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

                case 4: {
                    int dest;
                    double m;
                    cout << "Cuenta destino: ";
                    cin >> dest;

                    if (dest < 1 || dest > 3)
                        throw invalid_argument("Cuenta destino invalida");

                    Cuenta *cDestino = lista[dest - 1];

                    cout << "Monto: ";
                    cin >> m;
                    transferir(actual, cDestino, m);
                    break;
                }

                case 5:
                    salir = true;
                    break;

                default:
                    cout << "Opcion invalida.\n";
            }
        }
        catch (exception &e) {
            cout << "Error: " << e.what() << endl;
            continue;
        }
    }

    return 0;
}


