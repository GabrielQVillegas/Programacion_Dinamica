#include <iostream>
using namespace std;

struct Cuenta {
    int id;
    double saldo;
};

void consultarSaldo(Cuenta *cuenta) {
    cout << "Saldo actual: " << cuenta->saldo << endl;
}

int main() {
    Cuenta cuentas[3] = {
        {1, 1500},
        {2, 3000},
        {3, 500}
    };

    int id;
    cout << "Ingrese ID de cuenta (1-3): ";
    cin >> id;

    if (id < 1 || id > 3) {
        cout << "Cuenta invalida.\n";
        return 0;
    }

    Cuenta *actual = &cuentas[id - 1];

    int opcion;
    cout << "1. Consultar saldo\n";
    cout << "2. Salir\n";
    cout << "Seleccione: ";
    cin >> opcion;

    if (opcion == 1)
        consultarSaldo(actual);

    return 0;
}

