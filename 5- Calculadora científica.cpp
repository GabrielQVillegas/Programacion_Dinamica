#include <iostream>
#include <stdexcept>

using namespace std;

// Operaciones basicas
double operar(double a, double b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw runtime_error("Division entre cero");
            return a / b;
        default:
            throw invalid_argument("Operacion no valida");
    }
}

int main() {
    double a, b;
    char op;

    cout << "Calculadora - Version parcial\n";
    cout << "Operaciones basicas: + - * /\n\n";

    cout << "Ingresa una operacion (ejemplo: 5 + 3):\n";

    cin >> a >> op >> b;

    try {
        double resultado = operar(a, b, op);
        cout << "Resultado: " << resultado << endl;
    }
    catch (exception &e) {
        cout << "Excepcion: " << e.what() << endl;
    }

    return 0;
}
